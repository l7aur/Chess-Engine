#include "board/GameBoard.hpp"

int main()
{
    GameBoard controller{};

    controller.initView();
    while(!controller.shouldExit()) {
        controller.beginDrawing();
        controller.tick();
        controller.endDrawing();
    }
    return 0;
}