#pragma once

#include "../static/Definitions.hpp"

#include <filesystem>

class PieceConfig {
public:
    enum Type {
        GUARD_BEGIN,

        PAWN,
        ROOK,
        KNIGHT,
        BISHOP,
        QUEEN,
        KING,

        GUARD_END
    };

    static unsigned int NUMBER_OF_PIECES_PER_SET(const Type type);
    static std::filesystem::path PATH_TO_SPRITE(const Type type, const PieceColor color);
    static std::list<Position> POSITIONS(const Type type, const PieceColor color);

private:
    static std::filesystem::path WHITE_PATH_TO_SPRITE(const Type type);
    static std::filesystem::path BLACK_PATH_TO_SPRITE(const Type type);

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