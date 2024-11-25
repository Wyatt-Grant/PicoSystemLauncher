#pragma once

#include <math.h>
#include "../Scene.cpp"
#include "../../helpers/Drawing.cpp"
#include "../../globals/Complex.cpp"
#include "../../globals/Basic.cpp"
#include "../../audio/sfx.cpp"
#include "../../audio/music.cpp"
#include "MiniScene.h"
#include "../minigolf/MiniScene.cpp"

// game stuff
// int32_t hiscore = 999;
bool titlescreen = true;

float ballsX[] = {0,0,0,0};
float ballsY[] = {0,0,0,0};

int32_t ballRadius = 2;
float power = 0;
float cpower = 0;
bool isSettingPower = false;
bool justHit = false;
struct Edge {
    int32_t x;
    int32_t y;
    int32_t l;
    bool isVert;
};
Edge lastEdge = {-1,-1,0,false};
float holeX = 0;
float holeY = 0;
int32_t holeRadius = 3;
std::vector<Edge> edges;
int32_t hole = 0;
int32_t strokes[4][9] = {
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
};
bool hasSetUpHole = false;
int32_t playerCount = 0;
int32_t playerTurn = 0;
bool inHole[] = {false,false,false,false};

MiniScene::MiniScene() : Scene() {
    cls();
    hiscore = 999;
    theta = 90;
    arrowRadius = 15;
    isAiming = true;
    ballX = 0;
    ballY = 0;
}

MiniScene::~MiniScene() {

}

