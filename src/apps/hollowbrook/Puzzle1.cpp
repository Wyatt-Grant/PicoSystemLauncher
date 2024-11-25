#pragma once

#include "picosystem.hpp"
#include "../../globals/Basic.cpp"
#include "./Puzzle1.h"
#include "./MainGame.h"

const int GRID_SIZE = 3;
int orig_puzzle[GRID_SIZE][GRID_SIZE] = { // R D R D L
    { 1, 4, 2 },
    { 3, 5, 8 },
    { 6, 0, 7 }  // 0 represents the empty tile
};
int puzzle[GRID_SIZE][GRID_SIZE] = { // 
    { 1, 4, 2 },
    { 3, 5, 8 },
    { 6, 0, 7 }  // 0 represents the empty tile
};

int emptyX = 1, emptyY = 2; // Position of the empty tile

bool isAnimating = false;
int32_t lastdir = -1;
int animationTimer = 10;
int animX = 0, animY = 0; 

Puzzle1::Puzzle1() : Scene() {

}

Puzzle1::~Puzzle1() {
    
}

void moveTile(int dx, int dy) {
    int newX = emptyX + dx;
    int newY = emptyY + dy;

    // Check if the move is within bounds
    if (newX >= 0 && newX < GRID_SIZE && newY >= 0 && newY < GRID_SIZE) {
        // Swap the empty tile with the adjacent tile
        puzzle[emptyY][emptyX] = puzzle[newY][newX];
        puzzle[newY][newX] = 0;

        animX = emptyX;
        animY = emptyY;
        
        // Update empty tile position
        emptyX = newX;
        emptyY = newY;

        isAnimating = true;
    }
}

void Puzzle1::update(uint32_t tick) {
    if (pressed(UP)) {
        moveTile(0, 1);    // Move tile down
        lastdir = D_UP;
    }
    if (pressed(DOWN)) {
        moveTile(0, -1); // Move tile up
        lastdir = D_DOWN;
    }
    if (pressed(LEFT)) {
        moveTile(1, 0);  // Move tile right
        lastdir = D_LEFT;
    }
    if (pressed(RIGHT)) {
        moveTile(-1, 0); // Move tile left
        lastdir = D_RIGHT;
    }

    if (pressed(X)) {
        for (int y = 0; y < GRID_SIZE; ++y) {
            for (int x = 0; x < GRID_SIZE; ++x) {
                puzzle[x][y] = orig_puzzle[x][y];
            }
        }
        emptyX = 1;
        emptyY = 2;
    }

    bool complete = true;
    int i = 0;
    for (int y = 0; y < GRID_SIZE; ++y) {
        for (int x = 0; x < GRID_SIZE; ++x) {
            if (i != puzzle[y][x]) {
                complete = false;
            }
            i++;
        }
    }
    if (complete) {
        manorUnlocked = true;
        nextScene = new MainGame();
    }

    if (isAnimating) {
        animationTimer--;
        if (animationTimer <= 0) {
            animationTimer = 8;
            isAnimating = false;
        }
    }
}

void Puzzle1::draw(uint32_t tick) {
    cls();
    pen(15,15,15);
    window(25,20,70,70);
    window(0, 97, 120, 23);
    text("Solve the puzzle", 6, 101);
    text("using your d-pad", 6, 109);
    window(0, 0, 120, 15);
    text("Press X to reset", 6, 4);
    
    buffer_t *puzzle_sprite = buffer(64, 64, (void *)puzzle1_data);
    for (int y = 0; y < GRID_SIZE; ++y) {
        for (int x = 0; x < GRID_SIZE; ++x) {
            int tile = puzzle[y][x];
            
            // Skip the empty tile
            if (tile == 0) continue;

            // Calculate the source position in the original image
            int srcX = (tile % GRID_SIZE) * 21;
            int srcY = (tile / GRID_SIZE) * 21;

            // Calculate the destination position on the screen
            int destX = (x * 21) + 28;
            int destY = (y * 21) + 23;

            if (isAnimating && animX == x && animY == y) {
                if (lastdir == D_LEFT) destX += animationTimer*2;
                if (lastdir == D_RIGHT) destX -= animationTimer*2;
                if (lastdir == D_UP) destY += animationTimer*2;
                if (lastdir == D_DOWN) destY -= animationTimer*2;
            }

            // Draw the tile
            bblit(puzzle_sprite, srcX, srcY, 21, 21, destX, destY);
        }
    }
    
    delete puzzle_sprite;
}