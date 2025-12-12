#pragma once

/**
 * Game View
 */
class Window {
public:
    Window(const unsigned int _width, const unsigned int _height);
    ~Window() = default;

    void init(const char* title) const;
    void beginDrawing() const;
    void endDrawing() const;
    bool isClosed() const;

private:
    const unsigned int width;
    const unsigned int height;
};