#pragma once

#include "../Scene.cpp"
#include "../../helpers/Drawing.cpp"
#include "../../globals/Complex.cpp"
#include "../../globals/Basic.cpp"
#include "../../audio/sfx.cpp"
#include "../../audio/music.cpp"
#include "MenuScene.h"
#include "../picoman/PicoManScene.cpp"
#include "../minigolf/MiniScene.cpp"
#include "../blockz/BlockzScene.cpp"
#include "../chainbreaker/ChainScene.cpp"
#include "../wordguesser/WordScene.cpp"
#include "../hollowbrook/Title.cpp"

MenuScene::MenuScene() : Scene() {
    stringVector1 = {"< Games >", "< Music >", "< Settings >"}; // holds menu options
    selectedIndex1 = 0; // menu index
    lastIndex1 = 0; // old menu index

    stringVector2 = {}; // holds options for current menu item
    selectedIndex2 = 0; // options index
    lastIndex2 = 0; // old options index

    timer1 = 99; // animation timer for sliding
    bool1 = false; // if just pressed right
    bool2 = false; // if just pressed left/right
    changingSetting = false;
}

MenuScene::~MenuScene() {
    stringVector1.clear();
}

void MenuScene::update(uint32_t tick) {
    // timer
    if (timer1 > 10) {
        if (bool2) {
            lastIndex1 = selectedIndex1;
        } else {
            lastIndex2 = selectedIndex2;
        }
        timer1 = 0;
        playTick();
        stringVector2.clear();
        switch (selectedIndex1)
        {
            case 0:
                stringVector2.assign({"Pico-Man", "Blockz", "Chain Breaker", "Word Guesser", "Mini Golf", "Hollowbrook"});
                break;
            case 1:
                for (size_t i = 0; i < songsCount; i++) {
                    stringVector2.push_back(get_song_name(i));
                }
                break;
            case 2:
                stringVector2.assign({"Music Volume", "SFX Volume", "BackLight"});
                break;
            default:
                stringVector2.assign({"test1"});
                break;
        }
    }
    if (lastIndex1 != selectedIndex1 || lastIndex2 != selectedIndex2) {
        timer1++;
        return;
    }

    // left / right
    if (button(RIGHT) && timer1 == 0 && !changingSetting) {
        lastIndex1 = selectedIndex1;
        selectedIndex1++;
        selectedIndex2 = 0;
        lastIndex2 = 0;
        bool1 = true;
        bool2 = true;
        playLowTick();
        stopSong();
    } else if (button(LEFT) && timer1 == 0 && !changingSetting) {
        lastIndex1 = selectedIndex1;
        selectedIndex1--;
        selectedIndex2 = 0;
        lastIndex2 = 0;
        bool1 = false;
        bool2 = true;
        playLowTick();
        stopSong();
    } else if (button(UP) && timer1 == 0) {
        lastIndex2 = selectedIndex2;
        selectedIndex2++;
        bool1 = true;
        bool2 = false;
        playLowTick();
        stopSong();
        changingSetting = false;
    } else if (button(DOWN) && timer1 == 0) {
        lastIndex2 = selectedIndex2;
        selectedIndex2--;
        bool1 = false;
        bool2 = false;
        playLowTick();
        stopSong();
        changingSetting = false;
    }
    
    if (selectedIndex1 < 0) selectedIndex1 = stringVector1.size() - 1;
    if (selectedIndex1 > (stringVector1.size() - 1)) selectedIndex1 = 0;
    
    if (selectedIndex2 < 0) selectedIndex2 = stringVector2.size() - 1;
    if (selectedIndex2 > (stringVector2.size() - 1)) selectedIndex2 = 0;

    if (selectedIndex1 == 2) {
        if (pressed(A)) {
            changingSetting = true;
        }
        if (pressed(B)) {
            changingSetting = false;
        }
        if (pressed(LEFT) && changingSetting) {
            if (selectedIndex2 == 0 && volume >= 10) volume-=10;
            if (selectedIndex2 == 1 && sfx_volume >= 10) sfx_volume-=10;
            if (selectedIndex2 == 2 && backlightLevel >= 10) backlightLevel-=10;
            backlight(backlightLevel);
        }
        if (pressed(RIGHT) && changingSetting) {
            if (selectedIndex2 == 0 && volume <= 90) volume+=10;
            if (selectedIndex2 == 1 && sfx_volume <= 90) sfx_volume+=10;
            if (selectedIndex2 == 2 && backlightLevel <= 90) backlightLevel+=10;
            backlight(backlightLevel);
        }
    }

    if (pressed(A) && selectedIndex1 == 1) {
        playSong(selectedIndex2);
    }
    if (pressed(B)) {
        stopSong();
    }

    if (pressed(A) && selectedIndex1 == 0) {
        srand(tick);
        if (selectedIndex2 == 0) {
            nextScene = new PicoManScene();
        } else if (selectedIndex2 == 1) {
            nextScene = new BlockzScene();
        } else if (selectedIndex2 == 2) {
            nextScene = new ChainScene();
        } else if (selectedIndex2 == 3) {
            nextScene = new WordScene();
        } else if (selectedIndex2 == 4) {
            nextScene = new MiniScene();
        } else if (selectedIndex2 == 5) {
            nextScene = new Title();
        } else {
            playError();
        }
    }
}

