#pragma once

#include "picosystem.hpp"
// #include "./Scene.cpp"
#include "./Title.h"
// #include "./MainGame.h"
#include "../../globals/Basic.cpp"
#include "./Titlescreen.cpp"
#include "./MainGame.cpp"
#include "./Puzzle1.cpp"
#include "./Puzzle2.cpp"
#include "./GameOver.cpp"

Title::Title() : Scene() {
    playSong(4);
}

Title::~Title() {
    
}

void Title::update(uint32_t tick) {
    if (pressed(A)) {
        nextScene = new MainGame();
        // nextScene = new Puzzle1();
    }
}

void Title::draw(uint32_t tick) {
    cls();

    buffer_t* title = buffer(120, 120, (void *)title_bkg_data);
    bblit(title, 0, 0, 120, 120, 0, 0);
    delete title;

    buffer_t* logo = buffer(118, 20, (void *)logo_data);
    bblit(logo, 0, 0, 118, 20, 1, 10);
    delete logo;

    pen(15,15,15);
    btext_cx("Press A", 84, true, tick);
}