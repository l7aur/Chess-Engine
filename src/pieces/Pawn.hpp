#pragma once

#include "Piece.hpp"

class Pawn : public Piece {
public:
    explicit Pawn(const Color _color);
    ~Pawn() = default;

    void tick() const override;
private:
};