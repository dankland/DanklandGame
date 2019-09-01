#include "callbacks.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cassert>
#include "../events/mouse.hpp"
#include "../events/window.hpp"
#include "window.hpp"

void callback_window_size(GLFWwindow* window, int width, int height) {
    assert(window);
    OpenGLWindow::Data& data = *(OpenGLWindow::Data*)glfwGetWindowUserPointer(window);
    data.width_ = width;
    data.height_ = height;

    WindowResizeEvent event(width, height);
    data.callback_(event);
}

void callback_window_close(GLFWwindow* window) {
    assert(window);
    OpenGLWindow::Data& data = *(OpenGLWindow::Data*)glfwGetWindowUserPointer(window);

    WindowCloseEvent event;
    data.callback_(event);
}

void callback_cursor_position(GLFWwindow* window, double xpos, double ypos) {
    assert(window);
    OpenGLWindow::Data& data = *(OpenGLWindow::Data*)glfwGetWindowUserPointer(window);
    data.mouse_x_ = xpos;
    data.mouse_y_ = ypos;

    MouseMoveEvent event(xpos, ypos);
    data.callback_(event);
}

void callback_mouse_button(GLFWwindow* window, int button, int action, int mods) {
    assert(window);
    OpenGLWindow::Data& data = *(OpenGLWindow::Data*)glfwGetWindowUserPointer(window);

    if (action == GLFW_PRESS) {
        MouseDownEvent event(data.mouse_x_, data.mouse_y_, button);
        data.callback_(event);
    } else if (action == GLFW_RELEASE) {
        MouseUpEvent event(data.mouse_x_, data.mouse_y_, button);
        data.callback_(event);
    } else {
        assert(false);
    }
}

void callback_keyboard(GLFWwindow* window, int key, int scancode, int action, int mods) {
    assert(window);
    OpenGLWindow::Data& data = *(OpenGLWindow::Data*)glfwGetWindowUserPointer(window);
}
