#pragma once

using namespace picosystem;

class WordScene : public Scene {
public:
    WordScene();
    ~WordScene();

    void update(uint32_t tick) override;
    void draw(uint32_t tick) override;

private:
};
