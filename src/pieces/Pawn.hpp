#pragma once

#include "Piece.hpp"

class Pawn : public Piece {
public:
    Pawn();
    ~Pawn() = default;

    void tick() const override;
private:
};