#pragma once

#include <list>
#include <functional>

class Piece {
public:
    using NormalMove = std::pair<int, int>;
    using Position = std::pair<int, int>;
    using IsSpecialMoveAllowedFunction = std::function<bool()>;
    using SpecialMove = std::pair<NormalMove, IsSpecialMoveAllowedFunction>;
    using NormalMoves = std::list<NormalMove>;
    using SpecialMoves = std::list<SpecialMove>;

    Piece(
        const NormalMoves _normalMoves,
        const SpecialMoves _specialMoves);
    virtual ~Piece() = default;

    const NormalMoves& getNormalMoves() const;
    const SpecialMoves& getSpecialMoves() const;
    const Position& getPosition() const;

    virtual void tick() const = 0;

protected:
    const NormalMoves normalMoves;
    const SpecialMoves specialMoves;
    const Position position;
};