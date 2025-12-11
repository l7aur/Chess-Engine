#pragma once

/**
 * Game View
 */
class Window {
public:
    Window(const unsigned int _width, const unsigned int _height);
    ~Window() = default;

private:
    const unsigned int width;
    const unsigned int height;
};