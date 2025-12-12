#pragma once

#include <list>
#include <filesystem>
#include <functional>

class Piece {
public:
    using NormalMove = std::pair<int, int>;
    using Position = std::pair<int, int>;
    using IsSpecialMoveAllowedFunction = std::function<bool()>;
    using SpecialMove = std::pair<NormalMove, IsSpecialMoveAllowedFunction>;
    using NormalMoves = std::list<NormalMove>;
    using SpecialMoves = std::list<SpecialMove>;

    Piece(
        const std::filesystem::path& _spritePath,
        const Position& _position,
        const NormalMoves& _normalMoves,
        const SpecialMoves& _specialMoves);
    virtual ~Piece() = default;

    const NormalMoves& getNormalMoves() const;
    const SpecialMoves& getSpecialMoves() const;
    const Position& getPosition() const;
    const std::filesystem::path &getSpritePath() const;

    virtual void tick() const = 0;

protected:
    const NormalMoves normalMoves;
    const SpecialMoves specialMoves;
    const Position position;
    const std::filesystem::path spritePath;
};