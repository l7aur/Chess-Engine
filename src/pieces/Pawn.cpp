#include "Pawn.hpp"

Pawn::Pawn(const Color _color)
    : Piece {
        _color,
        {{1, 0}},
        {{{}, []{return false;}}}
    }
{
}

void Pawn::tick() const
{
}
