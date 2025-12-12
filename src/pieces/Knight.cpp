#include "Knight.hpp"

Knight::Knight(const std::filesystem::path &spritePath, const Position &position)
    : Piece {
        spritePath,
        position,
        {{}},
        {{}},
        {{{}, []{return false;}}}
    }
{
}