#pragma once

#include "../game_engine.h"
#include "state.h"

class Camera: public game_engine::component {
    public:
        struct {    
            glm::vec3 dir;
            glm::vec3 right;
            glm::vec3 up;
        }direction;

        struct angle {
            f64 horizontal;
            f64 vertical;
        }angle;

        f32 mouse_speed = 0.01f;
        
        void start() override {}

        void tick() override {
            f64 x_pos, y_pos;
            
            glfwGetCursorPos(state::window, &x_pos, &y_pos);
            //reset mouse in the middle
            glfwSetCursorPos(state::window, state::cfg.size.width/2.0, state::cfg.size.height/2.0);

            angle.horizontal += mouse_speed * state::deltatime * (f32)state::cfg.size.width/2 - x_pos;
            angle.vertical   += mouse_speed * state::deltatime * (f32)state::cfg.size.height/2 - y_pos;

            direction.dir = glm::vec3(
                cos(angle.vertical) * sin(angle.horizontal),
                sin(angle.vertical),
                cos(angle.vertical) * cos(angle.horizontal)
            );

            direction.right = glm::vec3(
                sin(angle.horizontal - 3.14f/2.0f),
                0,
                cos(angle.horizontal - 3.14f/2.0f)
            );

            direction.up = glm::cross(direction.right, direction.dir);
        }
        
        void stop() override {}

        void collision_enter(game_engine::entity *other) override {}
        void collision_exit(game_engine::entity *other) override {}
};

class Movement: public game_engine::component {
        void start() override {
            this->self->pos = glm::vec3(0, 1, 0); 
            
            //starting position, imma just set it at some random place
        }

        void tick() override {}
        void stop() override {}

        void collision_enter(game_engine::entity *other) override {}
        void collision_exit(game_engine::entity *other) override {}
};

class Player: public game_engine::entity {
    public:
        glm::vec3 dir; // forward

        void init() override {
            this->set_name("Player");
        }

    private:

};