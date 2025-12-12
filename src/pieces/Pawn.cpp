#include "Pawn.hpp"

Pawn::Pawn(const std::filesystem::path& _spritePath, const Position& _position)
    : Piece {
        _spritePath,
        _position,
        {{1, 0}},
        {{{2, 0}, []{return false;}}}
    }
{
}

void Pawn::tick() const
{
}
