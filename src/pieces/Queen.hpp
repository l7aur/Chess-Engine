#pragma once

#include "Piece.hpp"

class Queen : public Piece {
public:
    Queen(const std::filesystem::path& spritePath, const Position& position);
    ~Queen() = default;

private:
};