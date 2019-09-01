#include "vertex_array.hpp"

OpenGLVertexArray::OpenGLVertexArray(const std::vector<int>& sizes)
    : indices_total_{0}, indices_per_{0} {
    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);

    glGenBuffers(1, &vbo_);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_);

    int index = 0;
    int stride = 0;
    int offset = 0;

    for (const auto& size : sizes) {
        stride += size * sizeof(GL_FLOAT);
        indices_per_ += size;
    }

    for (const auto& size : sizes) {
        glEnableVertexAttribArray(index);
        glVertexAttribPointer(
            index, size, GL_FLOAT, GL_FALSE, stride, static_cast<const void*>(0) + offset);

        index++;
        offset += size * sizeof(GL_FLOAT);
    }
}

OpenGLVertexArray::~OpenGLVertexArray() {
    glDeleteBuffers(1, &vbo_);
    glDeleteVertexArrays(1, &vao_);
}

void OpenGLVertexArray::bind() const noexcept {
    glBindVertexArray(vao_);
}

void OpenGLVertexArray::buffer(const std::vector<float>& vertices) {
    glBindVertexArray(vao_);

    glBindBuffer(GL_ARRAY_BUFFER, vbo_);
    glBufferData(
        GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), &vertices[0], GL_STATIC_DRAW);

    indices_total_ = vertices.size();
}

[[nodiscard]] int OpenGLVertexArray::indices() const noexcept {
    return indices_total_ / indices_per_;
}