void setUpHole() {
    switch(hole) {
        case 0:
            for (int32_t i = 0; i <= playerCount; i++) {
                ballsX[i] = 30;
                ballsY[i] = 60;
                strokes[i][hole] = 0;
            }
            holeX = 90;
            holeY = 60;
            edges.push_back({10,40,100,false});
            edges.push_back({10,80,100,false});
            edges.push_back({10,40,40,true});
            edges.push_back({110,40,41,true});
            break;
        case 1:
            for (int32_t i = 0; i <= playerCount; i++) {
                ballsX[i] = 95;
                ballsY[i] = 80;
                strokes[i][hole] = 0;
            }
            holeX = 25;
            holeY = 45;
            edges.push_back({40,60,70,false});
            edges.push_back({10,100,100,false});
            edges.push_back({10,30,30,false});
            
            edges.push_back({110,60,41,true});
            edges.push_back({10,30,70,true});
            edges.push_back({40,30,30,true});
            break;
        case 2:
            for (int32_t i = 0; i <= playerCount; i++) {
                ballsX[i] = 100;
                ballsY[i] = 60;
                strokes[i][hole] = 0;
            }
            holeX = 20;
            holeY = 60;
            edges.push_back({10,40,30,false});
            edges.push_back({50,40,60,false});

            edges.push_back({10,80,60,false});
            edges.push_back({80,80,30,false});

            edges.push_back({10,40,40,true});
            edges.push_back({110,40,41,true});

            edges.push_back({40,40,26,true});
            edges.push_back({50,40,26,true});
            edges.push_back({40,65,10,false});

            edges.push_back({70,55,26,true});
            edges.push_back({80,55,26,true});
            edges.push_back({70,55,10,false});
            break;
        case 3:
            for (int32_t i = 0; i <= playerCount; i++) {
                ballsX[i] = 30;
                ballsY[i] = 30;
                strokes[i][hole] = 0;
            }
            holeX = 90;
            holeY = 90;
            edges.push_back({10,20,40,false});
            edges.push_back({10,60,60,false});
            edges.push_back({10,20,40,true});
            edges.push_back({50,20,20,true});

            edges.push_back({50,40,60,false});
            edges.push_back({70,100,40,false});
            edges.push_back({70,60,40,true});
            edges.push_back({110,40,61,true});
            break;
        case 4:
            for (int32_t i = 0; i <= playerCount; i++) {
                ballsX[i] = 30;
                ballsY[i] = 100;
                strokes[i][hole] = 0;
            }
            holeX = 100;
            holeY = 60;
            edges.push_back({10,110,40,false});
            edges.push_back({10,70,20,false});
            edges.push_back({10,70,41,true});
            edges.push_back({50,90,21,true});

            edges.push_back({50,90,20,false});
            edges.push_back({30,50,20,false});
            edges.push_back({30,50,21,true});
            edges.push_back({70,70,21,true});

            edges.push_back({70,70,40,false});
            edges.push_back({50,30,60,false});
            edges.push_back({50,30,21,true});
            edges.push_back({110,30,41,true});
            break;
        case 5:
            for (int32_t i = 0; i <= playerCount; i++) {
                ballsX[i] = 20;
                ballsY[i] = 40;
                strokes[i][hole] = 0;
            }
            holeX = 40;
            holeY = 100;
            edges.push_back({10,50,60,false});
            edges.push_back({10,30,20,true});

            edges.push_back({10,30,100,false});
            edges.push_back({30,110,80,false});
            edges.push_back({70,50,41,true});
            edges.push_back({110,30,81,true});

            edges.push_back({30,90,20,true});
            edges.push_back({30,90,40,false});
            break;
        case 6:
            for (int32_t i = 0; i <= playerCount; i++) {
                ballsX[i] = 20;
                ballsY[i] = 100;
                strokes[i][hole] = 0;
            }
            holeX = 90;
            holeY = 90;
            edges.push_back({10,110,40,false});
            edges.push_back({10,20,100,false});
            edges.push_back({50,35,20,false});
            edges.push_back({70,110,40,false});
            edges.push_back({10,20,90,true});
            edges.push_back({50,35,76,true});
            edges.push_back({70,35,75,true});
            edges.push_back({110,20,91,true});
            break;
        case 7:
            for (int32_t i = 0; i <= playerCount; i++) {
                ballsX[i] = 30;
                ballsY[i] = 90;
                strokes[i][hole] = 0;
            }
            holeX = 90;
            holeY = 40;
            edges.push_back({10,110,40,false});
            edges.push_back({10,70,60,false});
            edges.push_back({50,80,21,false});
            edges.push_back({10,70,40,true});
            edges.push_back({50,80,31,true});

            edges.push_back({70,110,40,false});
            edges.push_back({80,70,30,false});
            edges.push_back({70,80,30,true});
            edges.push_back({110,70,41,true});

            edges.push_back({80,60,30,false});
            edges.push_back({70,20,40,false});
            edges.push_back({70,20,51,true});
            edges.push_back({110,20,41,true});
            edges.push_back({80,60,11,true});
            break;
        case 8:
            for (int32_t i = 0; i <= playerCount; i++) {
                ballsX[i] = 100;
                ballsY[i] = 100;
                strokes[i][hole] = 0;
            }
            holeX = 60;
            holeY = 80;
            edges.push_back({10,110,60,false});
            edges.push_back({10,20,100,false});
            edges.push_back({30,40,60,false});
            edges.push_back({90,110,20,false});
            edges.push_back({30,90,20,false});
            edges.push_back({50,70,20,false});
            edges.push_back({10,20,90,true});
            edges.push_back({30,40,51,true});
            edges.push_back({90,40,70,true});
            edges.push_back({110,20,91,true});
            edges.push_back({70,70,41,true});
            edges.push_back({50,70,21,true});
            break;
    }
}

void checkHole() {
    for (int32_t i = 0; i <= playerCount; i++) {
        if (!inHole[i]) {
            if (abs(ballsX[i] - holeX) < 3 && (abs(ballsY[i] - holeY) < 3) && cpower < 60) {
                cpower = 0;
                power = 0;
                inHole[i] = true;
                bool allIn = true;
                for (int32_t i = 0; i <= playerCount; i++) {
                    if (!inHole[i]) {
                        allIn = false;
                        break;
                    }
                }
                if (allIn) {
                    for (int32_t i = 0; i <= playerCount; i++) {
                        inHole[i] = false;
                    }
                    hole += 1;
                    playerTurn = playerCount;
                    hasSetUpHole = false;
                    edges.clear();
                    edges.shrink_to_fit();
                    for (int32_t i = 0; i <= playerCount; i++) {
                        ballsX[i] = 0;
                        ballsY[i] = 0;
                    }
                }

                if (hole == 9) { //end game
                    titlescreen = true;
                    hole = 0;
                    for (int32_t n = 0; n <= playerCount; n++) {
                        int32_t total = 0;
                        for (int32_t i = 0; i < 9; i++) {
                            total += strokes[n][i];
                            strokes[n][i] = 0;
                        }
                        if (hiscore > total) {
                            hiscore = total;       
                            // saveMyData();
                            // readBackMyData();
                        }
                    }
                }

                playTick();
            }
        }
    }
}

