#include "Bishop.hpp"

Bishop::Bishop(const std::filesystem::path &spritePath, const Position &position)
    : Piece {
        spritePath,
        position,
        {{}},
        {{}},
        {{{}, []{return false;}}}
    }
{
}