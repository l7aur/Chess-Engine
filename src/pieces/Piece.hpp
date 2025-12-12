#pragma once

#include "../static/Definitions.hpp"
#include "raylib.h"

#include <list>
#include <filesystem>
#include <functional>

class Piece {
public:
    Piece(
        const std::filesystem::path& spritePath,
        const Position& _position,
        const NormalMoves& _normalMoves,
        const SpecialMoves& _specialMoves);
    virtual ~Piece();

    const NormalMoves& getNormalMoves() const;
    const SpecialMoves& getSpecialMoves() const;
    const Position& getPosition() const;
    const Texture2D& getSprite() const;
    virtual void tick() const = 0;

protected:
    const NormalMoves normalMoves;
    const SpecialMoves specialMoves;
    const Position position;
    const Texture2D sprite;
};