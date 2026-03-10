#pragma once

#include <span>
#include <vector>

#include "game/kart/CollisionGroup.hh"

#include "gfx/DrawableSpheroid.hpp"
#include "gfx/SceneNode.hpp"

using namespace bolt;
using namespace bolt::gfx;

class VehicleHitboxDrawable {
public:
    VehicleHitboxDrawable(const std::span<Kart::Hitbox> &hitboxes) : mHitboxes(hitboxes) {}

    void registerSpheroids(SceneNode &parent);
    void calcSpheroids();

private:
    const std::span<Kart::Hitbox> &mHitboxes;
    std::vector<DrawableSpheroid> mSpheroids;
};
