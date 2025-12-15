#include "GameState.hpp"

GameState::GameState(
    const unsigned int _numberOfRows,
    const unsigned int _numberOfColumns)
    : blacks{ PieceColor::Black }, whites{ PieceColor::White },
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

void GameState::addWhitePiece(const PieceConfig::Type type, const Position position) {
    whites.addPiece(type, position);
}

void GameState::addBlackPiece(const PieceConfig::Type type, const Position position) {
    blacks.addPiece(type, position);
}

Piece* GameState::getSelectedWhitePiece(const Position& position) const {
    return whites.getPieceByPosition(position);
}

Piece* GameState::getSelectedBlackPiece(const Position& position) const {
    return blacks.getPieceByPosition(position);
}

void GameState::setNormalMoves(const std::list<Position> &positions) {
    normalMoves = positions;
}

void GameState::setAttackMoves(const std::list<Position> &positions) {
    attackMoves = positions;
}

void GameState::setSpecialMoves(const std::list<Position> &positions) {
    specialMoves = positions;
}

const std::list<Position> &GameState::getNormalMoves() const {
    return normalMoves;
}

const std::list<Position> &GameState::getAttackMoves() const {
    return attackMoves;
}

const std::list<Position> &GameState::getSpecialMoves() const {
    return specialMoves;
}

void GameState::resetMoves() {
    normalMoves.clear();
    attackMoves.clear();
    specialMoves.clear();
}
