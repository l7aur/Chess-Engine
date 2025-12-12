#include "GameBoard.hpp"
#include "../static/Config.hpp"

GameBoard::GameBoard()
 : model { Config::NUMBER_OF_ROWS, Config::NUMBER_OF_COLUMNS },
 view{ Config::DISPLAY_WINDOW_WIDTH, Config::DISPLAY_WINDOW_HEIGHT }
{
}

void GameBoard::initView() const {
    view.init(Config::WINDOW_TITLE);
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

void GameBoard::tick()
{
    processUserInput();
    view.drawModel(model); // model should implement an interface ideally
}

void GameBoard::processUserInput()
{
}
