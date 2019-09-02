#include "application.hpp"
#include <spdlog/spdlog.h>
#include <array>
#include <vector>
#include "camera.hpp"
#include "events/event.hpp"
#include "opengl/context.hpp"
#include "opengl/renderer.hpp"
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
    auto camera = Camera();
    auto renderer = OpenGLRenderer();
    renderer.clear_colour({0.1, 0.1, 0.1, 1.0});

    while (!quit_) {
        render_context_->poll();

        // Render something
        renderer.clear();
        renderer.draw_rect(camera, Rect(-1.0, -1.0, 1.0, 1.0), glm::vec4(1.0, 0.0, 0.0, 1.0));
        renderer.draw_rect(camera, Rect(0.0, -1.0, 1.0, 1.0), glm::vec4(0.0, 1.0, 0.0, 1.0));
        renderer.draw_rect(camera, Rect(-1.0, 0.0, 1.0, 1.0), glm::vec4(0.0, 0.0, 1.0, 1.0));
        renderer.draw_rect(camera, Rect(0.0, 0.0, 1.0, 1.0), glm::vec4(1.0, 1.0, 1.0, 1.0));

        window_->swap();
    }
}
