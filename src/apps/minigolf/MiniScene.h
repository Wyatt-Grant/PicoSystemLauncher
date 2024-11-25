#pragma once

using namespace picosystem;

class MiniScene : public Scene {
public:
    MiniScene();
    ~MiniScene();

    void update(uint32_t tick) override;
    void draw(uint32_t tick) override;

private:
};
