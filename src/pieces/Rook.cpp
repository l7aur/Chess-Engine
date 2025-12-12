#include "Rook.hpp"

Rook::Rook(const std::filesystem::path &spritePath, const Position &position)
    : Piece {
        spritePath,
        position,
        {{}},
        {{}},
        {{{}, []{return false;}}}
    }
{
}