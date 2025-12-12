#pragma once

class GameState;

/**
 * Game View
 */
class Window {
public:
    Window(const unsigned int _width, const unsigned int _height);
    ~Window() = default;

    void init(const char* title) const;
    bool isClosed() const;
    void beginDrawing() const;
    void endDrawing() const;
    void drawModel(const GameState &model);

private:
    const unsigned int width;
    const unsigned int height;

    void drawCheckboard(
        const unsigned int numberOfRows,
        const unsigned int numberOfColumns) const;
};