#pragma once

#include "Piece.hpp"

class Pawn : public Piece {
public:
    Pawn(const std::filesystem::path& spritePath, const Position& position);
    ~Pawn() = default;

private:
};