#pragma once

// #include "../Scene.cpp"
#include "../../helpers/Drawing.cpp"
#include "../../globals/Complex.cpp"
#include "../../globals/Basic.cpp"
#include "../../audio/sfx.cpp"
#include "../../audio/music.cpp"
#include "./MainGame.h"
#include "./data.cpp"
#include "./Titlescreen.cpp"
#include "./NPCs.cpp"
#include "./Options.cpp"
#include "./Teleports.cpp"
#include "./Message.cpp"

Vector cam = { 428, 220 };


MainGame::MainGame() : Scene() {
    tileMap = new TileMap(cam);
    player = new Player(cam);
    message = new Message();
    npcs = new NPCs(player, message, cam);
    teleports = new Teleports(cam);

    menuIsOpen = false;
    titleScreen = true;
    menuIndex = 0;

    playSong(16);

    if (!skipStoryText) {
        if (graveyardUnlocked) {
            message->add("You: I fixed it!\nthe code word is:\nNEVER DIE!");
        } else if (manorUnlocked) {
            message->add("You: It looks\nlike a demon?\non the back is a\ncontract for\nimmortality in\nexchange for\nyoung lives.\nit's signed by\nthe mayor.");
        } else {
            message->add("You: I've finally\narrived in\nHollowbrook!\nTime to see if\nthe rumours about\nmissing kids\nare true!");
        }
    } else {
        skipStoryText = false;
    }
}

MainGame::~MainGame() {
    delete player;
    delete tileMap;
    delete message;
    delete npcs;
    delete teleports;
}

void MainGame::update(uint32_t tick) {
    if (!message->isBusy()) {
        if ((pressed(X) && player->isAlignedToGrid && !player->isMoving) || (menuIsOpen && pressed(B) && player->isAlignedToGrid && !player->isMoving)) {
            menuIsOpen = !menuIsOpen;
            menuIndex = 0;
            if (menuIsOpen) {
                stopSong();
            } else {
                playSong(16);
            }
        }
        if (!menuIsOpen) {
            player->update(tick);
            npcs->update(tick);
            teleports->update(tick);
        } else {
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
            if (pressed(A)) {
                switch (menuIndex) {
                    case 0:
                        nextScene = new Options();
                        break;
                    default:
                        menuIsOpen = false;
                        menuIndex = 0;
                        playSong(16);
                        break;
                }
            }
        }
    }

    message->update(tick);
}

void MainGame::draw(uint32_t tick) {
    cls();
    tileMap->draw(tick, 1);
    player->draw(tick);
    tileMap->draw(tick, 2);
    npcs->draw(tick);
    message->draw(tick);

    if (menuIsOpen) {
        pen(15,15,15);
        window(30, 94, 60, 50);
        text("Options", 42, 102);
        text("Cancel", 42, 110);
        window(36, -10, 47, 25);
        text("PAUSED", 42, 2);

        arrow(36, 102 + (8 * menuIndex), D_RIGHT);
    }
}