#include "ObjObakeOpengl.hpp"
#include "common.h"

#include <iostream>

using namespace bolt;

ObjObakeOpengl::ObjObakeOpengl(const std::vector<Field::ObjectObakeBlock *> &blockObjs) {
    processData(blockObjs);
}

void ObjObakeOpengl::load() {
    for (auto &cube : mCube) {
        cube.load();
    }
}

void ObjObakeOpengl::draw() {
    // Iterate each object and draw it
    for (auto &cube : mCube) {
        cube.shader().use();
        cube.draw();
    }
}

void ObjObakeOpengl::processData(const std::vector<Field::ObjectObakeBlock *> &blockObjs) {
    mCube.reserve(blockObjs.size());

    for (auto &block : blockObjs) {
        mCube.emplace_back(250.0f, 250.0f, 250.0f);

        math::Matrix34f mtx;
        mtx.setTranslation(block->pos().x, block->pos().y, block->pos().z);
        mtx.setRotation(block->rot().x, block->rot().y, block->rot().z);

        gfx::Color color = gfx::randomBrightColor(1.0f);

        mCube.back().setMtx(mtx);
        mCube.back().setAmbient(color);
    }
}
