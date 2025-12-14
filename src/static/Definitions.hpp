#pragma once

#include "PieceColor.hpp"

#include <utility>
#include <list>
#include <functional>


using Position = std::pair<int, int>;

struct NormalMove {
    int first{ 0 };
    int second{ 0 };

    NormalMove operator*(const PieceColor& color) const {
        return NormalMove{ first * static_cast<int>(color), second * static_cast<int>(color) };
    }

    Position operator+(const Position& position) const {
        return Position{ first + position.first, second + position.second };
    }
};

inline Position operator+(const Position& position, const NormalMove& move) {
    return move + position;
}

using IsSpecialMoveAllowedFunction = std::function<bool()>;
using SpecialMove = std::pair<NormalMove, IsSpecialMoveAllowedFunction>;
using NormalMoves = std::list<NormalMove>;
using AttackMoves = std::list<NormalMove>;
using SpecialMoves = std::list<SpecialMove>;