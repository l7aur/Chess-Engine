#pragma once

#include <utility>
#include <list>
#include <functional>

using NormalMove = std::pair<int, int>;
using Position = std::pair<int, int>;
using IsSpecialMoveAllowedFunction = std::function<bool()>;
using SpecialMove = std::pair<NormalMove, IsSpecialMoveAllowedFunction>;
using NormalMoves = std::list<NormalMove>;
using AttackMoves = std::list<NormalMove>;
using SpecialMoves = std::list<SpecialMove>;