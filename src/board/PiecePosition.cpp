#include "PiecePosition.hpp"

std::array<Position, 8> PiecePositions::WhitePawnsPositions()
{
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

std::array<Position, 8> PiecePositions::BlackPawnPositions()
{
    return {
        Position{7, 0},
        Position{7, 1},
        Position{7, 2},
        Position{7, 3},
        Position{7, 4},
        Position{7, 5},
        Position{7, 6},
        Position{7, 7}
    };
}
