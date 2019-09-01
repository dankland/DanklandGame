#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <memory>

class OpenGLContext;
class OpenGLWindow;
class Event;

class Application {
   public:
    Application();

    ~Application();

    void on_event(Event& e);

    void run();

   private:
    std::shared_ptr<OpenGLContext> render_context_;
    std::shared_ptr<OpenGLWindow> window_;
    bool quit_;
};

#endif
