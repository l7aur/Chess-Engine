#pragma once

#include "Piece.hpp"
#include "../static/PieceColor.hpp"
#include "PieceConfig.hpp"

#include <list>
#include <memory>

class PieceSet {
public:
    PieceSet(const PieceColor _color);
    ~PieceSet() = default;

    PieceSet(const PieceSet&) = delete;
    PieceSet(PieceSet&&) = delete;
    void operator=(const PieceSet&) = delete;
    void operator=(PieceSet&&) = delete;

    const PieceColor& getColor() const;
    const std::list<std::unique_ptr<Piece>>& getPieces() const;
    void addPiece(const PieceConfig::Type type, const Position position);
    Piece* getPieceByPosition(const Position& position) const;
private:
    std::list<std::unique_ptr<Piece>> pieces;
    const PieceColor color;
};