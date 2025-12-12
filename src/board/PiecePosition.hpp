#pragma once

#include "../static/Definitions.hpp"

#include <list>

class PiecePosition {
public:
    static std::list<Position> WhitePawnsPositions();
    static std::list<Position> BlackPawnPositions();

    static std::list<Position> WhiteRooksPositions();
    static std::list<Position> BlackRooksPositions();

    static std::list<Position> WhiteKnightsPositions();
    static std::list<Position> BlackKnightsPositions();

    static std::list<Position> WhiteBishopsPositions();
    static std::list<Position> BlackBishopsPositions();

    static std::list<Position> WhiteQueensPositions();
    static std::list<Position> BlackQueensPositions();

    static std::list<Position> WhiteKingsPositions();
    static std::list<Position> BlackKingsPositions();
};