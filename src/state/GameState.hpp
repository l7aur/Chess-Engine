#pragma once

#include "../pieces/PieceSet.hpp"
#include "../pieces/PieceConfig.hpp"
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

    void addWhitePiece(const PieceConfig::Type type, const Position position);
    void addBlackPiece(const PieceConfig::Type type, const Position position);
    Piece* getSelectedWhitePiece(const Position& position) const;
    Piece* getSelectedBlackPiece(const Position& position) const;

    void setNormalMoves(const std::list<Position>& positions);
    void setAttackMoves(const std::list<Position>& positions);
    void setSpecialMoves(const std::list<Position>& positions);
    const std::list<Position>& getNormalMoves() const;
    const std::list<Position>& getAttackMoves() const;
    const std::list<Position>& getSpecialMoves() const;
    void resetMoves();

private:
    const unsigned int numberOfRows;
    const unsigned int numberOfColumns;
    PieceSet blacks;
    PieceSet whites;
    std::list<Position> normalMoves{};
    std::list<Position> attackMoves{};
    std::list<Position> specialMoves{};
};