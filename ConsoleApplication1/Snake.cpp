#include "Snake.h"

Snake::Snake(int x, int y) {
	body.push_front({x, y});
	body.push_back({x,y - 1});
	body.push_back({x,y - 2});
	direction = Direction::LEFT;
}

void Snake::move() {
	switch (direction) {
	case Direction::UP:
		for (auto& element : body) {
			element.second--;
		}
		break;
	case Direction::DOWN:
		for (auto& element : body) {
			element.second++;
		}
		break;
	case Direction::LEFT:
		for(auto& element : body) {
			if(element != body.front()) element.first--;
		}
		break;
	case Direction::RIGHT:
		for (auto& element : body) {
			if (element != body.front()) element.first++;
		}
		break;
	}
}

bool Snake::checkCollision() {
	return body.front() == body.back();
}

void Snake::changeDirection(Direction newDirection) {
	direction = newDirection;
}

std::deque<std::pair<int, int>>& Snake::getBody() {
	return body;
}

