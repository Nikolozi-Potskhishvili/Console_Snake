
#include <iostream>
#include <vector>
#include "Game.h"
const int width = 120;
const int height = 30;

int main() {
    const int width = 120;
    const int height = 30;
    const int startX = width / 2;
    const int startY = height / 2;
    Game game(height, width, startX, startY);
    game.startGame();
}

