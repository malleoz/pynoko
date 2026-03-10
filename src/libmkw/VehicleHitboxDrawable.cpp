#include "VehicleHitboxDrawable.hpp"
#include "common.h"

#include <iostream>

#include "gfx/Color.hpp"

using namespace bolt;
using namespace bolt::gfx;

static Color randomBrightColor(float minBrightness) {
    RUNTIME_ASSERT(minBrightness < 2.0f, "minBrightness must be between 0 and 2");

    Color ret;
    ret.a = 1.0f;
    do {
        ret.r = static_cast<float>(rand()) / RAND_MAX;
        ret.g = static_cast<float>(rand()) / RAND_MAX;
        ret.b = static_cast<float>(rand()) / RAND_MAX;
    } while (ret.r + ret.g + ret.b < minBrightness);

    return ret;
}

void VehicleHitboxDrawable::registerSpheroids(SceneNode &parent) {
    mSpheroids.reserve(mHitboxes.size());

    std::cout << "Registering " << mHitboxes.size() << " hitboxes." << std::endl;

    for (auto &hitbox : mHitboxes) {
        f32 radius = hitbox.radius();
        std::cout << "Radius: " << radius << std::endl;
        mSpheroids.emplace_back(radius, radius, radius);

        const EGG::Vector3f &worldPos = hitbox.worldPos();

        Color color = randomBrightColor(1.0f);

        mSpheroids.back().setTranslation(worldPos.x, worldPos.y, worldPos.z);
        mSpheroids.back().setColor(color);

        parent.addChild(&mSpheroids.back());
    }
}

void VehicleHitboxDrawable::calcSpheroids() {
    for (size_t i = 0; i < mHitboxes.size(); ++i) {
        const EGG::Vector3f &worldPos = mHitboxes[i].worldPos();
        std::cout << worldPos.x << " | " << worldPos.y << " | " << worldPos.z << std::endl;
        mSpheroids[i].setTranslation(worldPos.x, worldPos.y, worldPos.z);
    }
}
