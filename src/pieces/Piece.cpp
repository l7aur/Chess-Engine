#include "Piece.hpp"

Piece::Piece(
    const NormalMoves _normalMoves,
    const SpecialMoves _specialMoves)
    : normalMoves{ _normalMoves }, specialMoves{ _specialMoves }
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