void MenuScene::draw(uint32_t tick) {
    cls();
    double progress = timer1 / 10.0;

    if (lastIndex1 == selectedIndex1) {
        int32_t i1 = lastIndex2 - 1 >= 0 ? lastIndex2 - 1 : stringVector2.size() - 1;
        int32_t i3 = lastIndex2 + 1 < stringVector2.size() ? lastIndex2 + 1 : 0;

        if (timer1 == 0 || bool2) {
            pen(5,5,5);
            btext_cx(stringVector2[i1], 16);
            pen(15,15,15);
            btext_cx(stringVector2[lastIndex2], 70);
            pen(5,5,5);
            btext_cx(stringVector2[i3], 112);
        } else {
            double height = 7;
            double yPos = 112;
            float currentYPos = 0;
            pen(5,5,5);

            if (bool1) { // pressed up
                currentYPos = yPos - (42 * progress);
                if (currentYPos < 70) currentYPos = 70;
                btext_cx(stringVector2[i3], currentYPos);

                yPos = 70;
                currentYPos = yPos - (54 * progress);
                if (currentYPos < 16) currentYPos = 16;
                btext_cx(stringVector2[lastIndex2], currentYPos);
            } else {
                yPos = 70;
                currentYPos = yPos + (42 * progress);
                if (currentYPos > 112) currentYPos = 112;
                btext_cx(stringVector2[lastIndex2], currentYPos);

                yPos = 16;
                currentYPos = yPos + (54 * progress);
                if (currentYPos > 70) currentYPos = 70;
                btext_cx(stringVector2[i1], currentYPos);
            }
        }
    }

    pen(2, 2, 2);
    frect(0, 0, 120, 13);
    draw_battery();

    pen(5, 5, 5);
    line(0, 52, 120, 52);
    line(0, 66, 120, 66);
    pen(10, 10, 10);
    frect(0, 54, 120, 11);

    pen(15, 15, 15);
    if (timer1 == 0 || !bool2) {
        btext_c(stringVector1[lastIndex1]);
    } else {
        double width = stringVector1[lastIndex1].size() * 6;
        double xPos = (120 - width)/2;
        
        double nextWidth = stringVector1[selectedIndex1].size() * 6;
        double nextXPos = (120 - nextWidth)/2;

        if (bool1) { // pressed right
            float currentXPos = (xPos * (1.0 - progress)) - (width * progress);
            if (currentXPos > xPos) currentXPos = xPos;
            btext_cy(stringVector1[lastIndex1], currentXPos);

            currentXPos = nextXPos + ((120 - nextXPos) * (1.0 - progress));
            if (currentXPos < nextXPos) currentXPos = nextXPos;
            btext_cy(stringVector1[selectedIndex1], currentXPos);
        } else {
            int32_t currentXPos = xPos + ((120 - xPos) * progress);
            if (currentXPos < xPos) currentXPos = xPos;
            btext_cy(stringVector1[lastIndex1], currentXPos);

            currentXPos = (nextXPos * (progress)) - (nextWidth * (1.0 - progress));
            if (currentXPos > nextXPos) currentXPos = nextXPos;
            btext_cy(stringVector1[selectedIndex1], currentXPos);
        }
    }

    pen(15, 15, 15);
    btext("PicoSystem", 58, 3);

    if (playingSong >= 0) {
        pen(15,15,15);
        window(0, 70, 120, 27);
        btext_cx("Now PLaying", 74);
        btext_cx(get_playing_song_name(), 86);
    }

    if (changingSetting) {
        pen(15,15,15);
        window(0, 70, 120, 28);
        arrow(4, 86, D_LEFT);
        arrow(111, 86, D_RIGHT);
        rect(10, 86, 99, 7);
        if (selectedIndex2 == 0) {
            btext_cx("Music Volume", 74);
            frect(11, 86, (float)volume * 0.98, 7);
        } else if (selectedIndex2 == 1) {
            btext_cx("SFX Volume", 74);
            frect(11, 86, (float)sfx_volume * 0.98, 7);
        } else if (selectedIndex2 == 2) {
            btext_cx("Backlight", 74);
            frect(11, 86, (float)backlightLevel * 0.98, 7);
        }
    }
}