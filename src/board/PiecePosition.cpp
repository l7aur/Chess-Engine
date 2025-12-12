#include "PiecePosition.hpp"

std::list<Position> PiecePosition::WhitePawnsPositions() {
    return {
        Position{1, 0},
        Position{1, 1},
        Position{1, 2},
        Position{1, 3},
        Position{1, 4},
        Position{1, 5},
        Position{1, 6},
        Position{1, 7}
    };
}

std::list<Position> PiecePosition::BlackPawnPositions() {
    return {
        Position{6, 0},
        Position{6, 1},
        Position{6, 2},
        Position{6, 3},
        Position{6, 4},
        Position{6, 5},
        Position{6, 6},
        Position{6, 7}
    };
}

std::list<Position> PiecePosition::WhiteRooksPositions() {
    return {
        Position{0, 0},
        Position{0, 7}
    };
}

std::list<Position> PiecePosition::BlackRooksPositions() {
    return {
        Position{7, 0},
        Position{7, 7}
    };
}

std::list<Position> PiecePosition::WhiteKnightsPositions() {
    return {
        Position{0, 1},
        Position{0, 6}
    };
}

std::list<Position> PiecePosition::BlackKnightsPositions() {
    return {
        Position{7, 1},
        Position{7, 6}
    };
}

std::list<Position> PiecePosition::WhiteBishopsPositions() {
    return {
        Position{0, 3},
        Position{0, 5}
    };
}

std::list<Position> PiecePosition::BlackBishopsPositions() {
    return {
        Position{7, 3},
        Position{7, 5}
    };
}

std::list<Position> PiecePosition::WhiteQueensPositions() {
    return { Position{0, 4} };
}

std::list<Position> PiecePosition::BlackQueensPositions() {
    return { Position{7, 4} };
}

std::list<Position> PiecePosition::WhiteKingsPositions() {
    return { Position{0, 5} };
}

std::list<Position> PiecePosition::BlackKingsPositions() {
    return { Position{7, 5} };
}