#pragma once

#include "picosystem.hpp"

using namespace picosystem;

class Puzzle1 : public Scene {
public:
    Puzzle1();
    ~Puzzle1();

    void update(uint32_t tick) override;
    void draw(uint32_t tick) override;

private:

};
