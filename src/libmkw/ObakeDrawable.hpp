#pragma once

#include <vector>

#include "game/field/obj/ObjectObakeBlock.hh"

#include "gfx/DrawableCuboid.hpp"
#include "gfx/SceneNode.hpp"

using namespace bolt;
using namespace bolt::gfx;

class ObakeDrawable {
public:
    ObakeDrawable(const std::vector<Field::ObjectObakeBlock *> &blockObjs)
        : mBlockObjs(blockObjs) {}

    void registerBlocks(SceneNode &parent);

private:
    std::vector<Field::ObjectObakeBlock *> mBlockObjs;
    std::vector<DrawableCuboid> mCuboids;
};
