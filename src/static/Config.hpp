#pragma once

class Config {
private:
    inline static const unsigned int SPRITE_WIDTH  = 32; // pixels
    inline static const unsigned int SPRITE_HEIGHT = 32; // pixels

public:
    inline static const unsigned int DISPLAY_WINDOW_WIDTH  = SPRITE_WIDTH  * 8; // pixels
    inline static const unsigned int DISPLAY_WINDOW_HEIGHT = SPRITE_HEIGHT * 8; // pixels

    inline static const char* WINDOW_TITLE = "L7aur Chess Engine";
};