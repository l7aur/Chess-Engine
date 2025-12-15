#include "PieceSet.hpp"
#include "PieceConfig.hpp"
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

void PieceSet::addPiece(const PieceConfig::Type type, const Position position) {
    using PieceConfig::Type::PAWN, PieceConfig::Type::ROOK, PieceConfig::Type::KNIGHT;
    using PieceConfig::Type::BISHOP, PieceConfig::Type::QUEEN, PieceConfig::Type::KING;

    std::unique_ptr<Piece> newPiece{};
    switch (type) {
    case ROOK:
        newPiece.reset(new Rook(PieceConfig::PATH_TO_SPRITE(type, color), position));
        break;
    case KNIGHT:
        newPiece.reset(new Knight(PieceConfig::PATH_TO_SPRITE(type, color), position));
        break;
    case BISHOP:
        newPiece.reset(new Bishop(PieceConfig::PATH_TO_SPRITE(type, color), position));
        break;
    case QUEEN:
        newPiece.reset(new Queen(PieceConfig::PATH_TO_SPRITE(type, color), position));
        break;
    case KING:
        newPiece.reset(new King(PieceConfig::PATH_TO_SPRITE(type, color), position));
        break;
    default:
        newPiece.reset(new Pawn(PieceConfig::PATH_TO_SPRITE(type, color), position));
        break;
    }
    pieces.push_back(std::move(newPiece));
}

Piece *PieceSet::getPieceByPosition(const Position& position) const
{
    auto pieceIt = std::find_if(pieces.begin(), pieces.end(),
        [&position] (const std::unique_ptr<Piece>& p) {
            return p->getPosition().first == position.first && p->getPosition().second == position.second; });

    return pieceIt != pieces.end() ? pieceIt->get() : nullptr;
}
