#include "GameState.hpp"

GameState::GameState(
    const unsigned int _numberOfRows,
    const unsigned int _numberOfColumns)
    : blacks{ PieceColor::BLACK }, whites{ PieceColor::WHITE },
    numberOfColumns{ _numberOfColumns }, numberOfRows{ _numberOfRows }
{
}

unsigned int GameState::getNumberOfRows() const {
    return numberOfRows;
}

unsigned int GameState::getNumberOfColumns() const {
    return numberOfColumns;
}

const PieceSet &GameState::getBlackPieceSet() const {
    return blacks;
}

const PieceSet &GameState::getWhitePieceSet() const {
    return whites;
}

void GameState::addWhitePiece(const PieceType type, const Piece::Position position) {
    whites.addPiece(type, position);
}

void GameState::addBlackPiece(const PieceType type, const Piece::Position position) {
    whites.addPiece(type, position);
}