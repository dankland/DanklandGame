#ifndef EVENTS_WINDOW_HPP
#define EVENTS_WINDOW_HPP

#include "event.hpp"

struct WindowCloseEvent : public Event {
   public:
    [[nodiscard]] Type type() const noexcept override {
        return Type::WindowClose;
    }
};

struct WindowResizeEvent : public Event {
   public:
    WindowResizeEvent(const int w, const int h) : width_{w}, height_{h} {
    }

    [[nodiscard]] Type type() const noexcept override {
        return Type::WindowResize;
    }

    [[nodiscard]] int width() const noexcept {
        return width_;
    }

    [[nodiscard]] int height() const noexcept {
        return height_;
    }

   private:
    int width_;
    int height_;
};

#endif
