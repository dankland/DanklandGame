#ifndef OPENGL_PROGRAM_HPP
#define OPENGL_PROGRAM_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>

class Shader;

class Program {
   public:
    Program();

    Program(const Shader& vshader, const Shader& fshader);

    ~Program();

    void link() noexcept;

    [[nodiscard]] bool valid() const noexcept;

    void attach(const Shader& shader) const noexcept;

    void detach(const Shader& shader) const noexcept;

    void use() const noexcept;

    [[nodiscard]] GLuint id() const noexcept;

    void set_uniform_mat4(const std::string& name,
                          glm::mat4::value_type const* matrix,
                          const bool transpose = false) noexcept;
    void set_uniform_1f(const std::string& name, const float f1) noexcept;
    void set_uniform_2f(const std::string& name, const float f1, const float f2) noexcept;
    void set_uniform_3f(const std::string& name,
                        const float f1,
                        const float f2,
                        const float f3) noexcept;
    void set_uniform_4f(const std::string& name,
                        const float f1,
                        const float f2,
                        const float f3,
                        const float f4) noexcept;
    void set_uniform_1i(const std::string& name, const int i1) noexcept;
    void set_uniform_2i(const std::string& name, const int i1, const int i2) noexcept;
    void set_uniform_3i(const std::string& name, const int i1, const int i2, const int i3) noexcept;
    void set_uniform_4i(const std::string& name,
                        const int i1,
                        const int i2,
                        const int i3,
                        const int i4) noexcept;

   private:
    GLuint id_;
    bool linked_;
};

#endif
