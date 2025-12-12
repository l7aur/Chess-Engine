#include "Queen.hpp"

Queen::Queen(const std::filesystem::path &spritePath, const Position &position)
    : Piece {
        spritePath,
        position,
        {{}},
        {{}},
        {{{}, []{return false;}}}
    }
{
}