#pragma once

#include "picosystem.hpp"

using namespace picosystem;

const int32_t DIR_UP = 0;
const int32_t DIR_DOWN = 1;
const int32_t DIR_LEFT = 2;
const int32_t DIR_RIGHT = 3;

struct Vector {
    int32_t x;
    int32_t y;
};

struct NPC {
    Vector pos;
    int32_t overworld;
    int32_t dir;
    std::string message;
};

struct Item {
    int32_t number;
    int32_t count;
};

struct KeyItem {
    int32_t number;
};

const std::string item_names[16] = {
    "Vitality Elixir",          // heals 15%
    "Renewal Elixir",           // heals 35%
    "Rejuvenate Elixir",        // heals 60%
    "Sacred Elixir",            // heals 100%

    "Dreamcatcher",             // cures sleep status
    "Herbal Antitoxin",         // cures poison status
    "Cooling Salve",            // cures burn status

    "Wonder Tonic",             // heals 100% and cures all statuses
    
    "Crimson XP Gem",           // gives 500 xp to pimon
    "Amber XP Gem",             // gives 2500 xp to pimon
    "Indigo XP Gem",            // gives 10000 xp to pimon

    "Coconut Macaroon",         // boost UNQ pow by 1
    "Lemon Tart",               // boost UNQ def by 1
    "Blueberry Cobbler",        // boost UNQ ele by 1
    "Peach Sorbet",             // boost UNQ spd by 1
    "Cherry Cheesecake",        // boost UNQ hp by 1
};

const std::string item_desc[16] = {
    "Heals 15 percent of PiMon's HP.",
    "Heals 35 percent of PiMon's HP.",
    "Heals 60 percent of PiMon's HP.",
    "Fully Heals PiMon's HP.",

    "Wakes PiMon up and removes PiMon's Sleep status.",
    "Removes PiMon's Poison status.",
    "Removes PiMon's Burn status.",

    "Completely restores PiMon. Fully Heals HP and all statuses.",
    
    "Gives PiMon 500 XP.",
    "Gives PiMon 2500 XP.",
    "Gives PiMon 10000 XP.",

    "boost UNQ pow by 1 (to a max of 50)",
    "boost UNQ def by 1 (to a max of 50)",
    "boost UNQ ele by 1 (to a max of 50)",
    "boost UNQ spd by 1 (to a max of 50)",
    "boost UNQ hp by 1 (to a max of 50)"
};

const std::string key_item_names[3] = {
    "Axe",
    "Boat",
    "Hammer",
};

const std::string key_item_desc[3] = {
    "Can cut down small trees.",
    "Allows travel on water",
    "Can break small rocks",
};