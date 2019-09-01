#ifndef CALLBACKS_HPP
#define CALLBACKS_HPP

struct GLFWwindow;

void callback_window_size(GLFWwindow* window, int width, int height);
void callback_window_close(GLFWwindow* window);
void callback_cursor_position(GLFWwindow* window, double xpos, double ypos);
void callback_mouse_button(GLFWwindow* window, int button, int action, int mods);
void callback_keyboard(GLFWwindow* window, int key, int scancode, int action, int mods);

#endif
