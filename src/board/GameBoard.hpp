#pragma once

/**
 * Game Controller
 */
class GameBoard {
public:
    GameBoard() = default;
    ~GameBoard() = default;

private:
    static const unsigned int NUMBER_OF_ROWS{ 8 };
    static const unsigned int NUMBER_OF_COLUMNS{ 8 };
};