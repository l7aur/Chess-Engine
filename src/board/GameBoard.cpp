#include "GameBoard.hpp"
#include "../static/Config.hpp"

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
    for (unsigned int i = 0; i < Config::NUMBER_OF_PAWNS_PER_SET; i++) {
        model.addWhitePiece(PAWN, {});
        model.addBlackPiece(PAWN, {});
    }
    for (unsigned int i = 0; i < Config::NUMBER_OF_ROOKS_PER_SET; i++) {
        model.addWhitePiece(ROOK, {});
        model.addBlackPiece(ROOK, {});
    }
    for (unsigned int i = 0; i < Config::NUMBER_OF_BISHOPS_PER_SET; i++) {
        model.addWhitePiece(BISHOP, {});
        model.addBlackPiece(BISHOP, {});
    }
    for (unsigned int i = 0; i < Config::NUMBER_OF_KINGS_PER_SET; i++) {
        model.addWhitePiece(KING, {});
        model.addBlackPiece(KING, {});
    }
    for (unsigned int i = 0; i < Config::NUMBER_OF_QUEENS_PER_SET; i++) {
        model.addWhitePiece(QUEEN, {});
        model.addBlackPiece(QUEEN, {});
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

}
