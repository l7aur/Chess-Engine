#pragma once

#include "../pieces/PieceSet.hpp"

/**
 * Game model
 */
class GameState {
public:
    GameState(
        const unsigned int _numberOfRows,
        const unsigned int _numberOfColumns);
    ~GameState() = default;

    unsigned int getNumberOfRows() const;
    unsigned int getNumberOfColumns() const;

private:
    const unsigned int numberOfRows;
    const unsigned int numberOfColumns;
    PieceSet blacks;
    PieceSet whites;
};