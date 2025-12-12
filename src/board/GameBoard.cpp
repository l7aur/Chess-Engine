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
    initPawnsPosition(
        PiecePosition::WhitePawnsPositions(),
        PiecePosition::BlackPawnPositions()
    );
    initRooksPosition(
        PiecePosition::WhiteRooksPositions(),
        PiecePosition::BlackRooksPositions()
    );
    initKnightsPosition(
        PiecePosition::WhiteKnightsPositions(),
        PiecePosition::BlackKnightsPositions()
    );
    initBishopsPosition(
        PiecePosition::WhiteBishopsPositions(),
        PiecePosition::BlackBishopsPositions()
    );
    initQueensPosition(
        PiecePosition::WhiteQueensPositions(),
        PiecePosition::BlackQueensPositions()
    );
    initKingsPosition(
        PiecePosition::WhiteKingsPositions(),
        PiecePosition::BlackKingsPositions()
    );
}

void GameBoard::initPawnsPosition(
        const std::list<Position>& whitePositions,
        const std::list<Position>& blackPositions)
{
    assert(whitePositions.size() == blackPositions.size());

    auto whiteIt = whitePositions.begin();
    auto blackIt = blackPositions.begin();

    for (unsigned int i = 0; i < Config::NUMBER_OF_PAWNS_PER_SET && whiteIt != whitePositions.end(); i++) {
        model.addWhitePiece(PAWN, *whiteIt);
        model.addBlackPiece(PAWN, *blackIt);
        whiteIt++;
        blackIt++;
    }
}

void GameBoard::initRooksPosition(
        const std::list<Position>& whitePositions,
        const std::list<Position>& blackPositions)
{
    assert(whitePositions.size() == blackPositions.size());

    auto whiteIt = whitePositions.begin();
    auto blackIt = blackPositions.begin();

    for (unsigned int i = 0; i < Config::NUMBER_OF_ROOKS_PER_SET && whiteIt != whitePositions.end(); i++) {
        model.addWhitePiece(ROOK, *whiteIt);
        model.addBlackPiece(ROOK, *blackIt);
        whiteIt++;
        blackIt++;
    }
}

void GameBoard::initKnightsPosition(
        const std::list<Position>& whitePositions,
        const std::list<Position>& blackPositions)
{
    assert(whitePositions.size() == blackPositions.size());

    auto whiteIt = whitePositions.begin();
    auto blackIt = blackPositions.begin();

    for (unsigned int i = 0; i < Config::NUMBER_OF_KNIGHTS_PER_SET && whiteIt != whitePositions.end(); i++) {
        model.addWhitePiece(KNIGHT, *whiteIt);
        model.addBlackPiece(KNIGHT, *blackIt);
        whiteIt++;
        blackIt++;
    }
}

void GameBoard::initBishopsPosition(
        const std::list<Position>& whitePositions,
        const std::list<Position>& blackPositions)
{
    assert(whitePositions.size() == blackPositions.size());

    auto whiteIt = whitePositions.begin();
    auto blackIt = blackPositions.begin();

    for (unsigned int i = 0; i < Config::NUMBER_OF_BISHOPS_PER_SET  && whiteIt != whitePositions.end(); i++) {
        model.addWhitePiece(BISHOP, *whiteIt);
        model.addBlackPiece(BISHOP, *blackIt);
        whiteIt++;
        blackIt++;
    }
}

void GameBoard::initQueensPosition(
        const std::list<Position>& whitePositions,
        const std::list<Position>& blackPositions)
{
    assert(whitePositions.size() == blackPositions.size());

    auto whiteIt = whitePositions.begin();
    auto blackIt = blackPositions.begin();

    for (unsigned int i = 0; i < Config::NUMBER_OF_QUEENS_PER_SET && whiteIt != whitePositions.end(); i++) {
        model.addWhitePiece(QUEEN, *whiteIt);
        model.addBlackPiece(QUEEN, *blackIt);
        whiteIt++;
        blackIt++;
    }
}

void GameBoard::initKingsPosition(
    const std::list<Position>& whitePositions,
    const std::list<Position>& blackPositions)
{
    assert(whitePositions.size() == blackPositions.size());

    auto whiteIt = whitePositions.begin();
    auto blackIt = blackPositions.begin();

    for (unsigned int i = 0; i < Config::NUMBER_OF_KINGS_PER_SET && whiteIt != whitePositions.end(); i++) {
        model.addWhitePiece(KING, *whiteIt);
        model.addBlackPiece(KING, *blackIt);
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
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        Vector2 cursorPosition = GetMousePosition();
        const auto& [selectedPiece, color] = model.getSelectedPiece(
            static_cast<unsigned int>(cursorPosition.y / view.getCellHeight()),
            static_cast<unsigned int>(cursorPosition.x / view.getCellWidth()));

        std::cout << (color == PieceColor::Black ? "Black " : "White ")
            << (selectedPiece != nullptr ? selectedPiece->getSprite().id : 0)
            << std::endl;
    }
}