void checkEdges() {
    int32_t overlap = 3;
    if (!inHole[playerTurn] && !isAiming && !isSettingPower) {
        for (auto &edge : edges) {
            if (lastEdge.x != edge.x || lastEdge.y != edge.y || lastEdge.l != edge.l || lastEdge.isVert != edge.isVert) {
                if (edge.isVert) {
                    if (theta >= 90 && theta < 270) { // left
                        if (intersects(edge.x, edge.y, 1, edge.l, ballsX[playerTurn]-2, ballsY[playerTurn]-2, 4, 4)) {
                            theta = (sin((pi * (float)theta / 180.0)) * 180.0)/pi;
                            playTick();
                            justHit = true;
                            lastEdge = edge;
                            return;
                        }
                    }
                    if (theta < 90 || theta > 270) {
                        if (intersects(edge.x, edge.y, 1, edge.l, ballsX[playerTurn]-2, ballsY[playerTurn]-2, 4, 4)) {
                            theta = 180 - (sin((pi * (float)theta / 180.0)) * 180.0)/pi;
                            playTick();
                            justHit = true;
                            lastEdge = edge;
                            return;
                        }
                    }
                }
                if (!edge.isVert) {
                    if (theta >= 0 && theta < 180) { // top
                        if (intersects(edge.x, edge.y, edge.l, 1, ballsX[playerTurn]-2, ballsY[playerTurn]-2, 4, 4)) {
                            theta = 270 + (sin((pi * (float)(theta-270) / 180.0)) * 180.0)/pi;
                            playTick();
                            justHit = true;
                            lastEdge = edge;
                            return;
                        }
                    }
                    if (theta < 0 || theta >= 180) {
                        if (intersects(edge.x, edge.y, edge.l, 1, ballsX[playerTurn]-2, ballsY[playerTurn]-2, 4, 4)) {
                            theta = 90 + (sin((pi * (float)(theta-90) / 180.0)) * 180.0)/pi;
                            playTick();
                            justHit = true;
                            lastEdge = edge;
                            return;
                        }
                    }
                }
            }
        }
    }
}

void drawEdges() {
    for (auto &edge : edges) {
        if (edge.isVert) vline(edge.x,edge.y,edge.l);
        if (!edge.isVert) hline(edge.x,edge.y,edge.l);
    }
}

void MiniScene::update(uint32_t tick) {
     if (titlescreen) {
        if (pressed(A)) {
            titlescreen = false;
        }
        if (pressed(UP)) {
            if (playerCount > 0) {
                playerCount -= 1;
            }
        }
        if (pressed(DOWN)) {
            if (playerCount < 3) {
                playerCount += 1;
            }
        }
        return;
    }

    if (!hasSetUpHole) {
        setUpHole();
        hasSetUpHole = true;
    }

    if (isAiming) {
        lastEdge = {-1,-1,0,false};
        if (button(LEFT)) {
            if (theta++ > 360) theta = 0;
        }
        if (button(RIGHT)) {
            if (theta-- < 0) theta = 360;
        }
        if (pressed(A)) {
            isAiming = false;
            isSettingPower = true;
        }
        if (button(Y) && pressed(X)) {
            for (int32_t i = 0; i <= playerCount; i++) {
                inHole[i] = false;
            }
            playerTurn = playerCount;
            hasSetUpHole = false;
            edges.clear();
            edges.shrink_to_fit();
            for (int32_t i = 0; i <= playerCount; i++) {
                ballsX[i] = 0;
                ballsY[i] = 0;
            }
            for (int32_t i = 0; i <= playerCount; i++) {
                strokes[hole][i] = 0;
            }
        }
    } else if (isSettingPower) {
        if (power < 5) {
            power++;
        } else if (power < 60) {
            power+=2;
        } else if (power < 120) {
            power+=4;
        } else {
            power+=6;
        }

        if (power > 240) power = 0;
        frect(0,112,power/2,8);
        if (pressed(A)) {
            cpower = power;
            isSettingPower = false;
            if (strokes[playerTurn][hole] < 9) strokes[playerTurn][hole] += 1;
            playTick();
        }
    } else if (!isAiming && !isSettingPower) {
        float speed = cpower > 20 ? 2 : 1.1;
        cpower -= 1;
        if (justHit) {
            speed = 4;
            justHit = false;
        }

        float bx = ballsX[playerTurn] + speed * cos((pi * (float)theta / (float)180.0));
        float by = ballsY[playerTurn] - speed * sin((pi * (float)theta / (float)180.0));
        ballsX[playerTurn] = bx;
        ballsY[playerTurn] = by;

        if (cpower <= 0) {
            isAiming = true;
            power = 0;
            if (ballsY[playerTurn] < 60) {
                theta = 270;
            } else {
                theta = 90;
            }
            do {
                playerTurn += 1;
                if (playerTurn > playerCount) {
                    playerTurn = 0; 
                }
            } while(inHole[playerTurn]);
        }
    }

    checkEdges();
    checkHole();
}

