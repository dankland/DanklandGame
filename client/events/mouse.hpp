#ifndef EVENTS_MOUSE_HPP
#define EVENTS_MOUSE_HPP

#include "event.hpp"

struct MouseMoveEvent : public Event {
   public:
    MouseMoveEvent(const int x, const int y) : x_{x}, y_{y} {
    }

    [[nodiscard]] Type type() const noexcept override {
        return Type::MouseMove;
    }

   private:
    int x_;
    int y_;
};

struct MouseDownEvent : public Event {
   public:
    MouseDownEvent(const int x, const int y, const int button) : x_{x}, y_{y}, button_{button} {
    }

    [[nodiscard]] Type type() const noexcept override {
        return Type::MouseDown;
    }

   private:
    int x_;
    int y_;
    int button_;
};

struct MouseUpEvent : public Event {
   public:
    MouseUpEvent(const int x, const int y, const int button) : x_{x}, y_{y}, button_{button} {
    }

    [[nodiscard]] Type type() const noexcept override {
        return Type::MouseUp;
    }

   private:
    int x_;
    int y_;
    int button_;
};

#endif
