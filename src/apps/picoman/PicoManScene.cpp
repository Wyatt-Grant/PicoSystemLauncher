#pragma once

#include "../Scene.cpp"
#include "../../helpers/Drawing.cpp"
#include "../../globals/Complex.cpp"
#include "../../globals/Basic.cpp"
#include "./PicoManSprites.cpp"
#include "../../audio/sfx.cpp"
#include "../../audio/music.cpp"
#include "PicoManScene.h"

//player vars
int32_t player_x;
int32_t player_y;
int32_t player_d;

int32_t ghosts;
std::vector<float> ghosts_x;
std::vector<float> ghosts_y;
std::vector<int32_t> ghosts_d;

//fuit vars
int32_t fruit_x;
int32_t fruit_y;
int32_t fruit;
bool show_fruit;
int32_t fruit_timer;

// power pellet
int32_t pp_index;
int32_t pp2_index;
int32_t power_mode;
int32_t power_mode_timer;

//game vars
int32_t ghost_timer;
int32_t start_delay_timer;
std::vector<int32_t> turns_x;
std::vector<int32_t> turns_y;
std::vector<std::vector<int32_t>> allowed_turns;
std::vector<int32_t> dots_x;
std::vector<int32_t> dots_y;
std::vector<bool> dots_collected;


PicoManScene::PicoManScene() : Scene() {
    playSong(0);
    cls();

    // player vars
    player_x = 56;
    player_y = 53;
    player_d = 4;

    //fuit vars
    fruit_x = 56;
    fruit_y = 53;
    fruit = 0;
    show_fruit = false;
    fruit_timer = 0;

    // power pellet
    pp_index = 0;
    pp2_index = 0;
    power_mode = false;
    power_mode_timer = 0;

    //game vars
    score = 0;
    lives = 3;
    ghost_timer = 0;
    start_delay_timer = 190;
    ghosts = 1;

    ghosts_x.assign({56, 56, 56, 56});
    ghosts_y.assign({70, 70, 70, 70});
    ghosts_d.assign({2, 2, 2, 2});

    turns_x.assign({
        4, 22, 50, 63, 91, 109,
        4, 22, 50, 63, 91, 109,
        35, 50, 63, 78,
        22, 35, 78, 91,
        35, 56, 78,
        4, 22, 35, 50, 63, 78, 91, 109,
        4, 22, 50, 63, 91, 109,
    });
    turns_y.assign({
        17, 17, 17, 17, 17, 17,
        40, 40, 40, 40, 40, 40,
        53, 53, 53, 53,
        68, 68, 68, 68,
        83, 83, 83,
        96, 96, 96, 96, 96, 96, 96, 96,
        109, 109, 109, 109, 109, 109
    });
    allowed_turns.assign({
        {D_DOWN, D_RIGHT},{D_LEFT, D_RIGHT, D_DOWN},{D_LEFT, D_DOWN},{D_DOWN, D_RIGHT},{D_LEFT, D_RIGHT, D_DOWN},{D_LEFT, D_DOWN},
        {D_UP, D_RIGHT},{D_UP, D_DOWN, D_LEFT, D_RIGHT},{D_UP, D_DOWN, D_LEFT},{D_UP, D_DOWN, D_RIGHT},{D_UP, D_DOWN, D_LEFT, D_RIGHT},{D_UP, D_LEFT},
        {D_DOWN, D_RIGHT},{D_UP, D_LEFT, D_RIGHT},{D_UP, D_LEFT, D_RIGHT},{D_DOWN, D_LEFT},
        {D_UP, D_DOWN, D_LEFT, D_RIGHT},{D_UP, D_DOWN, D_LEFT},{D_UP, D_DOWN, D_RIGHT},{D_UP, D_DOWN, D_LEFT, D_RIGHT},
        {D_UP, D_DOWN, D_RIGHT},{D_RIGHT, D_LEFT},{D_UP, D_DOWN, D_LEFT},
        {D_DOWN, D_RIGHT},{D_UP, D_DOWN, D_LEFT, D_RIGHT},{D_UP, D_LEFT, D_RIGHT},{D_DOWN, D_LEFT},{D_DOWN, D_RIGHT},{D_UP, D_LEFT, D_RIGHT},{D_UP, D_DOWN, D_LEFT, D_RIGHT},{D_DOWN, D_LEFT},
        {D_UP, D_RIGHT},{D_UP, D_LEFT, D_RIGHT},{D_UP, D_LEFT, D_RIGHT},{D_UP, D_LEFT, D_RIGHT},{D_UP, D_LEFT, D_RIGHT},{D_UP, D_LEFT}
    });
    dots_x.assign({
        6, 15, 24, 33, 42, 52, 65, 75, 84, 93, 102, 111,
        6, 24, 52, 65, 93, 111,
        6, 24, 52, 65, 93, 111,
        6, 15, 24, 33, 42, 52, 65, 75, 84, 93, 102, 111,
        24, 52, 65, 93,
        24, 37, 45, 52, 59, 65, 73, 80, 93,
        24, 37, 80, 93,
        9, 17, 24, 31, 37, 80, 86, 93, 100, 108,
        24, 37, 80, 93,
        24, 37, 45, 52, 59, 65, 73, 80, 93,
        24, 37, 80, 93,
        6, 15, 24, 31, 37, 45, 52, 65, 73, 80, 87, 93, 102, 111,
        6, 24, 52, 65, 93, 111,
        6, 15, 24, 31, 37, 45, 52, 59, 65, 73, 80, 87, 93, 102, 111
    });
    dots_y.assign({
        19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
        27, 27, 27, 27, 27, 27,
        34, 34, 34, 34, 34, 34,
        42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42, 42,
        49, 49, 49, 49,
        55, 55, 55, 55, 55, 55, 55, 55, 55,
        63, 63, 63, 63,
        70, 70, 70, 70, 70, 70, 70, 70, 70, 70,
        78, 78, 78, 78,
        85, 85, 85, 85, 85, 85, 85, 85, 85,
        91, 91, 91, 91,
        98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98,
        104, 104, 104, 104, 104, 104,
        111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111
    });
    dots_collected.assign({
        false, false, false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false,
        false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false, false, false,
        false, false, false, false,
        false, false, false, false, false, false, false, false, false,
        false, false, false, false,
        false, false, false, false, false, false, false, false, false, false,
        false, false, false, false,
        false, false, false, false, false, false, false, false, false,
        false, false, false, false,
        false, false, false, false, false, false, false, false, false, false, false, false, false, false,
        false, false, false, false, false, false,
        false, false, false, false, false, false, false, false, false, false, false, false, false, false, false
    });


    pp_index = rand() % dots_collected.size();
    do {
        pp2_index = rand() % dots_collected.size();
    } while(pp_index == pp2_index);
}

