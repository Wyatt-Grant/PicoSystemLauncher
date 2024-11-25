#pragma once

using namespace picosystem;

class PicoManScene : public Scene {
public:
    PicoManScene();
    ~PicoManScene();

    void update(uint32_t tick) override;
    void draw(uint32_t tick) override;

private:
};
