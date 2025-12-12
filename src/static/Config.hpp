#pragma once

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
};