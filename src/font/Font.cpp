#pragma once

#include "picosystem.hpp"

using namespace picosystem;

const uint8_t custom_font[96][9] = {
  {3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, //  
  {1, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x80, 0x00}, // !
  {3, 0xa0, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // "
  {5, 0x50, 0x50, 0xf8, 0x50, 0xf8, 0x50, 0x50, 0x00}, // #
  {5, 0x20, 0x78, 0xa0, 0x70, 0x28, 0xf0, 0x20, 0x00}, // $
  {5, 0xc0, 0xc8, 0x10, 0x20, 0x40, 0x98, 0x18, 0x00}, // %
  {5, 0x70, 0x90, 0xa0, 0x40, 0xa8, 0x90, 0x68, 0x00}, // &
  {1, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // '
  {3, 0x20, 0x40, 0x80, 0x80, 0x80, 0x40, 0x20, 0x00}, // (
  {3, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00}, // )
  {5, 0x00, 0xa8, 0x70, 0xf8, 0x70, 0xa8, 0x00, 0x00}, // *
  {5, 0x00, 0x20, 0x20, 0xf8, 0x20, 0x20, 0x00, 0x00}, // +
  {2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x80, 0x00}, // .
  {5, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00}, // -
  {1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00}, // ,
  {5, 0x00, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00}, // /
  {5, 0x70, 0x88, 0x98, 0xa8, 0xc8, 0x88, 0x70, 0x00}, // 0
  {5, 0x20, 0x60, 0xa0, 0x20, 0x20, 0x20, 0xf8, 0x00}, // 1
  {5, 0x70, 0x88, 0x08, 0x10, 0x20, 0x40, 0xf8, 0x00}, // 2
  {5, 0x70, 0x88, 0x08, 0x30, 0x08, 0x88, 0x70, 0x00}, // 3
  {5, 0x30, 0x50, 0x90, 0xf8, 0x10, 0x10, 0x10, 0x00}, // 4
  {5, 0xf8, 0x80, 0x80, 0xf0, 0x08, 0x08, 0xf0, 0x00}, // 5
  {5, 0x70, 0x80, 0x80, 0xf0, 0x88, 0x88, 0x70, 0x00}, // 6
  {5, 0xf8, 0x08, 0x10, 0x20, 0x40, 0x40, 0x40, 0x00}, // 7
  {5, 0x70, 0x88, 0x88, 0x70, 0x88, 0x88, 0x70, 0x00}, // 8
  {5, 0x70, 0x88, 0x88, 0x78, 0x08, 0x08, 0x70, 0x00}, // 9
  {1, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00}, // :
  {1, 0x00, 0x80, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00}, // ;
  {3, 0x00, 0x20, 0x40, 0x80, 0x40, 0x20, 0x00, 0x00}, // <
  {4, 0x00, 0x00, 0xf0, 0x00, 0xf0, 0x00, 0x00, 0x00}, // =
  {3, 0x00, 0x80, 0x40, 0x20, 0x40, 0x80, 0x00, 0x00}, // >
  {5, 0x70, 0x88, 0x88, 0x10, 0x20, 0x00, 0x20, 0x00}, // ?
  {5, 0x70, 0x88, 0xb8, 0xa8, 0xb8, 0x80, 0x70, 0x00}, // @
  {5, 0x70, 0x88, 0x88, 0xf8, 0x88, 0x88, 0x88, 0x00}, // A
  {5, 0xf0, 0x88, 0x88, 0xf0, 0x88, 0x88, 0xf0, 0x00}, // B
  {5, 0x70, 0x88, 0x80, 0x80, 0x80, 0x88, 0x70, 0x00}, // C
  {5, 0xf0, 0x88, 0x88, 0x88, 0x88, 0x88, 0xf0, 0x00}, // D
  {5, 0xf8, 0x80, 0x80, 0xf0, 0x80, 0x80, 0xf8, 0x00}, // E
  {5, 0xf8, 0x80, 0x80, 0xf0, 0x80, 0x80, 0x80, 0x00}, // F
  {5, 0x70, 0x88, 0x80, 0x80, 0x98, 0x88, 0x70, 0x00}, // G
  {5, 0x88, 0x88, 0x88, 0xf8, 0x88, 0x88, 0x88, 0x00}, // H
  {5, 0xf8, 0x20, 0x20, 0x20, 0x20, 0x20, 0xf8, 0x00}, // I
  {5, 0xf8, 0x08, 0x08, 0x08, 0x08, 0x88, 0x70, 0x00}, // J
  {5, 0x88, 0x88, 0x90, 0xe0, 0x90, 0x88, 0x88, 0x00}, // K
  {5, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xf8, 0x00}, // L
  {5, 0x88, 0xd8, 0xa8, 0x88, 0x88, 0x88, 0x88, 0x00}, // M
  {5, 0x88, 0x88, 0xc8, 0xa8, 0x98, 0x88, 0x88, 0x00}, // N
  {5, 0x70, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00}, // O
  {5, 0xf0, 0x88, 0x88, 0xf0, 0x80, 0x80, 0x80, 0x00}, // P
  {5, 0x70, 0x88, 0x88, 0x88, 0xa8, 0x90, 0x68, 0x00}, // Q
  {5, 0xf0, 0x88, 0x88, 0xf0, 0x88, 0x88, 0x88, 0x00}, // R
  {5, 0x78, 0x80, 0x80, 0x70, 0x08, 0x08, 0xf0, 0x00}, // S
  {5, 0xf8, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00}, // T
  {5, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x70, 0x00}, // U
  {5, 0x88, 0x88, 0x88, 0x88, 0x88, 0x50, 0x20, 0x00}, // V
  {5, 0x88, 0x88, 0x88, 0x88, 0xa8, 0xd8, 0x88, 0x00}, // W
  {5, 0x88, 0x88, 0x50, 0x20, 0x50, 0x88, 0x88, 0x00}, // X
  {5, 0x88, 0x88, 0x50, 0x20, 0x20, 0x20, 0x20, 0x00}, // Y
  {5, 0xf8, 0x08, 0x10, 0x20, 0x40, 0x80, 0xf8, 0x00}, // Z
  {2, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0xc0, 0x00}, // [
  {5, 0x00, 0x80, 0x40, 0x20, 0x10, 0x08, 0x00, 0x00}, // 
  {2, 0xc0, 0x40, 0x40, 0x40, 0x40, 0x40, 0xc0, 0x00}, // ]
  {3, 0x40, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ^
  {6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0x00}, // _
  {2, 0x80, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // `
  {5, 0x00, 0x00, 0x70, 0x08, 0x78, 0x88, 0x78, 0x00}, // a
  {5, 0x80, 0x80, 0xf0, 0x88, 0x88, 0x88, 0xf0, 0x00}, // b
  {5, 0x00, 0x00, 0x70, 0x88, 0x80, 0x88, 0x70, 0x00}, // c
  {5, 0x08, 0x08, 0x78, 0x88, 0x88, 0x88, 0x78, 0x00}, // d
  {5, 0x00, 0x00, 0x70, 0x88, 0xf8, 0x80, 0x78, 0x00}, // e
  {5, 0x30, 0x40, 0xf8, 0x40, 0x40, 0x40, 0x40, 0x00}, // f
  {5, 0x00, 0x00, 0x78, 0x88, 0x78, 0x08, 0x70, 0x00}, // g
  {5, 0x80, 0x80, 0xf0, 0x88, 0x88, 0x88, 0x88, 0x00}, // h
  {5, 0x20, 0x00, 0xe0, 0x20, 0x20, 0x20, 0xf8, 0x00}, // i
  {5, 0x08, 0x00, 0x38, 0x08, 0x08, 0x88, 0x70, 0x00}, // j
  {5, 0x80, 0x80, 0x90, 0xe0, 0x90, 0x88, 0x88, 0x00}, // k
  {4, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x30, 0x00}, // l
  {5, 0x00, 0x00, 0xd0, 0xa8, 0xa8, 0x88, 0x88, 0x00}, // m
  {5, 0x00, 0x00, 0xf0, 0x88, 0x88, 0x88, 0x88, 0x00}, // n
  {5, 0x00, 0x00, 0x70, 0x88, 0x88, 0x88, 0x70, 0x00}, // o
  {5, 0x00, 0x00, 0xf0, 0x88, 0xf0, 0x80, 0x80, 0x00}, // p
  {5, 0x00, 0x00, 0x78, 0x88, 0x78, 0x08, 0x08, 0x00}, // q
  {5, 0x00, 0x00, 0xb0, 0xc8, 0x80, 0x80, 0x80, 0x00}, // r
  {5, 0x00, 0x00, 0x78, 0x80, 0x70, 0x08, 0xf0, 0x00}, // s
  {5, 0x40, 0x40, 0xf0, 0x40, 0x40, 0x48, 0x30, 0x00}, // t
  {5, 0x00, 0x00, 0x88, 0x88, 0x88, 0x88, 0x78, 0x00}, // u
  {5, 0x00, 0x00, 0x88, 0x88, 0x88, 0x50, 0x20, 0x00}, // v
  {5, 0x00, 0x00, 0x88, 0x88, 0x88, 0xa8, 0x50, 0x00}, // w
  {5, 0x00, 0x00, 0x88, 0x50, 0x20, 0x50, 0x88, 0x00}, // x
  {5, 0x00, 0x00, 0x88, 0x88, 0x78, 0x08, 0x70, 0x00}, // y
  {5, 0x00, 0x00, 0xf8, 0x10, 0x20, 0x40, 0xf8, 0x00}, // z
  {3, 0x20, 0x40, 0x40, 0x80, 0x40, 0x40, 0x20, 0x00}, // {
  {1, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00}, // |
  {3, 0x80, 0x40, 0x40, 0x20, 0x40, 0x40, 0x80, 0x00}, // }
  {5, 0x00, 0x00, 0x48, 0xb0, 0x00, 0x00, 0x00, 0x00}, // ~
  {0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // 
};
uint8_t *_custom_font = (uint8_t *)&custom_font[0][0];