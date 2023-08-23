#pragma once
#include "Board.h"
#include <conio.h>
#include <iostream>

class Game {
public:
	Game(int h, int w, int startX, int startY);
	void startGame();
	void handleInput();
private:
	bool isRunning;
	Board board;
	Snake snake;
	Food food;
};