PicoManScene::~PicoManScene() {

}

std::vector<int32_t> get_possible_turns(int32_t x, int32_t y) {
    for (int32_t i = 0; i < turns_x.size(); i++) {
        if (x == turns_x[i] && y == turns_y[i]) {
            return allowed_turns[i];
        }
    }
    
    return {};
}

void handle_player_input() {
    std::vector<int32_t> turns = get_possible_turns(player_x, player_y);
    if (turns.size() > 0) {
        if (button(UP) || button(X)) {
            for (int32_t i = 0; i < turns.size(); i++) {
                if (turns[i] == D_UP) {
                    player_d = D_UP;
                }
            }
        } else if (button(DOWN) || button(B)) {
            for (int32_t i = 0; i < turns.size(); i++) {
                if (turns[i] == D_DOWN) {
                    player_d = D_DOWN;
                }
            }
        } else if (button(LEFT) || button(Y)) {
            for (int32_t i = 0; i < turns.size(); i++) {
                if (turns[i] == D_LEFT) {
                    player_d = D_LEFT;
                }
            }
        } else if (button(RIGHT) || button(A)) {
            for (int32_t i = 0; i < turns.size(); i++) {
                if (turns[i] == D_RIGHT) {
                    player_d = D_RIGHT;
                }
            }
        }
    } else {
        if ((button(UP) || button(X)) && player_d == D_DOWN) {
            player_d = D_UP;
        }
        if ((button(DOWN) || button(B)) && player_d == D_UP) {
            player_d = D_DOWN;
        }
        if ((button(LEFT) || button(Y)) && player_d == D_RIGHT) {
            player_d = D_LEFT;
        }
        if ((button(RIGHT) || button(A)) && player_d == D_LEFT) {
            player_d = D_RIGHT;
        }
    }
}

