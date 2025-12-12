#pragma once

#include "../state/GameState.hpp"
#include "../window/Window.hpp"

/**
 * Game Controller
 */
class GameBoard {
public:
    GameBoard();
    ~GameBoard() = default;

    void init();
    bool shouldExit() const;
    void beginDrawing() const;
    void endDrawing() const;

    void tick();
private:
    GameState model;
    Window view;

    bool isWhiteTurn{ true };
    Piece* selectedPiece{ nullptr };

    void initView();
    void initModel();
    void initPawnsPosition(
        const std::list<Position>& whitePositions,
        const std::list<Position>& blackPositions);
    void initRooksPosition(
        const std::list<Position>& whitePositions,
        const std::list<Position>& blackPositions);
    void initKnightsPosition(
        const std::list<Position> &whitePositions,
        const std::list<Position> &blackPositions);
    void initBishopsPosition(
        const std::list<Position> &whitePositions,
        const std::list<Position> &blackPositions);
    void initQueensPosition(
        const std::list<Position>& whitePositions,
        const std::list<Position>& blackPositions);
    void initKingsPosition(
        const std::list<Position>& whitePositions,
        const std::list<Position>& blackPositions);
    void processUserInput();
};