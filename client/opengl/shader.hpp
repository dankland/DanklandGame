#ifndef OPENGL_SHADER_HPP
#define OPENGL_SHADER_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class Shader {
   public:
    enum class Type
    {
        Vertex = 0,
        Fragment
    };

    Shader(const Type t, const std::string& str);

    ~Shader();

    static Shader from_string(const Type t, const std::string& str);

    static Shader from_file(const Type t, const std::string& path);

    [[nodiscard]] bool valid() const noexcept;

    [[nodiscard]] GLuint id() const noexcept;

   private:
    GLuint id_;
};

#endif
