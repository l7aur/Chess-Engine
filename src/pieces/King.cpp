#include "King.hpp"

King::King(const std::filesystem::path &spritePath, const Position &position)
    : Piece {
        spritePath,
        position,
        {{}},
        {{}},
        {{{}, []{return false;}}}
    }
{
}