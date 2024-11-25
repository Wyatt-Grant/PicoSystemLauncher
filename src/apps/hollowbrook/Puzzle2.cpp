#pragma once

#include "picosystem.hpp"
#include "../../globals/Basic.cpp"
#include "./Puzzle2.h"
#include "./MainGame.h"

const int GRID2_SIZE = 4;
int orig2_puzzle[GRID2_SIZE][GRID2_SIZE] = { // R R R D D L L D L U U R U L
    { 0, 1, 3, 7 },
    { 5, 2, 6, 11 },
    { 4, 13, 9, 10 },
    { 8, 12, 14, 15 }  // 0 represents the empty tile
};
int puz[GRID2_SIZE][GRID2_SIZE] = { // R R R D D L L D L U U R U L
    { 0, 1, 3, 7 },
    { 5, 2, 6, 11 },
    { 4, 13, 9, 10 },
    { 8, 12, 14, 15 }  // 0 represents the empty tile
};

int empty2X = 0, empty2Y = 0; // Position of the empty tile

bool is2Animating = false;
int32_t last2dir = -1;
int animation2Timer = 8;
int anim2X = 0, anim2Y = 0; 

Puzzle2::Puzzle2() : Scene() {

}

Puzzle2::~Puzzle2() {
    
}

void moveTile2(int dx, int dy) {
    int newX = empty2X + dx;
    int newY = empty2Y + dy;

    // Check if the move is within bounds
    if (newX >= 0 && newX < GRID2_SIZE && newY >= 0 && newY < GRID2_SIZE) {
        // Swap the empty tile with the adjacent tile
        puz[empty2Y][empty2X] = puz[newY][newX];
        puz[newY][newX] = 0;

        anim2X = empty2X;
        anim2Y = empty2Y;
        
        // Update empty tile position
        empty2X = newX;
        empty2Y = newY;

        is2Animating = true;
    }
}

void Puzzle2::update(uint32_t tick) {
    if (pressed(UP)) {
        moveTile2(0, 1);    // Move tile down
        last2dir = D_UP;
    }
    if (pressed(DOWN)) {
        moveTile2(0, -1); // Move tile up
        last2dir = D_DOWN;
    }
    if (pressed(LEFT)) {
        moveTile2(1, 0);  // Move tile right
        last2dir = D_LEFT;
    }
    if (pressed(RIGHT)) {
        moveTile2(-1, 0); // Move tile left
        last2dir = D_RIGHT;
    }

    if (pressed(X)) {
        for (int y = 0; y < GRID2_SIZE; ++y) {
            for (int x = 0; x < GRID2_SIZE; ++x) {
                puz[x][y] = orig2_puzzle[x][y];
            }
        }
        empty2X = 0;
        empty2Y = 0;
    }

    bool complete = true;
    int i = 0;
    for (int y = 0; y < GRID2_SIZE; ++y) {
        for (int x = 0; x < GRID2_SIZE; ++x) {
            if (i != puz[y][x]) {
                complete = false;
            }
            i++;
        }
    }
    if (complete) {
        graveyardUnlocked = true;
        nextScene = new MainGame();
    }

    if (is2Animating) {
        animation2Timer--;
        if (animation2Timer <= 0) {
            animation2Timer = 8;
            is2Animating = false;
        }
    }
}

void Puzzle2::draw(uint32_t tick) {
    cls();
    pen(15,15,15);
    window(25,20,70,70);
    window(0, 97, 120, 23);
    text("Solve the puzzle", 6, 101);
    text("using your d-pad", 6, 109);
    window(0, 0, 120, 15);
    text("Press X to reset", 6, 4);
    
    buffer_t *puzzle_sprite = buffer(64, 64, (void *)puzzle2_data);
    for (int y = 0; y < GRID2_SIZE; ++y) {
        for (int x = 0; x < GRID2_SIZE; ++x) {
            int tile = puz[y][x];
            
            // Skip the empty tile
            if (tile == 0) continue;

            // Calculate the source position in the original image
            int srcX = (tile % GRID2_SIZE) * 16;
            int srcY = (tile / GRID2_SIZE) * 16;

            // Calculate the destination position on the screen
            int destX = (x * 16) + 28;
            int destY = (y * 16) + 23;

            if (is2Animating && anim2X == x && anim2Y == y) {
                if (last2dir == D_LEFT) destX += animation2Timer*2;
                if (last2dir == D_RIGHT) destX -= animation2Timer*2;
                if (last2dir == D_UP) destY += animation2Timer*2;
                if (last2dir == D_DOWN) destY -= animation2Timer*2;
            }

            // Draw the tile
            bblit(puzzle_sprite, srcX, srcY, 16, 16, destX, destY);
        }
    }
    
    delete puzzle_sprite;
}