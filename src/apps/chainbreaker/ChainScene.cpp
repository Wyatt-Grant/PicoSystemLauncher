#pragma once

#include "../Scene.cpp"
#include "../../helpers/Drawing.cpp"
#include "../../helpers/Math.cpp"
#include "../../globals/Complex.cpp"
#include "../../globals/Basic.cpp"
#include "../../audio/sfx.cpp"
#include "../../audio/music.cpp"
#include "ChainScene.h"
#include "../chainbreaker/ChainScene.cpp"

// game vars
bool isTitle = true;
bool isEnd = false;
int32_t cBallColor = 3;
bool justErased = false;
int32_t eraseTimer = 0;

std::pair<double, double> coordinates;
std::pair<double, double> end_coordinates;
double distance;
double original_distance;
std::vector<int> balls = {
    3, 1, 4, 2, 0, 5, 3, 4, 1, 2,
    5, 0, 1, 3, 4, 2, 5, 3, 0, 1,
    2, 4, 5, 3, 1, 0, 2, 4, 5, 1,
    2, 3, 0, 4, 5, 1, 2, 0, 3, 4,
    5, 1, 2, 0, 4, 3, 5, 2, 1, 4,
    5, 2, 4, 1, 3, 0, 5, 1, 4, 2,
    3, 0, 5, 1, 2, 4, 3, 0, 5, 1,
    2, 4, 0, 3, 5, 1, 2, 4, 0, 3,
    0, 5, 2, 3, 1, 4, 0, 5, 3, 2,
    1, 4, 5, 0, 2, 3, 4, 1, 0, 5,
    2, 3, 4, 0, 5, 1, 2, 4, 3, 0,
    5, 2, 4, 1, 3, 0, 5, 1, 4, 2,
    3, 0, 5, 1, 2, 4, 3, 0, 5, 1,
    2, 4, 0, 3, 5, 1, 2, 4, 0, 3,
    5, 1, 2, 4, 0, 3, 5, 2, 1, 4
};


int randomBall(bool isInVector = false) {
    int r = 0;

    if (level == 1) {
        r = rand() % 4;
    } else if (level == 2) {
        r = rand() % 5;
    } else {
        r = rand() % 6;
    }

    if (isInVector) {
        bool found = false;
        for (int color : balls) { 
            if (color == r) {
                found = true;
            }
        }
        if (!found) {
            r = randomBall(true);
        }
    }

    return r;
}


void resetGame(uint32_t tick, bool keepScore = false) {
    srand(tick + theta);
    isTitle = false;
    distance = 175.0;
    original_distance = 100.0;//175.0;
    score = keepScore ? score : 0;
    if (keepScore) {
        level++;
    } else {
        level = 1;
        lives = 3;
    }
    winner = false;
    balls.clear();
    cBallColor = randomBall();

    int32_t ballCount = level * 10;
    if (level > 3) {
        ballCount = level * 8;
    }
    if (level > 6) {
        ballCount = level * 6;
    }

    for (int i = 0; i < ballCount; i++) {
        if (i >= 2) {
            int r = randomBall();
            while(balls[i-2] == r) {
                r = randomBall();
            }
            balls.push_back(r);
        } else {
            balls.push_back(randomBall());
        }
    }
}

ChainScene::ChainScene() : Scene() {
    cls();
    lives = 3;
    score = 0;
    level = 1;
    theta = 90;
    arrowRadius = 10;
    isAiming = true;
    winner = false;
    ballX = 0;
    ballY = 0;

    resetGame(rand());
    coordinates = spiral(distance);
    end_coordinates = spiral(original_distance);
}

ChainScene::~ChainScene() {

}

