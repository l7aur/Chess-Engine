#pragma once

#include "../static/Definitions.hpp"

class GameState;
class PieceSet;
struct Color;

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
    void highlightBoardPositions(const std::list<Position>& positions, const Color& color) const;

private:
    const unsigned int width;
    const unsigned int height;

    unsigned int cellHeight{ 0 };
    unsigned int cellWidth{ 0 };
};