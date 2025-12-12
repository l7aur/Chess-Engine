#include "PieceSet.hpp"

PieceSet::PieceSet(const PieceColor _color)
    : color{ _color }
{
}

PieceSet::~PieceSet()
{
    for(auto& p : pieces)
        delete p;
}

const PieceColor &PieceSet::getColor() const {
    return color;
}