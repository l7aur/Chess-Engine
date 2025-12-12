#pragma once

#include "Piece.hpp"

class Pawn : public Piece {
public:
    Pawn(const std::filesystem::path& _spritePath, const Position& _position);
    ~Pawn() = default;

    void tick() const override;
private:
};