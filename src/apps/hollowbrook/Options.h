#pragma once

#include "picosystem.hpp"
#include "./OverWorld.cpp"

using namespace picosystem;

class Options : public Scene {
public:
    Options();
    ~Options();

    void update(uint32_t tick) override;
    void draw(uint32_t tick) override;

private:
    int32_t menuIndex;
};
