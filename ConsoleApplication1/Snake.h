#pragma once
#include <deque>
#include "GameObject.h"
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
	
	

private:
	Direction direction;
	std::deque<std::pair<int, int>> body;
};

