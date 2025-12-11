#include "Piece.hpp"

Piece::Piece(
    const Color _color,
    const NormalMoves _normalMoves,
    const SpecialMoves _specialMoves)
    : color { _color }, normalMoves{ _normalMoves }, specialMoves{ _specialMoves }
{
}

const Piece::NormalMoves &Piece::getNormalMoves() const {
    return normalMoves;
}

const Piece::SpecialMoves &Piece::getSpecialMoves() const {
    return specialMoves;
}

const Piece::Position &Piece::getPosition() const {
    return position;
}

const Color &Piece::getColor() const {
    return color;
}
