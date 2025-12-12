#include "Piece.hpp"

Piece::Piece(
    const std::filesystem::path& _spritePath,
    const Position& _position,
    const NormalMoves& _normalMoves,
    const SpecialMoves& _specialMoves)
    :
    spritePath{ _spritePath },
    position{ _position },
    normalMoves{ _normalMoves },
    specialMoves{ _specialMoves }
{
}

const NormalMoves &Piece::getNormalMoves() const {
    return normalMoves;
}

const SpecialMoves &Piece::getSpecialMoves() const {
    return specialMoves;
}

const Position &Piece::getPosition() const {
    return position;
}

const std::filesystem::path &Piece::getSpritePath() const {
    return spritePath;
}