#include "Pawn.hpp"

Pawn::Pawn()
    : Piece {
        {{1, 0}},
        {{{2, 0}, []{return false;}}}
    }
{
}

void Pawn::tick() const
{
}
