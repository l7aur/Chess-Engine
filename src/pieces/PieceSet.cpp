#include "PieceSet.hpp"
#include "Resource.hpp"
#include "Pawn.hpp"

PieceSet::PieceSet(const PieceColor _color)
    : color{ _color }
{
}

const PieceColor &PieceSet::getColor() const {
    return color;
}

const std::list<std::unique_ptr<Piece>> &PieceSet::getPieces() const {
    return pieces;
}

void PieceSet::addPiece(const PieceType type, const Position position) {
    std::unique_ptr<Piece> newPiece{};
    switch (type) {
    case PAWN:
        newPiece.reset(new Pawn(
            color == PieceColor::BLACK ? Resource::BLACK_PATH_TO_PAWN : Resource::WHITE_PATH_TO_PAWN,
            position));
        break;
    case ROOK:
        break;
    case KNIGHT:
        break;
    case BISHOP:
        break;
    case QUEEN:
        break;
    case KING:
        break;
    }
    pieces.push_back(std::move(newPiece));
}
