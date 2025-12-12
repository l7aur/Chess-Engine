#include "Window.hpp"
#include "../state/GameState.hpp"

#include "raylib.h"
#include <assert.h>

namespace
{
    Color BACKGROUND_BLACK = BLACK;
    Color BACKGROUND_BOARD = BROWN;
    Color BACKGROUND_WHITE = Color(0xcc, 0xcc, 0xcc, 0xff);
}


Window::Window(const unsigned int _width, const unsigned int _height)
    : width{ _width }, height{ _height }
{
}

void Window::init(const char* title) const {
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

void Window::drawModel(const GameState& model) {
    drawCheckboard(model.getNumberOfRows(), model.getNumberOfColumns());
}

void Window::drawCheckboard(
    const unsigned int numberOfRows,
    const unsigned int numberOfColumns) const
{
    assert(numberOfColumns != 0);
    assert(numberOfRows != 0);

    const unsigned int rectangleWidth = width / numberOfColumns;
    const unsigned int rectangleHeight = height / numberOfRows;

    assert(rectangleWidth != 0);
    assert(rectangleHeight != 0);

    ClearBackground(BACKGROUND_BOARD);
    for (unsigned int i = 0; i < numberOfRows; i++)
        for (unsigned int j = 0; j < numberOfColumns; j++)
            DrawRectangle(
                j * rectangleWidth,
                i * rectangleHeight,
                rectangleWidth,
                rectangleHeight,
                (j + i) & 1U ? BACKGROUND_WHITE : BACKGROUND_BLACK
            );
}
