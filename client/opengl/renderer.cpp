#include "renderer.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/type_ptr.hpp>
#include "../camera.hpp"
#include "program.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "vertex_array.hpp"

OpenGLRenderer::OpenGLRenderer() {
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

    colour_program_.compile(vshader, fshader);
    colour_va_.create({3, 3});
}

OpenGLRenderer::~OpenGLRenderer() {
}

void OpenGLRenderer::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLRenderer::clear_colour(const glm::vec3& rgb) {
    glClearColor(rgb.r, rgb.g, rgb.b, 1.0);
}

void OpenGLRenderer::clear_colour(const glm::vec4& rgba) {
    glClearColor(rgba.r, rgba.g, rgba.b, rgba.a);
}

void OpenGLRenderer::draw_rect(const Camera& camera, const Rect& rect, const glm::vec3& rgb) {
    std::vector<float> vertices;
    // p1
    vertices.push_back(rect.x_);
    vertices.push_back(rect.y_);
    vertices.push_back(0.0);
    vertices.push_back(rgb.r);
    vertices.push_back(rgb.g);
    vertices.push_back(rgb.b);
    // p2
    vertices.push_back(rect.x_);
    vertices.push_back(rect.y_ + rect.h_);
    vertices.push_back(0.0);
    vertices.push_back(rgb.r);
    vertices.push_back(rgb.g);
    vertices.push_back(rgb.b);
    // p3
    vertices.push_back(rect.x_ + rect.w_);
    vertices.push_back(rect.y_ + rect.h_);
    vertices.push_back(0.0);
    vertices.push_back(rgb.r);
    vertices.push_back(rgb.g);
    vertices.push_back(rgb.b);
    // p1
    vertices.push_back(rect.x_);
    vertices.push_back(rect.y_);
    vertices.push_back(0.0);
    vertices.push_back(rgb.r);
    vertices.push_back(rgb.g);
    vertices.push_back(rgb.b);
    // p3
    vertices.push_back(rect.x_ + rect.w_);
    vertices.push_back(rect.y_ + rect.h_);
    vertices.push_back(0.0);
    vertices.push_back(rgb.r);
    vertices.push_back(rgb.g);
    vertices.push_back(rgb.b);
    // p4
    vertices.push_back(rect.x_ + rect.w_);
    vertices.push_back(rect.y_);
    vertices.push_back(0.0);
    vertices.push_back(rgb.r);
    vertices.push_back(rgb.g);
    vertices.push_back(rgb.b);

    auto matrix = camera.matrix();

    colour_program_.use();
    colour_program_.set_uniform_mat4("view", glm::value_ptr(matrix), false);
    colour_va_.bind();
    colour_va_.buffer(vertices);
    glDrawArrays(GL_TRIANGLES, 0, colour_va_.indices());
}
