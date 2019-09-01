#include "renderer.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "program.hpp"
#include "texture.hpp"
#include "vertex_array.hpp"

OpenGLRenderer::OpenGLRenderer() {
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

void OpenGLRenderer::draw(const Program& program, const OpenGLVertexArray& va) {
    program.use();
    va.bind();
    glDrawArrays(GL_TRIANGLES, 0, va.indices());
}

void OpenGLRenderer::draw(const Program& program,
                          const OpenGLTexture2D& texture,
                          const OpenGLVertexArray& va) {
    program.use();
    texture.bind();
    va.bind();
    glDrawArrays(GL_TRIANGLES, 0, va.indices());
}
