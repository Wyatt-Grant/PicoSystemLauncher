#pragma once

#include "picosystem.hpp"
#include "./data.cpp"
#include "../../helpers/Drawing.cpp"
#include "./maps/demo.cpp"
#include "./overworld.cpp"

using namespace picosystem;

class Player {
    public:
        int32_t direction;
        bool justFinishedMoving;
        bool isAlignedToGrid;
        bool isMoving;
        
        Player(Vector& camera);
        void update(uint32_t tick);
        void draw(uint32_t tick);
        bool isFacing(int32_t x, int32_t y);

    private:
        int32_t playerFrame;
        Vector& cam;

        void updatePlayerMovement();
        void updatePlayerAnimation(uint32_t tick);
};

void Player::updatePlayerMovement() {
    isAlignedToGrid = (cam.x % 16 == 12 || cam.x % 16 == -4) && (cam.y % 16 == 12 || cam.y % 16 == -4);

    int playerOnTileX = (cam.x + 56)/16;
    int playerOnTileY = (cam.y + 56)/16;

    if (justFinishedMoving) {
        justFinishedMoving = false;
    }

    if (isAlignedToGrid) {
        isMoving = false;
        if (button(UP)) {
            direction = 0;
            if (demo_collide[playerOnTileY-1][playerOnTileX] < 0) {
                isMoving = true;
            }
            if (cam.x <= 668 && cam.y <= 60 && !manorUnlocked) {
                isMoving = false;
            }
        } else if (button(DOWN)) {
            direction = 1;
            if (demo_collide[playerOnTileY+1][playerOnTileX] < 0) {
                isMoving = true;
            }
        } else if (button(LEFT)) {
            direction = 2;
            if (demo_collide[playerOnTileY][playerOnTileX-1] < 0) {
                isMoving = true;
            }
        } else if (button(RIGHT)) {
            direction = 3;
            if (demo_collide[playerOnTileY][playerOnTileX+1] < 0) {
                isMoving = true;
            }
            if (cam.x >= 236 && cam.y >= 620 && !graveyardUnlocked) {
                isMoving = false;
            }
        }
    }

    if (isMoving) {
        switch (direction) {
            case 0:
                cam.y -= 2;
                break;
            case 1:
                cam.y += 2;
                break;
            case 2:
                cam.x -= 2;
                break;
            case 3:
                cam.x += 2;
                break;
        }
            
        if ((cam.x % 16 == 12 || cam.x % 16 == -4) && (cam.y % 16 == 12 || cam.y % 16 == -4)) {
            justFinishedMoving = true;
        }
    }
}

void Player::updatePlayerAnimation(uint32_t tick) {
    switch (direction) {
        case 0:
            playerFrame = 4;
            break;
        case 1:
            playerFrame = 1;
            break;
        case 2:
            playerFrame = 7;
            break;
        case 3:
            playerFrame = 10;
            break;
    }

    if (!isAlignedToGrid || button(UP) || button(DOWN) || button(LEFT) || button(RIGHT)) {
        int animationFrame = (tick % 40)/10;

        if (animationFrame == 0) {
            animationFrame = 0;
        } else if (animationFrame == 1) {
            animationFrame = -1;
        } else if (animationFrame == 2) {
            animationFrame = 0;
        } else if (animationFrame == 3) {
            animationFrame = 1;
        }

        playerFrame += animationFrame;
    }
}

bool Player::isFacing(int32_t x, int32_t y) {
    switch (direction) {
        case DIR_UP:
            return cam.x == x && cam.y - 16 == y;
        case DIR_DOWN:
            return cam.x == x && cam.y + 16 == y;
        case DIR_LEFT:
            return cam.x - 16 == x && cam.y == y;
        case DIR_RIGHT:
            return cam.x + 16 == x && cam.y == y;
    }

    return false;
}

Player::Player(Vector& camera) : cam(camera) {
    direction = 1; // 0 = UP    1 = DOWN    2 = LEFT     3 = RIGHT
    playerFrame = 1;
    isAlignedToGrid = true;
    isMoving = false;
    justFinishedMoving = false;
}

void Player::update(uint32_t tick) {
    updatePlayerMovement();
    updatePlayerAnimation(tick);
}

void Player::draw(uint32_t tick) {
    buffer_t *player_sprite = buffer(192, 16, (void *)overworld_1);
    bblit(player_sprite, playerFrame * 16, 0, 16, 16, 52, 52);
    delete player_sprite;

    // DEBUG
    // pen(15,15,15);
    // window(0, 0, 32, 23);
    // text(str((int32_t) cam.x), 4, 4);
    // text(str((int32_t) cam.y), 4, 12);
}