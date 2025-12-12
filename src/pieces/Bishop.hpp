#pragma once

#include "Piece.hpp"

class Bishop : public Piece {
public:
    Bishop(const std::filesystem::path& spritePath, const Position& position);
    ~Bishop() = default;

private:
};