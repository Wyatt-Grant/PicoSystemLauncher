#pragma once

using namespace picosystem;

class MenuScene : public Scene {
public:
    MenuScene();
    ~MenuScene();

    void update(uint32_t tick) override;
    void draw(uint32_t tick) override;

private:
};
