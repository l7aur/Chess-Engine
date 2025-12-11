#pragma once

class Config {
private:
    inline static unsigned int SPRITE_WIDTH  = 32; // pixels
    inline static unsigned int SPRITE_HEIGHT = 32; // pixels

public:
    inline static unsigned int DISPLAY_WINDOW_WIDTH  = SPRITE_WIDTH  * 8; // pixels
    inline static unsigned int DISPLAY_WINDOW_HEIGHT = SPRITE_HEIGHT * 8; // pixels
};