void ChainScene::update(uint32_t tick) {
    if (isEnd) {
        if (pressed(A)) {
            if (winner) {
                isEnd = false;
                // isTitle = true;
                resetGame(tick, true);
            } else {
                isEnd = false;
                // isTitle = true;
                resetGame(tick);
            }
        }
        return;
    }

    // if (isTitle) {
    //     // if (pressed(A)) {
    //         resetGame(tick);
    //     }

    //     return;
    // }


    if (isAiming) {
        if (button(LEFT)) {
            theta += 5;
            if (theta > 360) {
                theta = 0;
            }
        }
        if (button(RIGHT)) {
            theta -= 5;
            if (theta < 0) {
                theta = 360;
            }
        }
        if (pressed(A)) {
            isAiming = false;
            playTick();
        }
    } else {
        float speed = 1.0;
        ballX = ballX + speed * fcos((pi * (float)theta / (float)180.0));
        ballY = ballY - speed * fsin((pi * (float)theta / (float)180.0));

        float d = isPointOnSpiral(ballX, ballY, distance, distance + (balls.size() * 7), 2.0);
        if (d > 0) {
            isAiming = true;
            distance -= 7;
            score += 1;
            balls.insert(balls.begin() + (int32_t) (d-distance)/7, cBallColor);
            // for (int i = 0; i < 10; i++) {
            //     int removed = removeDuplicates(balls);
            //     score += removed * removed;
            //     distance += removed * 7;
            // }
            isAiming = true;
            cBallColor = randomBall(true);
            ballX = 0;
            ballY = 0;
            srand(tick + theta);
        }
    }

    if (lives <= 0) {
        isEnd = true;
    }

    if (ballX > 70 || ballX < -70 || ballY > 70 || ballY < -70) {
        srand(tick + theta);
        isAiming = true;
        ballX = 0;
        ballY = 0;
        cBallColor = randomBall(true);
    }

    if (justErased) {
        eraseTimer++;
        if (eraseTimer > 0) {
            justErased = false;
            eraseTimer = 0;
        }
    } else if (tick % 4 == 0) {
        for (int32_t r = 0; r < balls.size(); r++) {
            if (balls[r] == -1) {
                balls.erase(balls.begin() + r);
                playTick();
                distance += 6;
                break;
            }
        }

        int removed = removeDuplicates(balls);
        score += removed * removed;
        // distance += removed * 12;
        if (removed > 0) {
            justErased = true;
            cBallColor = randomBall(true);
        } else {
            if (balls.size() < 5) {
                isEnd = true;
                winner = true;
            }
        }

        if (distance <= original_distance) {
            distance += 70;
            lives--;
            playError();
        }
    }
}

void ChainScene::draw(uint32_t tick) {
    cls();

    if (isEnd) {
        pen(15, 15, 15);
        text(winner ? "LEVEL WON" : "GAME OVER", 60 - 27, 18);
        text(str(score), 60 - (str(score).size() * 6)/2, 56);
        return;
    }

    if (isTitle) {
        isTitle = false;

        return;
    }

    // bkg spiral
    double old_distance = original_distance;
    pen(7,7,7);
    for (int i = 0; i < 1000; i++) {
        coordinates = spiral(original_distance);
        line(coordinates.first + 60, coordinates.second + 66, coordinates.first + 61, coordinates.second + 67);
        original_distance += 2;
        if (original_distance > distance) {
            break;
        }
    }
    original_distance = old_distance;

    // balls on spiral
    old_distance = distance;
    for (int color : balls) {
        if (distance <= original_distance) {
            old_distance += 70;
            lives--;
        }

        setColorByInt(color);
        coordinates = spiral(distance);
        text("o", coordinates.first + 60 - 2, coordinates.second + 66 - 4);
        frect(coordinates.first + 60 - 1, coordinates.second + 66 - 1, 3, 3);
        distance += 7;
    }

    // end ball
    pen(7,7,7);
    text("o", end_coordinates.first + 60 - 2, end_coordinates.second + 66 - 4);

    // aaim rrow
    setColorByInt(cBallColor);
    text("o", ballX + 60 - 2, ballY + 66 - 4);
    frect(ballX + 60 - 1, ballY + 66 - 1, 3, 3);
    if (isAiming) {
        int32_t px = 60 + arrowRadius * fcos((pi * (float)theta / (float)180.0));
        int32_t py = 66 - arrowRadius * fsin((pi * (float)theta / (float)180.0));
        line(60,66,px,py);
    }

    pen(15,15,15);
    text("lives", 1, 1);
    text("score", 89, 1);
    for (int i = 0; i < lives; i++) {
        pen(15,2,2);
        text("x", 1 + (i * 7), 9);
    }
    pen(2,15,2);
    text(str(score), 119 - (6 * str(score).size()), 9);

    // distance
    distance = old_distance;
    distance -= 0.03 + (0.01 * level);
}