#ifndef DANKLAND_SERVER_SYSTEM_MOVEMENT_H
#define DANKLAND_SERVER_SYSTEM_MOVEMENT_H

#include "server/registry.h"

#include "server/component/position.h"
#include "server/component/velocity.h"

namespace dankland::system {

void update_positions(int dt) noexcept {
    using component::Position;
    using component::Velocity;

    registry.view<Position, Velocity>().each([dt](auto& pos, auto& velocity) {
        pos.x += velocity.dx * dt;
        pos.y += velocity.dy * dt;
    });
}

}  // namespace dankland::system

#endif  // DANKLAND_SERVER_SYSTEM_MOVEMENT_H
