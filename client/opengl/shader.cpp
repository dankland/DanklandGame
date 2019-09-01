#include "shader.hpp"
#include <spdlog/spdlog.h>
#include <cassert>
#include <fstream>
#include <sstream>

Shader::Shader(const Type t, const std::string& str) {
    switch (t) {
        case Type::Vertex:
            id_ = glCreateShader(GL_VERTEX_SHADER);
            break;
        case Type::Fragment:
            id_ = glCreateShader(GL_FRAGMENT_SHADER);
            break;
        default:
            assert(false);
            break;
    }

    const char* source = str.c_str();
    const int length = str.size();
    glShaderSource(id_, 1, &source, &length);
    glCompileShader(id_);

    if (!valid()) {
        spdlog::critical("Shader::valid() failure");
        throw "Shader compile error";
    }
}

Shader::~Shader() {
    glDeleteShader(id_);
}

Shader Shader::from_string(const Type t, const std::string& str) {
    return Shader(t, str);
}

Shader Shader::from_file(const Type t, const std::string& path) {
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();

    return Shader(t, buffer.str());
}

bool Shader::valid() const noexcept {
    GLint status;
    glGetShaderiv(id_, GL_COMPILE_STATUS, &status);
    return status == GL_TRUE;
}

GLuint Shader::id() const noexcept {
    return id_;
}
