#include "application.hpp"
#include <spdlog/spdlog.h>
#include <array>
#include <vector>
#include "camera.hpp"
#include "events/event.hpp"
#include "opengl/context.hpp"
#include "opengl/program.hpp"
#include "opengl/renderer.hpp"
#include "opengl/shader.hpp"
#include "opengl/vertex_array.hpp"
#include "opengl/window.hpp"

Application::Application()
    : render_context_{new OpenGLContext()},
      window_{new OpenGLWindow("Title",
                               720,
                               480,
                               std::bind(&Application::on_event, this, std::placeholders::_1))},
      quit_{false} {
    spdlog::debug("Application constructor");
    render_context_->init();
}

Application::~Application() {
    spdlog::debug("Application destructor");
}

void Application::on_event(Event& e) {
    switch (e.type()) {
        case Event::Type::WindowClose:
            quit_ = true;
            break;
        case Event::Type::WindowResize:
            window_->on_event(e);
            break;
        default:
            break;
    }
}

void Application::run() {
    const auto vshader = Shader::from_string(Shader::Type::Vertex, R"(
                        #version 430 core
                        layout (location = 0) uniform mat4 view;
                        layout (location = 0) in vec3 aPos;
                        layout (location = 1) in vec3 aCol;
                        out vec3 bCol;
                        void main() {
                            gl_Position = view*vec4(aPos, 1.0);
                            bCol = aCol;
                        }
                    )");

    const auto fshader = Shader::from_string(Shader::Type::Fragment, R"(
                        #version 430 core
                        in vec3 bCol;
                        out vec4 FragColor;
                        void main() {
                            FragColor = vec4(bCol, 1.0f);
                        }
                    )");

    auto camera = Camera();
    auto matrix = camera.matrix();

    auto program = Program{vshader, fshader};
    program.use();
    program.set_uniform_mat4("view", glm::value_ptr(matrix), false);

    // clang-format off
    const std::vector<float> vertices = {
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
        -0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 1.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
    };
    // clang-format on

    auto vertex_array = OpenGLVertexArray({3, 3});
    vertex_array.buffer(vertices);

    auto renderer = OpenGLRenderer();
    renderer.clear_colour({0.1, 0.1, 0.1, 1.0});

    while (!quit_) {
        render_context_->poll();

        // Render something
        renderer.clear();
        renderer.draw(program, vertex_array);

        window_->swap();
    }
}
