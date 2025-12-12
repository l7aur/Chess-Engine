#pragma once

#include "Piece.hpp"

class Rook : public Piece {
public:
    Rook(const std::filesystem::path& spritePath, const Position& position);
    ~Rook() = default;

private:
};