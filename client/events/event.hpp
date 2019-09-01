#ifndef EVENTS_EVENT_HPP
#define EVENTS_EVENT_HPP

struct Event {
   public:
    enum class Type
    {
        // Window
        WindowClose = 0,
        WindowResize,
        // Mouse
        MouseMove,
        MouseDown,
        MouseUp,
        // Keyboard
    };

    [[nodiscard]] virtual Type type() const noexcept = 0;
};

#endif
