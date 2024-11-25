#pragma once

#include "picosystem.hpp"

using namespace picosystem;

class Puzzle2 : public Scene {
public:
    Puzzle2();
    ~Puzzle2();

    void update(uint32_t tick) override;
    void draw(uint32_t tick) override;

private:

};
