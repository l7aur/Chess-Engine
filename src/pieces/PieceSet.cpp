#include "PieceSet.hpp"
#include "Resource.hpp"
#include "Pawn.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "King.hpp"
#include "Queen.hpp"
#include "Bishop.hpp"

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
    case ROOK:
        newPiece.reset(new Rook(
            color == PieceColor::Black ? Resource::BLACK_PATH_TO_ROOK : Resource::WHITE_PATH_TO_ROOK,
            position));
        break;
    case KNIGHT:
        newPiece.reset(new Knight(
            color == PieceColor::Black ? Resource::BLACK_PATH_TO_KNIGHT : Resource::WHITE_PATH_TO_KNIGHT,
            position));
        break;
    case BISHOP:
        newPiece.reset(new Bishop(
            color == PieceColor::Black ? Resource::BLACK_PATH_TO_BISHOP : Resource::WHITE_PATH_TO_BISHOP,
            position));
        break;
    case QUEEN:
        newPiece.reset(new Queen(
            color == PieceColor::Black ? Resource::BLACK_PATH_TO_QUEEN : Resource::WHITE_PATH_TO_QUEEN,
            position));
        break;
    case KING:
        newPiece.reset(new King(
            color == PieceColor::Black ? Resource::BLACK_PATH_TO_KING : Resource::WHITE_PATH_TO_KING,
            position));
        break;
    default:
        newPiece.reset(new Pawn(
            color == PieceColor::Black ? Resource::BLACK_PATH_TO_PAWN : Resource::WHITE_PATH_TO_PAWN,
            position));
        break;
    }
    pieces.push_back(std::move(newPiece));
}
