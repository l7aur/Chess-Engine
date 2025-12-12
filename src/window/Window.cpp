#include "Window.hpp"

#include "raylib.h"

Window::Window(const unsigned int _width, const unsigned int _height)
    : width{ _width }, height{ _height }
{
}

void Window::init(const char* title) const {
    InitWindow(width, height, title);
}

void Window::beginDrawing() const {
    BeginDrawing();
}

void Window::endDrawing() const {
    EndDrawing();
}

bool Window::isClosed() const {
    return WindowShouldClose();
}