#include "program.hpp"
#include <spdlog/spdlog.h>
#include "shader.hpp"

Program::Program() : linked_{false} {
    id_ = glCreateProgram();
}

Program::Program(const Shader& vshader, const Shader& fshader) : linked_{false} {
    spdlog::debug("Program constructor");
    id_ = glCreateProgram();

    attach(vshader);
    attach(fshader);
    link();
    detach(fshader);
    detach(vshader);

    if (!valid()) {
        spdlog::critical("Program link error");
        throw "Program link error";
    }
}

Program::~Program() {
    spdlog::debug("Program destructor");
    glDeleteProgram(id_);
}

void Program::link() noexcept {
    glLinkProgram(id_);
    linked_ = true;
}

bool Program::valid() const noexcept {
    GLint status;
    glGetProgramiv(id_, GL_LINK_STATUS, &status);
    return status == GL_TRUE;
}

void Program::attach(const Shader& shader) const noexcept {
    glAttachShader(id_, shader.id());
}

void Program::detach(const Shader& shader) const noexcept {
    glDetachShader(id_, shader.id());
}

void Program::use() const noexcept {
    glUseProgram(id_);
}

GLuint Program::id() const noexcept {
    return id_;
}

void Program::set_uniform_mat4(const std::string& name,
                               glm::mat4::value_type const* matrix,
                               const bool transpose) noexcept {
    const auto loc = glGetUniformLocation(id_, name.c_str());
    glUniformMatrix4fv(loc, 1, transpose, matrix);
}

void Program::set_uniform_1f(const std::string& name, const float f1) noexcept {
    const auto loc = glGetUniformLocation(id_, name.c_str());
    glUniform1f(loc, f1);
}

void Program::set_uniform_2f(const std::string& name, const float f1, const float f2) noexcept {
    const auto loc = glGetUniformLocation(id_, name.c_str());
    glUniform2f(loc, f1, f2);
}

void Program::set_uniform_3f(const std::string& name,
                             const float f1,
                             const float f2,
                             const float f3) noexcept {
    const auto loc = glGetUniformLocation(id_, name.c_str());
    glUniform3f(loc, f1, f2, f3);
}

void Program::set_uniform_4f(const std::string& name,
                             const float f1,
                             const float f2,
                             const float f3,
                             const float f4) noexcept {
    const auto loc = glGetUniformLocation(id_, name.c_str());
    glUniform4f(loc, f1, f2, f3, f4);
}

void Program::set_uniform_1i(const std::string& name, const int i1) noexcept {
    const auto loc = glGetUniformLocation(id_, name.c_str());
    glUniform1i(loc, i1);
}

void Program::set_uniform_2i(const std::string& name, const int i1, const int i2) noexcept {
    const auto loc = glGetUniformLocation(id_, name.c_str());
    glUniform2i(loc, i1, i2);
}

void Program::set_uniform_3i(const std::string& name,
                             const int i1,
                             const int i2,
                             const int i3) noexcept {
    const auto loc = glGetUniformLocation(id_, name.c_str());
    glUniform3i(loc, i1, i2, i3);
}

void Program::set_uniform_4i(const std::string& name,
                             const int i1,
                             const int i2,
                             const int i3,
                             const int i4) noexcept {
    const auto loc = glGetUniformLocation(id_, name.c_str());
    glUniform4i(loc, i1, i2, i3, i4);
}
