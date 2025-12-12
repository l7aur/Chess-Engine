#pragma once

#include "Piece.hpp"

class King : public Piece {
public:
    King(const std::filesystem::path& spritePath, const Position& position);
    ~King() = default;

private:
};