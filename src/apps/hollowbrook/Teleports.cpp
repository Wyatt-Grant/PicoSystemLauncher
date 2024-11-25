#pragma once

#include "picosystem.hpp"
#include "../../helpers/Drawing.cpp"
#include "data.cpp"

using namespace picosystem;

class Teleports {
    public:
        Teleports(Vector& camera);

        void update(uint32_t tick);
        void draw(uint32_t tick);

    private:
        Vector& cam;
        bool teleporting = false;
};

Teleports::Teleports(Vector& camera) : cam(camera) {
    
}

void Teleports::update(uint32_t tick) {
    int32_t _x = cam.x;
    int32_t _y = cam.y;

    // house 1
    if (cam.x == 204 && cam.y == 316) cam = { 1036, 92 };
    if (cam.x == 1036 && cam.y == 108) cam = { 204, 332 };
    if (cam.x == 1020 && cam.y == 108) cam = { 204, 332 };

    // house 2
    if (cam.x == 620 && cam.y == 364) cam = { 1356, 92 };
    if (cam.x == 1356 && cam.y == 108) cam = { 620, 380 };
    if (cam.x == 1372 && cam.y == 108) cam = { 620, 380 };

    // house 3
    if (cam.x == 572 && cam.y == 156) cam = { 1020, 284 };
    if (cam.x == 1020 && cam.y == 300) cam = { 572, 172 };
    if (cam.x == 1036 && cam.y == 300) cam = { 572, 172 };

    // manor
    if (cam.x == 60 && cam.y == 92) cam = { 1036, 524 };
    if (cam.x == 1020 && cam.y == 540) cam = { 60, 108 };
    if (cam.x == 1036 && cam.y == 540) cam = { 60, 108 };

    // library
    if (cam.x == 92 && cam.y == 572) cam = { 1356, 284 };
    if (cam.x == 1340 && cam.y == 300) cam = { 92, 588 };
    if (cam.x == 1356 && cam.y == 300) cam = { 92, 588 };

    // cata-comb
    if (cam.x == 604 && cam.y == 540) cam = { 1388, 652 };
    if (cam.x == 1388 && cam.y == 668) cam = { 604, 556 };

    teleporting = _x != cam.x || _y != cam.y;
}

void Teleports::draw(uint32_t tick) {
    if (teleporting) {
        cls();
    }
}