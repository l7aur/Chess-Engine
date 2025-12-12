#pragma once

#include "../static/Definitions.hpp"

#include <array>

class PiecePositions {
public:
    static std::array<Position, 8> WhitePawnsPositions();
    static std::array<Position, 8> BlackPawnPositions();
};