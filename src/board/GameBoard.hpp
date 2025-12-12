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

    // Finite State Machine
    bool isWhiteTurn{ true };
    Piece* selectedPiece{ nullptr };

    void initView();
    void initModel();
    void initPiecesPosition(
        const PieceType type,
        const std::list<Position>& whitePositions,
        const std::list<Position>& blackPositions,
        const unsigned int numberOfPieces);
    void processUserInput();
};