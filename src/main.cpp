#include "board/GameBoard.hpp"
#include "state/GameState.hpp"
#include "window/Window.hpp"
#include "static/Config.hpp"

int main()
{
    GameState model;
    Window view{ Config::DISPLAY_WINDOW_WIDTH, Config::DISPLAY_WINDOW_HEIGHT };
    GameBoard controller;

    return 0;
}