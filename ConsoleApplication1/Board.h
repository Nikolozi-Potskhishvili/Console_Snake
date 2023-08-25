#pragma once
#include <vector>
#include "Snake.h"
#include "Food.h"

class Board {
public:
	Board(int h, int w);
	void init(std::vector<std::vector<char>>& board);
	void update();
	void placeSnake(Snake& snake,Food& food);
	void placeGameObject(GameObject& obj);
	void removeGameObject(GameObject& obj);
	int getHeight();
	int getWidtht();

private:
	std::vector<std::vector<char>> board;
	int height;
	int width;
};

