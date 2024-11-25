#pragma once

#include "picosystem.hpp"
#include "../apps/Scene.cpp"
#include "./Constants.cpp"

using namespace picosystem;

// settings
int32_t backlightLevel = 70;
int32_t volume = 100;
int32_t sfx_volume = 100;
bool muted = false;

// audio
int8_t playingSong = -1;
bool stopMusic = false;
voice_t piano = voice(20, 200, 50, 50);
const int16_t notes[] = {0, 262, 277, 294, 311, 330, 349, 370, 391, 415, 440, 466, 494, 523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988, 1047, 1109, 1175, 1245, 1319, 1397, 1480, 1568, 1661, 1760, 1865, 1976, 2093, 2217, 2349, 2489, 2637, 2794, 2960, 3136, 3322, 3520, 3729, 3951};
int32_t timer = 0;

// scenes
Scene *currentScene;
Scene *nextScene;

//common game
int32_t lives;
int32_t score;
int32_t level;
int32_t hiscore;
int32_t theta;
float arrowRadius;
bool isAiming = true;
bool winner = false;
float ballX = 0;
float ballY = 0;

int32_t selectedIndex1;
int32_t lastIndex1;
int32_t selectedIndex2;
int32_t lastIndex2;
int32_t timer1;
bool bool1;
bool bool2;
bool changingSetting;

//hollowbrook

bool graveyardUnlocked = false;
bool manorUnlocked = false;
bool skipStoryText = false;
