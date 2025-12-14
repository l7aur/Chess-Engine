#pragma once

#include "raylib.h"

class Config {
private:
    inline static const unsigned int SPRITE_WIDTH  = 32; // pixels
    inline static const unsigned int SPRITE_HEIGHT = 32; // pixels

public:
    inline static const unsigned int NUMBER_OF_ROWS = 8;
    inline static const unsigned int NUMBER_OF_COLUMNS = 8;
    inline static const unsigned int DISPLAY_WINDOW_WIDTH  = SPRITE_WIDTH * NUMBER_OF_COLUMNS * 2; // pixels
    inline static const unsigned int DISPLAY_WINDOW_HEIGHT = SPRITE_HEIGHT * NUMBER_OF_ROWS * 2;   // pixels

    inline static const char* WINDOW_TITLE = "L7aur Chess Engine";

    inline static const unsigned int NUMBER_OF_PAWNS_PER_SET = 8;
    inline static const unsigned int NUMBER_OF_KNIGHTS_PER_SET = 2;
    inline static const unsigned int NUMBER_OF_BISHOPS_PER_SET = 2;
    inline static const unsigned int NUMBER_OF_ROOKS_PER_SET = 2;
    inline static const unsigned int NUMBER_OF_QUEENS_PER_SET = 1;
    inline static const unsigned int NUMBER_OF_KINGS_PER_SET = 1;

    inline static const Color HIGHLIGHT_NORMAL = { 0x00, 0xff, 0x00, 0x60 };
    inline static const Color HIGHLIGHT_ATTACK = { 0xff, 0x00, 0x00, 0x60 };
    inline static const Color HIGHLIGHT_SPECIAL = { 0xff, 0xff, 0x00, 0x60 };
};