void handle_player_movement() {
    std::vector<int32_t> turns = get_possible_turns(player_x, player_y);
    bool isCurrentDirValid = true;

    if (turns.size() > 0) {
        isCurrentDirValid = false;
        for (int32_t i = 0; i < turns.size(); i++) {
            if (player_d == turns[i]) {
                isCurrentDirValid = true;
            }
        }
    }

    if (player_y == 68 && player_x == 0) {
        player_x = 113;
        player_d = D_LEFT;
    } else if (player_y == 68 && player_x == 113) {
        player_x = 0;
        player_d = D_RIGHT;
    }

    if (isCurrentDirValid) {
        switch (player_d) {
            case D_UP:
                if (player_y > 17) player_y--;
                break;
            case D_DOWN:
                if (player_y < 109) player_y++;
                break;
            case D_LEFT:
                if (player_x > 4 || player_y == 68) player_x--;
                break;
            case D_RIGHT:
                if (player_x < 109 || player_y == 68) player_x++;
                break;
        }
    }
}

void handle_ghost_movement(uint32_t tick) {
    ghost_timer++;
    if (ghost_timer > 300 && ghosts < 4) {
        ghosts++;
        ghost_timer = 0;
    }

    for (size_t g = 0; g < ghosts; g++) {
        std::vector<int32_t> turns = get_possible_turns(ghosts_x[g], ghosts_y[g]);
        bool isCurrentDirValid = true;

        if (turns.size() > 0) {
            isCurrentDirValid = false;
            for (int32_t i = 0; i < turns.size(); i++) {
                if (ghosts_d[g] == turns[i]) {
                    isCurrentDirValid = true;
                }
            }
        }

        if ((int32_t)ghosts_y[g] == 68 && (int32_t)ghosts_x[g] <= 0) {
            ghosts_x[g] = 113;
            ghosts_d[g] = D_LEFT;
        } else if ((int32_t)ghosts_y[g] == 68 && (int32_t)ghosts_x[g] >= 113) {
            ghosts_x[g] = 0;
            ghosts_d[g] = D_RIGHT;
        }

        if (turns.size() > 0) {
            for (auto it = turns.begin(); it != turns.end(); ++it) {
                if (ghosts_d[g] == D_DOWN && *it == D_UP) {
                    turns.erase(it);
                    break;
                } else if (ghosts_d[g] == D_UP && *it == D_DOWN) {
                    turns.erase(it);
                    break;
                } else if (ghosts_d[g] == D_RIGHT && *it == D_LEFT) {
                    turns.erase(it);
                    break;
                } else if (ghosts_d[g] == D_LEFT && *it == D_RIGHT) {
                    turns.erase(it);
                    break;
                }
            }

            ghosts_d[g] = turns[rand() % turns.size()];
            isCurrentDirValid = true;
        }

        if (isCurrentDirValid) {
            float speed = power_mode ? .4 : .75;
            switch (ghosts_d[g]) {
                case D_UP:
                    if (ghosts_y[g] > 17) ghosts_y[g] -= speed;
                    break;
                case D_DOWN:
                    if (ghosts_y[g] < 109) ghosts_y[g] += speed;
                    break;
                case D_LEFT:
                    if (ghosts_x[g] > 4 || (int32_t)ghosts_y[g] == 68) ghosts_x[g] -= speed;
                    break;
                case D_RIGHT:
                    if (ghosts_x[g] < 109 || (int32_t)ghosts_y[g] == 68) ghosts_x[g] += speed;
                    break;
            }
        }
    }
}

void handle_ghost_Collision(uint32_t tick) {
    bool hit = false;
    for (size_t g = 0; g < ghosts; g++) {
        if (abs(ghosts_y[g] - player_y) <= 2 && abs(ghosts_x[g] - player_x) <= 2) {
            if (power_mode) {
                ghosts_x[g] = 56;
                ghosts_y[g] = 70;
                ghosts_d[g] = 2;
                clear_area(ghosts_x[g]-5,ghosts_y[g]-5,17,17);
                playTick();
            } else {
                hit = true;
                playError();
                clear_area(player_x-5,player_y-5,17,17);
                lives--;
            }
        }
    }
    if (hit) {
        for (size_t g = 0; g < ghosts; g++) {
            clear_area(ghosts_x[g]-5,ghosts_y[g]-5,17,17);
            ghosts_x[g] = 56;
            ghosts_y[g] = 70;
            ghosts_d[g] = 2;
        }
        ghosts = 1;
        ghost_timer = 0;
        start_delay_timer = 40;
    }
}

