#pragma once

#include "../pieces/PieceSet.hpp"
#include "../pieces/PieceType.hpp"
#include "../static/Definitions.hpp"

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

    const PieceSet& getBlackPieceSet() const;
    const PieceSet& getWhitePieceSet() const;

    void addWhitePiece(const PieceType type, const Position position);
    void addBlackPiece(const PieceType type, const Position position);
    Piece* getSelectedWhitePiece(const Position& position) const;
    Piece* getSelectedBlackPiece(const Position& position) const;

private:
    const unsigned int numberOfRows;
    const unsigned int numberOfColumns;
    PieceSet blacks;
    PieceSet whites;
};