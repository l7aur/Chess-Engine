#include "Piece.hpp"

Piece::Piece(
    const std::filesystem::path& spritePath,
    const Position& _position,
    const NormalMoves& _normalMoves,
    const SpecialMoves& _specialMoves)
    :
    position{ _position },
    normalMoves{ _normalMoves },
    specialMoves{ _specialMoves },
    sprite{ LoadTexture(spritePath.string().c_str()) }
{
}

Piece::~Piece() {
    UnloadTexture(sprite);
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

const Texture2D &Piece::getSprite() const {
    return sprite;
}
