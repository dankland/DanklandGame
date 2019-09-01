#ifndef OPENGL_TEXTURE_HPP
#define OPENGL_TEXTURE_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class OpenGLTexture2D {
   public:
    explicit OpenGLTexture2D(const std::string& path);

    ~OpenGLTexture2D();

    [[nodiscard]] int get_width() const noexcept;

    [[nodiscard]] int get_height() const noexcept;

    void bind() const noexcept;

   private:
    GLuint id_;
    int width_;
    int height_;
    int channels_;
};

#endif
