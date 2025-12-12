#pragma once

class GameState;
class PieceSet;

/**
 * Game View
 */
class Window {
public:
    Window(
        const unsigned int _width,
        const unsigned int _height);
    ~Window() = default;

    void init(
        const char* title,
        const unsigned int numberOfRows,
        const unsigned int numberOfColumns);
    bool isClosed() const;
    void beginDrawing() const;
    void endDrawing() const;
    void drawCheckboard() const;
    void drawPieceSet(const PieceSet& pieceSet) const;
    unsigned int getCellWidth() const;
    unsigned int getCellHeight() const;

private:
    const unsigned int width;
    const unsigned int height;

    unsigned int cellHeight{ 0 };
    unsigned int cellWidth{ 0 };
};