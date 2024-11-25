#pragma once

#include "./data.cpp"
#include "./tileset.cpp"
#include "./maps/demo.cpp"
#include "../../helpers/Drawing.cpp"

using namespace picosystem;

class TileMap {
    public:
        TileMap(Vector& camera);

        void update(uint32_t tick);
        void draw(uint32_t tick, int32_t layer);
        bool isPlayerInGrass();

    private:
        Vector& cam;

        buffer_t* getTileset(int32_t tile);
        void drawTile(int32_t tile, int32_t dx, int32_t dy);
        void drawMap(int32_t layer);
};

buffer_t* TileMap::getTileset(int32_t tile) {
    switch((tile / 64) + 1) {
        case 1:  return buffer(128, 128, (void *)tileset_1_data);
        case 2:  return buffer(128, 128, (void *)tileset_2_data);
        case 3:  return buffer(128, 128, (void *)tileset_3_data);
        case 4:  return buffer(128, 128, (void *)tileset_4_data);
        case 5:  return buffer(128, 128, (void *)tileset_5_data);
    }

    return buffer(128, 128, (void *)tileset_1_data);
}

void TileMap::drawTile(int32_t tile, int32_t dx, int32_t dy) {
    if (tile >= (tile / 64) * 64) {
        buffer_t* temp = getTileset(tile);
        tile -= ((tile / 64) * 64);

        int sx = (tile % 8) * 16;
        int sy = (tile / 8) * 16;
        bblit(temp, sx, sy, 16, 16, dx, dy);

        delete temp;
    }
}

void TileMap::drawMap(int32_t layer) {
    for (int32_t y = 0; y < 10; y++) {
        for (int32_t x = 0; x < 10; x++) {
            int32_t xTileOffset = x + (cam.x / 16);
            int32_t yTileOffset = y + (cam.y / 16);

            if (xTileOffset >= 100
            || yTileOffset >= 64
            || xTileOffset < 0
            || yTileOffset < 0) {
                continue;
            }

            int32_t dx = (x * 16) - (cam.x % 16);
            int32_t dy = (y * 16) - (cam.y % 16);

            if (layer == 1) {
                drawTile(demo_layer1[yTileOffset][xTileOffset], dx, dy);
                if (x < 3 || x > 5 || y < 3 || y > 5) {
                    drawTile(demo_layer2[yTileOffset][xTileOffset], dx, dy);
                }
            }
            if (layer == 2 && x >= 3 && x <= 5 && y >=3 && y <= 5){
                drawTile(demo_layer2[yTileOffset][xTileOffset], dx, dy);
            }
        }
    }
}

TileMap::TileMap(Vector& camera) : cam(camera) {
    
}

void TileMap::update(uint32_t tick) {
    
}

void TileMap::draw(uint32_t tick, int32_t layer) {
    drawMap(layer);
}