#include "Window.hpp"
#include "../state/GameState.hpp"

#include "raylib.h"
#include <assert.h>

namespace {
    const Color BACKGROUND_BLACK = BLACK;
    const Color BACKGROUND_BOARD = BROWN;
    const Color BACKGROUND_WHITE = Color(0xcc, 0xcc, 0xcc, 0xff);
    const unsigned int VERTICAL_OFFSET_IN_CELL = 2; // pixels
    const unsigned int VERTICAL_LIMIT_IN_CELL = 5; // pixels
}


Window::Window(
    const unsigned int _width,
    const unsigned int _height)
    :
    width{ _width },
    height{ _height }
{
}

void Window::init(
    const char* title,
    const unsigned int numberOfRows,
    const unsigned int numberOfColumns)
{
    assert(numberOfRows != 0);
    assert(numberOfColumns != 0);

    rectangleWidth =  width / numberOfColumns;
    rectangleHeight =  height / numberOfRows;

    assert(rectangleWidth != 0);
    assert(rectangleHeight != 0);

    InitWindow(width, height, title);
}

bool Window::isClosed() const {
    return WindowShouldClose();
}

void Window::beginDrawing() const {
    BeginDrawing();
}

void Window::endDrawing() const {
    EndDrawing();
}

void Window::drawCheckboard() const {
    ClearBackground(BACKGROUND_BOARD);
    for (unsigned int i = 0; i * rectangleWidth < width; i++)
        for (unsigned int j = 0; j * rectangleHeight < height; j++)
            DrawRectangle(
                j * rectangleWidth,
                i * rectangleHeight,
                rectangleWidth,
                rectangleHeight,
                (j + i) & 1U ? BACKGROUND_WHITE : BACKGROUND_BLACK
            );
}

void Window::drawPieceSet(const PieceSet& pieceSet) const {
    for(const auto& piece : pieceSet.getPieces()) {
        const Texture2D& texture = piece->getSprite();
        const auto&[y, x] = piece->getPosition();
        DrawTexturePro(
            texture,
            {   0,
                0,
                static_cast<float>(texture.width),
                static_cast<float>(texture.height)
            },
            {   static_cast<float>(x * rectangleWidth),
                static_cast<float>(y * rectangleHeight + VERTICAL_OFFSET_IN_CELL),
                static_cast<float>(rectangleWidth),
                static_cast<float>(rectangleHeight - VERTICAL_LIMIT_IN_CELL)
            },
            {},
            0.0f,
            WHITE
        );
    }
}
