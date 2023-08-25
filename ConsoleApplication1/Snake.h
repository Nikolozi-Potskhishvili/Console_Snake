#pragma once
#include <deque>
#include "Food.h"
enum class Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Snake : GameObject{
public:
	Snake(int x, int y);
	void move() override;
	bool checkCollision();
	void changeDirection(Direction newDirection);
	std::deque<std::pair<int, int>>& getBody();
	void eatFood(Food& obj);
	bool checkFood(Food& obj);

private:
	Direction direction;
	int length;
	std::deque<std::pair<int, int>> body;
};

