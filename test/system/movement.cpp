#include "catch2/catch.hpp"

#include "server/registry.h"

#include "server/component/position.h"
#include "server/component/velocity.h"

#include "server/system/movement.h"

TEST_CASE("Movement Test", "[Movement]") {
    using dankland::registry;
    using dankland::component::Position;
    using dankland::component::Velocity;

    auto entity = registry.create();
    auto& pos = registry.assign<Position>(entity, 1, 2);
    registry.assign<Velocity>(entity, -5, 5);

    dankland::system::update_positions(1);

    REQUIRE(pos.x == -4);
    REQUIRE(pos.y == 7);
}
