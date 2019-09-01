#ifndef DANKLAND_SYSTEM_MOVEMENT_H
#define DANKLAND_SYSTEM_MOVEMENT_H

#include "server/registry.h"

#include "component/position.h"
#include "component/velocity.h"

namespace dankland::system {

class MovementSystem {
   public:
    static void tick() noexcept {
        using component::Position;
        using component::Velocity;

        registry.view<Position, Velocity>().each([](auto& pos, auto& velocity) {
            pos.x += velocity.dx;
            pos.y += velocity.dy;
        });
    }
};

}  // namespace dankland::system

#endif  // DANKLAND_SYSTEM_MOVEMENT_H
