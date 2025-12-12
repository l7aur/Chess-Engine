#pragma once

#include "Piece.hpp"

class Knight : public Piece {
public:
    Knight(const std::filesystem::path& spritePath, const Position& position);
    ~Knight() = default;

private:
};