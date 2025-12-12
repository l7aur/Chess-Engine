#pragma once

#include "../state/GameState.hpp"
#include "../window/Window.hpp"

/**
 * Game Controller
 */
class GameBoard {
public:
    GameBoard();
    ~GameBoard() = default;

    void init();
    bool shouldExit() const;
    void beginDrawing() const;
    void endDrawing() const;

    void tick();
private:
    GameState model;
    Window view;

    void processUserInput();
};