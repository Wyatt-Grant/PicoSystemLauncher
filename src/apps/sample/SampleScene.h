#pragma once

using namespace picosystem;

class SampleScene : public Scene {
public:
    SampleScene();
    ~SampleScene();

    void update(uint32_t tick) override;
    void draw(uint32_t tick) override;

private:
};
