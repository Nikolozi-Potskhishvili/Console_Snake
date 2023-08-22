#pragma once
#include <vector>
#include "Snake.h"
class Board {
public:
	Board(int h, int w);
	void init(std::vector<std::vector<char>>& board);
	void update();
	void placeSnake(Snake& snake);
private:
	std::vector<std::vector<char>> board;
	int height;
	int width;
};