void MiniScene::draw(uint32_t tick) {
    if (titlescreen) {
        cls();
        pen(15,15,15);
        btext_cx("Wyatt's Mini Golf", 30);
        btext("X + Y to reset", 40, 113);

        btext_cx(playerCount == 0 ? "> 1 Player " : "1 Player ", 60);
        btext_cx(playerCount == 1 ? "> 2 Player " : "2 Player ", 70);
        btext_cx(playerCount == 2 ? "> 3 Player " : "3 Player ", 80);
        btext_cx(playerCount == 3 ? "> 4 Player " : "4 Player ", 90);
        return;
    }

    clear_area(0,0,120,8);
    pen(0,7,0);
    frect(0,9,120,112);

    pen(10,10,10);
    fcircle(holeX,holeY,holeRadius);
    
    for (int32_t i = playerCount; i >= 0; i--) {
        switch (i) {
            case 0:
                pen(15,15,15);
                break;
            case 1:
                pen(5,15,5);
                break;
            case 2:
                pen(15,5,5);
                break;
            case 3:
                pen(5,5,15);
                break;
        }
        if (!inHole[i]) {
            fcircle(ballsX[i],ballsY[i],ballRadius);
        }
    }
    switch (playerTurn) {
        case 0:
            pen(15,15,15);
            break;
        case 1:
            pen(5,15,5);
            break;
        case 2:
            pen(15,5,5);
            break;
        case 3:
            pen(5,5,15);
            break;
    }
    if (!inHole[playerTurn]) {
        fcircle(ballsX[playerTurn],ballsY[playerTurn],ballRadius);
    }
    for (int32_t i = 0; i <= playerCount; i++) {
        switch (i) {
            case 0:
                pen(15,15,15);
                break;
            case 1:
                pen(5,15,5);
                break;
            case 2:
                pen(15,5,5);
                break;
            case 3:
                pen(5,5,15);
                break;
        }
        int32_t total = 0;
        for (int32_t n = 0; n < 9; n++) {
            total += strokes[i][n];
        }
        text(str(total),70+(i*12),0);
    }
    pen(15,15,15);

    drawEdges();

    //ui
    switch (playerTurn) {
        case 0:
            pen(15,15,15);
            break;
        case 1:
            pen(5,15,5);
            break;
        case 2:
            pen(15,5,5);
            break;
        case 3:
            pen(5,5,15);
            break;
    }

    if (isAiming) {
        int32_t px = ballsX[playerTurn] + arrowRadius * cos((pi * (float)theta / (float)180.0));
        int32_t py = ballsY[playerTurn] - arrowRadius * sin((pi * (float)theta / (float)180.0));
        line(ballsX[playerTurn],ballsY[playerTurn],px,py);
    }

    for (int32_t i = 0; i < 9; i++) {
        text(strokes[playerTurn][i] == 0 && i != hole ? "-" : str(strokes[playerTurn][i]),(i*7) + 2,0);
    }

    pen(15,15,15);
    hline(0,8,120);
}