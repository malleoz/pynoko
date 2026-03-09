#pragma once

#include <span>
#include <vector>

#include "game/field/obj/ObjectObakeBlock.hh"
#include <egg/math/Vector.hh>

#include "glad/glad.h"

#include "gfx/Color.hpp"
#include "gfx/DrawableCuboid.hpp"
#include "gfx/Shader.hpp"

#include "math/Matrix.hpp"

class ObjObakeOpengl {
public:
    ObjObakeOpengl(const std::vector<Field::ObjectObakeBlock *> &blockObjs);

    void load();
    void draw();

private:
    void processData(const std::vector<Field::ObjectObakeBlock *> &blockObjs);

    std::vector<bolt::gfx::DrawableCuboid> mCube;
};
