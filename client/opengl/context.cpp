#include "context.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

OpenGLContext::OpenGLContext() {
    spdlog::debug("OpenGLContext contructor");
    const bool success = glfwInit();
    if (!success) {
        spdlog::critical("glfwInit() failure");
        throw "glfwInit() failure";
    }
}

OpenGLContext::~OpenGLContext() {
    spdlog::debug("OpenGLContext destructor");
    glfwTerminate();
}

void OpenGLContext::init() {
    spdlog::debug("OpenGLContext::init()");
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    while ((err = glGetError()) != GL_NO_ERROR) {
    }

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void OpenGLContext::poll() {
    glfwPollEvents();
}
