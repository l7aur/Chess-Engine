#include "GameBoard.hpp"
#include "../window/WindowConfig.hpp"
#include "../pieces/PieceConfig.hpp"

#include <iostream>
#include <assert.h>

GameBoard::GameBoard()
 : model { WindowConfig::NUMBER_OF_ROWS, WindowConfig::NUMBER_OF_COLUMNS },
 view{ WindowConfig::DISPLAY_WINDOW_WIDTH, WindowConfig::DISPLAY_WINDOW_HEIGHT }
{
}

void GameBoard::init() {
    initView();
    initModel();
}

void GameBoard::initView() {
    view.init(
        WindowConfig::WINDOW_TITLE,
        model.getNumberOfRows(),
        model.getNumberOfColumns());
}

void GameBoard::initModel() {
    for (
        PieceConfig::Type it = static_cast<PieceConfig::Type>(static_cast<int>(PieceConfig::Type::GUARD_BEGIN) + 1);
        it != PieceConfig::Type::GUARD_END;
        it = static_cast<PieceConfig::Type>(static_cast<int>(it) + 1))
    {
        initPiecesPosition(
            it,
            PieceConfig::POSITIONS(it, PieceColor::White),
            PieceConfig::POSITIONS(it, PieceColor::Black),
            PieceConfig::NUMBER_OF_PIECES_PER_SET(it)
        );
    }
}

void GameBoard::initPiecesPosition(
    const PieceConfig::Type type,
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
    computeMoves();
    /**
     * TODO: evaluate if any king is in check
     */
    /**
     * TODO: evaluate if the game has ended (checkmate)
     */
    processSceneDrawing();
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

void GameBoard::computeMoves() {
    if (selectedPiece == nullptr)
        return;

    const auto& current = isWhiteTurn ? model.getWhitePieceSet() : model.getBlackPieceSet();
    const auto& other = isWhiteTurn ? model.getBlackPieceSet() : model.getWhitePieceSet();

    model.setNormalMoves(computeNormalMoves(current, other));
    model.setAttackMoves(computeAttackMoves(current, other));
    model.setSpecialMoves(computeSpecialMoves(current, other));
}

std::list<Position> GameBoard::computeNormalMoves(
    const PieceSet& current,
    const PieceSet& other
) const
{
    assert(selectedPiece != nullptr);

    std::list<Position> toHighlight{};
    const auto& moves = selectedPiece->getNormalMoves();
    const auto& currentPosition = selectedPiece->getPosition();

    for (const auto& m : moves) {
        const auto boardMove = m * current.getColor();
        toHighlight.push_back(boardMove + currentPosition);
    }
    return toHighlight;
}

std::list<Position> GameBoard::computeAttackMoves(
    const PieceSet& current,
    const PieceSet& other
) const
{
    assert(selectedPiece != nullptr);

    std::list<Position> toHighlight{};
    const auto& moves = selectedPiece->getAttackMoves();
    const auto& currentPosition = selectedPiece->getPosition();

    for (const auto& m : moves) {
        const auto boardMove = m * current.getColor();
        toHighlight.push_back(boardMove + currentPosition);
    }
    return toHighlight;
}

std::list<Position> GameBoard::computeSpecialMoves(
    const PieceSet& current,
    const PieceSet& other
) const
{
    assert(selectedPiece != nullptr);

    std::list<Position> toHighlight{};
    const auto& moves = selectedPiece->getSpecialMoves();
    const auto& currentPosition = selectedPiece->getPosition();

    for (const auto& m : moves)
        if (m.second()) {
            const auto boardMove = m.first * current.getColor();
            toHighlight.push_back(boardMove + currentPosition);
        }
    return toHighlight;
}

void GameBoard::processSceneDrawing() {
    view.drawCheckboard();
    view.drawPieceSet(model.getWhitePieceSet());
    view.drawPieceSet(model.getBlackPieceSet());

    view.highlightBoardPositions(model.getNormalMoves(), WindowConfig::HIGHLIGHT_NORMAL);
    view.highlightBoardPositions(model.getAttackMoves(), WindowConfig::HIGHLIGHT_ATTACK);
    view.highlightBoardPositions(model.getSpecialMoves(), WindowConfig::HIGHLIGHT_SPECIAL);
}

bool GameBoard::isValidBoardPosition(const Position& position) const {
    /**
     * TODO: a position is valid iff it is attack, normal or special
     * and does not generate a check on current piece set king
     */
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
        model.resetMoves();
        selectedPiece = nullptr;
    }
}