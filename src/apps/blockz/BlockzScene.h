#pragma once

using namespace picosystem;

class BlockzScene : public Scene {
public:
    BlockzScene();
    ~BlockzScene();

    void update(uint32_t tick) override;
    void draw(uint32_t tick) override;

private:
};
