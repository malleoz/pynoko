#pragma once

#include "game/field/KColData.hh"
#include "game/field/obj/ObjectObakeManager.hh"
#include <egg/math/Quat.hh>
#include <egg/math/Vector.hh>

#include "KclOpengl.hpp"
#include "ObjObakeOpengl.hpp"
#include "RaceCamera.hpp"

#include <GLFW/glfw3.h>

class MkwVis {
public:
    MkwVis(const Field::KColData *kcl, const Field::ObjectObakeManager *obakeMgr)
        : mKcl(kcl), mObakeMgr(obakeMgr) {}
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
    RaceCamera *mCamera;
    KclOpengl *mKclOgl;
    const Field::KColData *mKcl;
    const Field::ObjectObakeManager *mObakeMgr;
    ObjObakeOpengl *mObjObakeOgl;

    GLFWwindow *mWindow;
    int mWidth;
    int mHeight;
};
