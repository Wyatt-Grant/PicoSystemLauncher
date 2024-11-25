#pragma once

#include "picosystem.hpp"

using namespace picosystem;

class GameOver : public Scene {
public:
    GameOver();
    ~GameOver();

    void update(uint32_t tick) override;
    void draw(uint32_t tick) override;

private:

};
