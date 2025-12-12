#pragma once

#include "Piece.hpp"
#include "PieceColor.hpp"

#include <list>

class PieceSet {
public:
    PieceSet(const PieceColor _color);
    ~PieceSet();

    PieceSet(const PieceSet&) = delete;
    PieceSet(PieceSet&&) = delete;
    void operator=(const PieceSet&) = delete;
    void operator=(PieceSet&&) = delete;

    const PieceColor& getColor() const;

private:
    std::list<Piece*> pieces;
    const PieceColor color;
};