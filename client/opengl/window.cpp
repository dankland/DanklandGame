#include "window.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../events/event.hpp"
#include "../events/window.hpp"
#include "callbacks.hpp"

OpenGLWindow::OpenGLWindow(const std::string& title,
                           const int w,
                           const int h,
                           const std::function<void(Event&)>& func) {
    data_.width_ = w;
    data_.height_ = h;
    data_.callback_ = func;

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    window_ = glfwCreateWindow(w, h, title.c_str(), NULL, NULL);

    glfwMakeContextCurrent(window_);

    glfwSetWindowUserPointer(window_, &data_);

    // Set callbacks -- Window
    glfwSetWindowSizeCallback(window_, callback_window_size);
    glfwSetWindowCloseCallback(window_, callback_window_close);
    // Set callbacks -- Mouse
    glfwSetCursorPosCallback(window_, callback_cursor_position);
    glfwSetMouseButtonCallback(window_, callback_mouse_button);
    // Set callbacks -- Keyboard
    glfwSetKeyCallback(window_, callback_keyboard);
}

OpenGLWindow::~OpenGLWindow() {
    glfwDestroyWindow(window_);
}

void OpenGLWindow::on_event(Event& e) {
    switch (e.type()) {
        case Event::Type::WindowResize:
            resize(dynamic_cast<WindowResizeEvent&>(e).width(),
                   dynamic_cast<WindowResizeEvent&>(e).height());
            break;
        default:
            break;
    }
}

void OpenGLWindow::fullscreen() {
}

void OpenGLWindow::resize(const int w, const int h) {
    data_.width_ = w;
    data_.height_ = h;
    glViewport(0, 0, w, h);
}

void OpenGLWindow::swap() {
    glfwSwapBuffers(window_);
}
