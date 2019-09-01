#ifndef OPENGL_WINDOW_HPP
#define OPENGL_WINDOW_HPP

#include <functional>
#include <string>

struct GLFWwindow;
class Event;

class OpenGLWindow {
   public:
    struct Data {
        std::string title_ = "untitled";
        int width_ = 480;
        int height_ = 480;
        bool fullscreen_ = false;
        bool vsync_ = false;
        double mouse_x_ = 0.0;
        double mouse_y_ = 0.0;
        std::function<void(Event&)> callback_;
    };

    OpenGLWindow(const std::string& title,
                 const int w,
                 const int h,
                 const std::function<void(Event&)>& func);

    ~OpenGLWindow();

    void on_event(Event& e);

    void fullscreen();

    void resize(const int w, const int h);

    void swap();

   private:
    Data data_;
    GLFWwindow* window_;
};

#endif
