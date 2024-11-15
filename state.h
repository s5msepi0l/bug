#include "game_engine.h"
#include "renderer.h"
#include "util.h"
#include "world.h"
#include "components/player.h"

using namespace game_engine;

namespace state {
    Engine game;
    ecs entities;
    World world;

    //main.cpp is responsible for keeping track of the global deltatime
    f32 deltatime;

    // is prolly gonna be wrapped
    GLFWwindow *window;
    pipeline_renderer renderer;


    struct {
        struct {
            u32 width = 1280;
            u32 height = 720;
        }size;

        u32 framerate = 60;
    }cfg;

};