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
        const AttackMoves& _attackMoves,
        const SpecialMoves& _specialMoves);
    virtual ~Piece();

    const NormalMoves& getNormalMoves() const;
    const AttackMoves& getAttackMoves() const;
    const SpecialMoves& getSpecialMoves() const;
    const Position& getPosition() const;
    void setPosition(const Position& newPosition);
    const Texture2D& getSprite() const;

protected:
    const NormalMoves normalMoves;
    const AttackMoves attackMoves;
    const SpecialMoves specialMoves;
    const Texture2D sprite;

    Position position;
};