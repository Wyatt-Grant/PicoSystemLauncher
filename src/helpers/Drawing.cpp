#pragma once

#include "picosystem.hpp"
#include "../globals/Constants.cpp"

using namespace picosystem;

/**
 * blit within the bounds of the screen.
 *
 * improves performance by simply not blitting outside the screen bounds.
 *
 * @param src Image Source
 * @param sx Souce X
 * @param sy Souce Y
 * @param w Width
 * @param h Height
 * @param dx Destination X
 * @param dy Destination Y
 * 
 * @return void.
 */
void bblit(buffer_t *src, int32_t sx, int32_t sy, int32_t w, int32_t h, int32_t dx, int32_t dy) {
    if (dx < 0) {
        sx += -dx;
        dx = 0;
    } else if ((dx + w) >= 120) {
        w = 120 - dx;
    }

    if (dy < 0) {
        sy += -dy;
        dy = 0;
    } else if ((dy + h) >= 120) {
        h = 120 - dy;
    }

    blit(src, sx, sy, w, h, dx, dy);
}

/**
 * sets pen to black and calls clear. then sets pen back to the previous color.
 * 
 * @return void.
 */
void cls() {
    color_t prev_pen_color = _pen;
    pen(0,0,0);
    clear();
    pen(prev_pen_color);
}

/**
 * sets pen to black and calls clear. then sets pen back to the previous color.
 * 
 * @return void.
 */
void clear_area(int32_t x, int32_t y, int32_t w, int32_t h) {
    color_t prev_pen_color = _pen;
    pen(0,0,0);
    frect(x, y, w, h);
    pen(prev_pen_color);
}

/**
 * draw window
 *
 * @param x X
 * @param y Y
 * @param w Width
 * @param h Height
 * 
 * @return void.
 */
void window(int32_t x, int32_t y, int32_t w, int32_t h) {
    color_t prev_pen_color = _pen;

    pen(2,2,2);
    frect(x+1,y+1,w-2,h-2);

    pen(prev_pen_color);
    line(x+2, y, x+w-2, y);
    pixel(x+1,y+1);
    pixel(x+w-2,y+1);
    line(x+3, y+2, x+w-3, y+2);

    line(x, y+2, x, y+h-2);
    line(x+w-1, y+2, x+w-1, y+h-2);
    line(x+2, y+3, x+2, y+h-3);
    line(x+w-3, y+3, x+w-3, y+h-3);

    line(x+3, y+h-3, x+w-3, y+h-3);
    pixel(x+1,y+h-2);
    pixel(x+w-2,y+h-2);
    line(x+2, y+h-1, x+w-2, y+h-1);
}

/**
 * draw right pointing cursor (default to right)
 *
 * @param x X
 * @param y Y
 * @param w Width
 * @param h Height
 * 
 * @return void.
 */
void arrow(int32_t x, int32_t y, int32_t d = 4) {
    switch (d) {
        case D_UP:
            line(x,y+3,x+7,y+3);
            line(x+1,y+2,x+6,y+2);
            line(x+2,y+1,x+5,y+1);
            pixel(x+3,y);
            break;
        case D_DOWN:
            line(x,y,x+7,y);
            line(x+1,y+1,x+6,y+1);
            line(x+2,y+2,x+5,y+2);
            pixel(x+3,y+3);
            break;
        case D_LEFT:
            line(x+3,y,x+3,y+7);
            line(x+2,y+1,x+2,y+6);
            line(x+1,y+2,x+1,y+5);
            pixel(x,y+3);
            break;
        case D_RIGHT:
            line(x,y,x,y+7);
            line(x+1,y+1,x+1,y+6);
            line(x+2,y+2,x+2,y+5);
            pixel(x+3,y+3);
            break;
    }
}

/**
 * better text - adds more options to text
 * 
 * @param s string to display
 * @param x x coordinate
 * @param y y coordinate
 * @param flash should text flash
 * @param tick current game tick
 * 
 * @return void.
 */
void btext(std::string s, int32_t x, int32_t y, bool flash = false, uint32_t tick = 0) {    
    if ((flash && tick % 40 >= 20) || !flash) {
        text(s, x, y);
    }
}
void btext_cy(std::string s, int32_t x, bool flash = false, uint32_t tick = 0) {    
    btext(s, x, (120 - 8)/2, flash, tick);
}
void btext_cx(std::string s, int32_t y, bool flash = false, uint32_t tick = 0) {    
    btext(s, (120 - (s.size() * 6))/2, y, flash, tick);
}
void btext_c(std::string s, bool flash = false, uint32_t tick = 0) {    
    btext(s, (120 - (s.size() * 6))/2, (120 - 8)/2, flash, tick);
}

/**
 * draw battery indicator
 * 
 * @return void.
 */
void draw_battery() {
    int32_t bat = battery();

    pen(2,12,2);
    frect(3,2,(100/bat) * 18.0,8);

    pen(0,15,0);
    vline(22,5,3);
    vline(2,3,7);
    hline(3,2,18);
    vline(21,3,7);
    hline(3,10,18);

    pen(0,4,0);
    text(str(bat),3,3);
}