void handle_dots() {
    for (int32_t i = 0; i < dots_collected.size(); i++) {
        if (player_x+2 == dots_x[i] && player_y+2 == dots_y[i] && !dots_collected[i]) {
            dots_collected[i] = true;
            playTick();
            score += 10;
            if (pp_index == i) {
                power_mode = true;
            }
            if (pp2_index == i) {
                power_mode = true;
            }
        }
    }
}

void handle_fruit() {
    if (!show_fruit) fruit_timer++;
    if (fruit_timer > 500) show_fruit = true;
    if (player_x == fruit_x && player_y == fruit_y && show_fruit) {
        show_fruit = false;
        score += 250;
        fruit_timer = 0;
        fruit = rand() % 5;
        playTick();
    }
}

void handle_refille_dots() {
    bool all_true = true;
    for (bool dot_collected : dots_collected) {
        if (!dot_collected) {
            all_true = false;
            break;
        }
    }
    if (all_true) {
        std::fill(dots_collected.begin(), dots_collected.end(), false);
        pp_index = rand() % dots_collected.size();
        do {
            pp2_index = rand() % dots_collected.size();
        } while(pp_index == pp2_index);
    }
}

void PicoManScene::update(uint32_t tick) {
    if (start_delay_timer > 0) {
        start_delay_timer--;
        return;
    }
    stopSong();

    if (power_mode) {
        power_mode_timer++;
    }
    if (power_mode_timer > 260) {
        power_mode = false;
        power_mode_timer = 0;
    }

    handle_fruit();
    handle_refille_dots();
    handle_player_input();
    handle_ghost_movement(tick);
    if (lives >= 0) {
        handle_player_movement();
        handle_dots();
        handle_ghost_Collision(tick);
    }
}

void PicoManScene::draw(uint32_t tick) {
    buffer_t *sprites = buffer(120, 120, (void *)sheet);

    clear_area(0,0,120,12);
    clear_area(player_x-5,player_y-5,17,17);
    clear_area(0,68,7,7);
    clear_area(113,68,7,7);
    for (size_t g = 0; g < ghosts; g++) {
        clear_area(ghosts_x[g]-5,ghosts_y[g]-5,17,17);
    }

    bblit(sprites, 0, 13, 120, 107, 0, 13);

    for (int32_t i = 0; i < dots_x.size(); i++) {
        if (!dots_collected[i]) {
            if (pp_index == i) {
                fcircle(dots_x[i] + 1, dots_y[i] + 1, 2.5);
            } else if (pp2_index == i) {
                fcircle(dots_x[i] + 1, dots_y[i] + 1, 2.5);
            } else {
                pixel(dots_x[i] + 1, dots_y[i] + 1);
            }
        }
    }

    if (show_fruit) {
        bblit(sprites, 84 + (fruit * 7), 0, 7, 7, fruit_x, fruit_y);
    }

    for (size_t g = 0; g < ghosts; g++) {
        if (!power_mode) {
            bblit(sprites, 35 + (g*7), 0, 7, 7, ghosts_x[g], ghosts_y[g]);
        } else {
            if (power_mode_timer >= 200) {
                if (tick % 10 > 5) {
                    bblit(sprites, 35 + (g*7), 0, 7, 7, ghosts_x[g], ghosts_y[g]);
                } else {
                    bblit(sprites, 63, 0, 7, 7, ghosts_x[g], ghosts_y[g]);
                }
            } else {
                bblit(sprites, 63, 0, 7, 7, ghosts_x[g], ghosts_y[g]);
            }
        }
    }

    if (lives >= 0) {
        int32_t player_frame = tick % 20 > 10 ? 0 : 7 * player_d;
        bblit(sprites, player_frame, 0, 7, 7, player_x, player_y);
    }

    if (lives >= 0) {
        for (size_t i = 1; i <= lives; i++){
            bblit(sprites, 28, 0, 7, 7, 119 - (8*i), 2);
        }
    } else {
        text("GAME OVER", 66, 2);
    }

    pen(15,15,15);
    text(str(score), 2, 2);
    // text(str(dots_collected.size()), 2, 2);
    // text(str(dots_x.size()), 32, 2);
    // text(str(dots_y.size()), 62, 2);
    
    delete sprites;
}