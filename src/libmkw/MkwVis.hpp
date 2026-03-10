#pragma once

#include "game/field/KColData.hh"
#include "game/field/obj/ObjectObakeManager.hh"
#include "game/kart/CollisionGroup.hh"
#include <egg/math/Quat.hh>
#include <egg/math/Vector.hh>

#include "KclDrawable.hpp"
#include "ObakeDrawable.hpp"
#include "RaceCamera.hpp"
#include "VehicleHitboxDrawable.hpp"

#include "gfx/RenderSystem.hpp"
#include "gfx/SceneManager.hpp"

#include "glad/glad.h"
#include <GLFW/glfw3.h>

class MkwVis {
public:
    MkwVis(const Field::KColData *kcl, const Field::ObjectObakeManager *obakeMgr,
            const Kart::CollisionGroup *collisionGroup)
        : mKcl(kcl), mObakeMgr(obakeMgr), mCollisionGroup(collisionGroup) {}
    ~MkwVis();
    void createWindow(int width, int height);
    // call once to load graphics
    void load();
    // update character position
    void setPose(const EGG::Vector3f &pos, const EGG::Quatf &rot);
    // call every frame to process events (e.g. clicking 'X' button)
    void update();
    // call every frame to draw
    void draw();
    void destroyWindow();

private:
    bolt::gfx::SceneManager *mScene;
    bolt::gfx::RenderSystem *mRenderSystem;
    RaceCamera *mCamera;
    KclDrawable *mKclDrawable;
    const Field::KColData *mKcl;
    const Field::ObjectObakeManager *mObakeMgr;
    ObakeDrawable *mObakeDrawable;
    VehicleHitboxDrawable *mVehicleHitboxDrawable;
    const Kart::CollisionGroup *mCollisionGroup;

    GLFWwindow *mWindow;
    int mWidth;
    int mHeight;
};
