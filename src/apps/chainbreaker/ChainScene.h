#pragma once

using namespace picosystem;

class ChainScene : public Scene {
public:
    ChainScene();
    ~ChainScene();

    void update(uint32_t tick) override;
    void draw(uint32_t tick) override;

private:
};
