#pragma once

#include "./TileMap.cpp"
#include "./Player.cpp"
#include "./Message.cpp"
#include "./NPCs.cpp"
#include "./Teleports.cpp"

using namespace picosystem;

class MainGame : public Scene {
public:
    MainGame();
    ~MainGame();

    void update(uint32_t tick) override;
    void draw(uint32_t tick) override;

private:
    Player* player;
    TileMap* tileMap;
    Message* message;
    NPCs* npcs;
    bool titleScreen;
    bool menuIsOpen;
    int32_t menuIndex;
    Teleports* teleports;
};
