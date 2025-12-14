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
        PieceType::KNIGHT,
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
    processSceneDrawing();
    processUserInput();
    processHighlights();
}

void GameBoard::processUserInput() {
    Vector2 cursorPosition = GetMousePosition();
    const Position position {
        static_cast<unsigned int>(cursorPosition.y / view.getCellHeight()),
        static_cast<unsigned int>(cursorPosition.x / view.getCellWidth())
    };
    const bool isValidPosition = isValidBoardPosition(position);

    processUserLeftClick(position);
    processUserLeftClickPressed(position, isValidPosition);
    processUserLeftClickRelease(position, isValidPosition);
}

void GameBoard::processHighlights() const {
    if (selectedPiece == nullptr)
        return;

    view.highlightBoardPositions(computeNormalMoves(), Config::HIGHLIGHT_NORMAL);
    view.highlightBoardPositions(computeAttackMoves(), Config::HIGHLIGHT_ATTACK);
    view.highlightBoardPositions(computeSpecialMoves(), Config::HIGHLIGHT_SPECIAL);
}

std::list<Position> GameBoard::computeNormalMoves() const {
    const auto& moves = selectedPiece->getNormalMoves();
    const auto& currentPieceSet = isWhiteTurn ? model.getWhitePieceSet() : model.getBlackPieceSet();
    const auto& otherPieceSet = isWhiteTurn ? model.getBlackPieceSet() : model.getWhitePieceSet();
    const auto& currentPosition = selectedPiece->getPosition();
    std::list<Position> toHighlight{};

    for(const auto& m : moves) {
        const auto boardMove = m * currentPieceSet.getColor();
        toHighlight.push_back(boardMove + currentPosition);
    }
    return toHighlight;
}

std::list<Position> GameBoard::computeAttackMoves() const {
    const auto& moves = selectedPiece->getAttackMoves();
    const auto& currentPieceSet = isWhiteTurn ? model.getWhitePieceSet() : model.getBlackPieceSet();
    const auto& otherPieceSet = isWhiteTurn ? model.getBlackPieceSet() : model.getWhitePieceSet();
    const auto& currentPosition = selectedPiece->getPosition();
    std::list<Position> toHighlight{};

    for(const auto& m : moves) {
        const auto boardMove = m * currentPieceSet.getColor();
        toHighlight.push_back(boardMove + currentPosition);
    }
    return toHighlight;
}

std::list<Position> GameBoard::computeSpecialMoves() const {
    const auto& moves = selectedPiece->getSpecialMoves();
    const auto& currentPieceSet = isWhiteTurn ? model.getWhitePieceSet() : model.getBlackPieceSet();
    const auto& otherPieceSet = isWhiteTurn ? model.getBlackPieceSet() : model.getWhitePieceSet();
    const auto& currentPosition = selectedPiece->getPosition();
    std::list<Position> toHighlight{};

    // for(const auto& m : moves) {
    //     const auto boardMove = m * currentPieceSet.getColor();
    //     toHighlight.push_back(boardMove + currentPosition);
    // }
    return toHighlight;
}

void GameBoard::processSceneDrawing() {
    view.drawCheckboard();
    view.drawPieceSet(model.getWhitePieceSet());
    view.drawPieceSet(model.getBlackPieceSet());
}

bool GameBoard::isValidBoardPosition(const Position& position) const {
    Piece* pieceAtPosition = model.getSelectedWhitePiece(position);
    if (pieceAtPosition != nullptr)
        return false;

    pieceAtPosition = model.getSelectedBlackPiece(position);
    if (pieceAtPosition == nullptr)
        return true;
    return false;
}

void GameBoard::processUserLeftClick(const Position &position) {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        selectedPiece = isWhiteTurn ? model.getSelectedWhitePiece(position) : model.getSelectedBlackPiece(position);
}

void GameBoard::processUserLeftClickPressed(const Position &position, const bool isValidPostion) {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && selectedPiece != nullptr) {
        if (isValidPostion)
            selectedPiece->setDrawPosition(position);
        else
            selectedPiece->resetDrawPosition();
    }
}

void GameBoard::processUserLeftClickRelease(const Position &position, const bool isValidPosition) {
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && selectedPiece != nullptr) {
        if (isValidPosition) {
            selectedPiece->commitPosition(position);
            isWhiteTurn = !isWhiteTurn;
        }
        else {
            selectedPiece->resetDrawPosition();
        }
        selectedPiece = nullptr;
    }
}