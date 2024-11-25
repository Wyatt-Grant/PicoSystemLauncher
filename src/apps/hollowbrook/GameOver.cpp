#pragma once

#include "picosystem.hpp"
#include "./GameOver.h"
#include "../../globals/Basic.cpp"
#include "../../helpers/Drawing.cpp"

GameOver::GameOver() : Scene() {
    
}

GameOver::~GameOver() {
    
}

void GameOver::update(uint32_t tick) {

}

void GameOver::draw(uint32_t tick) {
    cls();

    pen(15,15,15);
    btext_cx("Thanks", 54, true, tick);
    btext_cx("for playing!", 64, true, tick);
}