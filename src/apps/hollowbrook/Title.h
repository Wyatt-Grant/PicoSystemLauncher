#pragma once

#include "picosystem.hpp"

using namespace picosystem;

class Title : public Scene {
public:
    Title();
    ~Title();

    void update(uint32_t tick) override;
    void draw(uint32_t tick) override;

private:

};
