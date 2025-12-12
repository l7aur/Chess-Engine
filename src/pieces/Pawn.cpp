#include "Pawn.hpp"

Pawn::Pawn(const std::filesystem::path& spritePath, const Position& position)
    : Piece {
        spritePath,
        position,
        {{1, 0}},
        {{1, 1}, {1, -1}},
        {{{2, 0}, []{return false;}}}
    }
{
}