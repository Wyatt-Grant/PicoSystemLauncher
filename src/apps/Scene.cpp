#pragma once

#include "picosystem.hpp"

using namespace picosystem;

class Scene {
    public:
        Scene() {}
        ~Scene() {}

        virtual void update(uint32_t tick) {}
        virtual void draw(uint32_t tick) {}
};