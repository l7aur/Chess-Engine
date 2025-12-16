#include "Pawn.hpp"
/**
 * TODO: special move: If a pawn reaches the other side it should become a queen
 */
Pawn::Pawn(const std::filesystem::path& spritePath, const Position& position)
    : Piece {
        spritePath,
        position,
        {{1, 0}},
        {{1, 1}, {1, -1}},
        {{{2, 0}, []{return true;}}}
    }
{
}