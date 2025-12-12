#include "GameBoard.hpp"
#include "../static/Config.hpp"
#include "PiecePosition.hpp"

#include <iostream>
#include <assert.h>

GameBoard::GameBoard()
 : model { Config::NUMBER_OF_ROWS, Config::NUMBER_OF_COLUMNS },
 view{ Config::DISPLAY_WINDOW_WIDTH, Config::DISPLAY_WINDOW_HEIGHT }
{
}

void GameBoard::init() {
    initView();
    initModel();
}

void GameBoard::initView() {
    SetTargetFPS(120);
    view.init(
        Config::WINDOW_TITLE,
        model.getNumberOfRows(),
        model.getNumberOfColumns());
}

void GameBoard::initModel() {
    initPiecesPosition(
        PieceType::PAWN,
        PiecePosition::WhitePawnsPositions(),
        PiecePosition::BlackPawnPositions(),
        Config::NUMBER_OF_PAWNS_PER_SET
    );
    initPiecesPosition(
        PieceType::ROOK,
        PiecePosition::WhiteRooksPositions(),
        PiecePosition::BlackRooksPositions(),
        Config::NUMBER_OF_ROOKS_PER_SET
    );
    initPiecesPosition(
        PieceType::KING,
        PiecePosition::WhiteKnightsPositions(),
        PiecePosition::BlackKnightsPositions(),
        Config::NUMBER_OF_KNIGHTS_PER_SET
    );
    initPiecesPosition(
        PieceType::BISHOP,
        PiecePosition::WhiteBishopsPositions(),
        PiecePosition::BlackBishopsPositions(),
        Config::NUMBER_OF_BISHOPS_PER_SET
    );
    initPiecesPosition(
        PieceType::QUEEN,
        PiecePosition::WhiteQueensPositions(),
        PiecePosition::BlackQueensPositions(),
        Config::NUMBER_OF_QUEENS_PER_SET
    );
    initPiecesPosition(
        PieceType::KING,
        PiecePosition::WhiteKingsPositions(),
        PiecePosition::BlackKingsPositions(),
        Config::NUMBER_OF_KINGS_PER_SET
    );
}

void GameBoard::initPiecesPosition(
    const PieceType type,
    const std::list<Position> &whitePositions,
    const std::list<Position> &blackPositions,
    const unsigned int numberOfPieces)
{
    assert(whitePositions.size() == blackPositions.size());

    auto whiteIt = whitePositions.begin();
    auto blackIt = blackPositions.begin();

    for (unsigned int i = 0; i < numberOfPieces && whiteIt != whitePositions.end(); i++) {
        model.addWhitePiece(type, *whiteIt);
        model.addBlackPiece(type, *blackIt);
        whiteIt++;
        blackIt++;
    }
}

bool GameBoard::shouldExit() const {
    return view.isClosed();
}

void GameBoard::beginDrawing() const {
    view.beginDrawing();
}

void GameBoard::endDrawing() const {
    view.endDrawing();
}

void GameBoard::tick() {
    processUserInput();

    view.drawCheckboard();

    view.drawPieceSet(model.getWhitePieceSet());
    view.drawPieceSet(model.getBlackPieceSet());
}

void GameBoard::processUserInput() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 cursorPosition = GetMousePosition();
        const unsigned int row = static_cast<unsigned int>(cursorPosition.y / view.getCellHeight());
        const unsigned int col = static_cast<unsigned int>(cursorPosition.x / view.getCellWidth());
        selectedPiece = isWhiteTurn ? model.getSelectedWhitePiece(row, col) : model.getSelectedBlackPiece(row, col);
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && selectedPiece != nullptr) {
        Vector2 cursorPosition = GetMousePosition();
        const unsigned int row = static_cast<unsigned int>(cursorPosition.y / view.getCellHeight());
        const unsigned int col = static_cast<unsigned int>(cursorPosition.x / view.getCellWidth());
        const bool isNotValidPosition = (isWhiteTurn ? model.getSelectedBlackPiece(row, col) : model.getSelectedWhitePiece(row, col)) != nullptr;
        if (!isNotValidPosition) {
            selectedPiece->setPosition(Position{row, col});
            isWhiteTurn = !isWhiteTurn;
        }
        selectedPiece = nullptr;
    }
}
