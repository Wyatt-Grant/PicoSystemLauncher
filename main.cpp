#include "picosystem.hpp"
#include "pico/multicore.h"

#include "src/globals/Basic.cpp"
#include "src/font/Font.cpp"
#include "src/helpers/Drawing.cpp"
#include "src/apps/menu/MenuScene.cpp"

using namespace picosystem;

void init() {
    currentScene = new MenuScene();
    nextScene = nullptr;

    blend(MASK);
    camera(0, 0);
    backlight(backlightLevel);
    font(5, 8, 1, _custom_font);
    multicore_launch_core1(handleMusic);
}

void update(uint32_t tick) {
    if (nextScene == nullptr) {
        currentScene->update(tick);
    }

    if (nextScene != nullptr) {
        delete currentScene;
        currentScene = nextScene;
        nextScene = nullptr;
        delete nextScene;
    }

    led((100 - battery())/4, battery()/4,0);
}

void draw(uint32_t tick) {
    if (nextScene == nullptr) {
        currentScene->draw(tick);
    }
}