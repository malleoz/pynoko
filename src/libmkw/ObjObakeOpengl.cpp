#include "ObjObakeOpengl.hpp"
#include "common.h"

#include <iostream>

using namespace bolt;

ObjObakeOpengl::ObjObakeOpengl(const std::vector<Field::ObjectObakeBlock *> &blockObjs)
    : mBlockObjs(blockObjs), mCube(150.0f, 150.0f, 150.0f) {
    mShader = gfx::Shader(LIBMKW_RES("kcl.vert"), LIBMKW_RES("kcl.frag"));
    mShader.use();
}

void ObjObakeOpengl::load() {
    // set pose (identity for course)
    mShader.use();
    math::Matrix44f mtx;
    mtx.setIdentity();
    mShader.setMat4("model", mtx);

    // Camera matrices (set by Camera)
    mShader.use();
    unsigned int uniformIndex = glGetUniformBlockIndex(mShader.id(), "Matrices");
    glUniformBlockBinding(mShader.id(), uniformIndex, 0);
}

void ObjObakeOpengl::draw() {
    // Iterate each object and draw it
    for (const auto *obj : mBlockObjs) {
        math::Vector3f scale(obj->scale().x, obj->scale().y, obj->scale().z);

        math::Matrix44f model;
        model.setIdentity();
        model.setRotation(obj->rot().x, obj->rot().y, obj->rot().z);

        for (int i = 0; i < 3; ++i) {
            model.data[i][0] *= obj->scale().x;
            model.data[i][1] *= obj->scale().y;
            model.data[i][2] *= obj->scale().z;
        }

        model.setTranslation(obj->pos().x, obj->pos().y, obj->pos().z);

        mShader.use();
        mShader.setMat4("model", model);
        gfx::Color color = gfx::COLOR_WHITE;
        mShader.setVec4("ambientColor", math::Vector4f(color.r, color.g, color.b, color.a));

        mCube.draw();
    }
}
