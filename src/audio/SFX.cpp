#pragma once

#include "picosystem.hpp"
#include "../globals/Basic.cpp"

using namespace picosystem;

void playTick() {
    voice_t tickSound = voice(100,0,0,0,0,0,30,0,0);
    play(tickSound, 350, 30, sfx_volume);
}

void playLowTick() {
    voice_t tickSound = voice(100,0,0,0,0,0,30,0,0);
    play(tickSound, 150, 30, sfx_volume);
}
    
void playError() {
    voice_t errorSound = voice(100,0,60,0,0,0,0,0,60);
    play(errorSound, 300, 400, sfx_volume);
}