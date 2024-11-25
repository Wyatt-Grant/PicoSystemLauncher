#pragma once

#include "picosystem.hpp"
#include "./Options.h"
#include "./MainGame.cpp"

Options::Options() : Scene() {
    menuIndex = 0;
}

Options::~Options() {
    
}

void Options::update(uint32_t tick) {
    if (pressed(B)) {
        skipStoryText = true;
        nextScene = new MainGame();
    }
    if (button(RIGHT)) {
        if (menuIndex == 0) {
            if (backlightLevel < 100) {
                backlightLevel++;
                backlight(backlightLevel);
            }
        }
        if (menuIndex == 1) {
            if (volume < 100) {
                volume++;
            }
        }
    }
    if (button(LEFT)) {
        if (menuIndex == 0) {
            if (backlightLevel > 15) {
                backlightLevel--;
                backlight(backlightLevel);
            }
        }
        if (menuIndex == 1) {
            if (volume > 0) {
                volume--;
            }
        }
    }
    if (pressed(DOWN)) {
        if (menuIndex < 1) {
            menuIndex++;
        }
    }
    if (pressed(UP)) {
        if (menuIndex > 0) {
            menuIndex--;
        }
    }
}

void Options::draw(uint32_t tick) {
    cls();

    text("Backlight",7,1);  text(str(backlightLevel) + "%",94,1);
    text("Volume",7,9);  text(str(volume) + "%",94,9);

    arrow(1,1 + (8 * menuIndex), D_RIGHT);

}