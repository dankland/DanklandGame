#ifndef OPENGL_VERTEX_ARRAY_HPP
#define OPENGL_VERTEX_ARRAY_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

class OpenGLVertexArray {
   public:
    OpenGLVertexArray();

    ~OpenGLVertexArray();

    void create(const std::vector<int>& sizes);

    void bind() const noexcept;

    void buffer(const std::vector<float>& vertices);

    [[nodiscard]] int indices() const noexcept;

   private:
    GLuint vao_;
    GLuint vbo_;
    int indices_total_;
    int indices_per_;
};

#endif
