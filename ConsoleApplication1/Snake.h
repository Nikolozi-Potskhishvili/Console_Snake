#pragma once
#include <deque>

enum class Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Snake	{
public:
	Snake(int x, int y);
	void move();
	bool checkCollision();
	void changeDirection(Direction newDirection);
	std::deque<std::pair<int, int>>& getBody();
	

private:
	Direction direction;
	std::deque<std::pair<int, int>> body;
};

