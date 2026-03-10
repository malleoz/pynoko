#include "ObakeDrawable.hpp"
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

void ObakeDrawable::registerBlocks(SceneNode &parent) {
    mCuboids.reserve(mBlockObjs.size());

    for (auto &block : mBlockObjs) {
        mCuboids.emplace_back(325.0f, 325.0f, 325.0f);

        math::Matrix34f mtx;
        mtx.setTranslation(block->pos().x, block->pos().y, block->pos().z);
        mtx.setRotation(block->rot().x, block->rot().y, block->rot().z);

        Color color = randomBrightColor(1.0f);

        mCuboids.back().setMtx(mtx);
        mCuboids.back().setColor(color);

        parent.addChild(&mCuboids.back());
    }
}
