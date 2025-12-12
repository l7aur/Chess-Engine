#include "board/GameBoard.hpp"

int main()
{
    GameBoard controller{};

    controller.init();
    while(!controller.shouldExit()) {
        controller.beginDrawing();
        controller.tick();
        controller.endDrawing();
    }
    return 0;
}