#include "Snake.h"

Snake::Snake(int x, int y) {
	body.push_front({x, y});
	body.push_back({x,y - 1});
	body.push_back({x,y - 2});
	body.push_back({ x,y - 3 });
	length = 4;
	direction = Direction::LEFT;
	pos = body.front();
}

void Snake::move() {
	std::pair<int, int> newHead = body.front();
	switch (direction) {

	case Direction::UP:
		newHead.second--;
		break;
	case Direction::DOWN:
		newHead.second++;
		break;
	case Direction::LEFT:
		newHead.first--;
		break;
	case Direction::RIGHT:
		newHead.first++;
		break;
	}
	body.push_front(newHead);
	body.pop_back();
	pos = body.front();
}

bool Snake::checkCollision() {
	int x = body.front().first;
	int y = body.front().second;
	for (auto& pr : body) {
		if (pr != body.front()) {
			if (pr.first == x && pr.second == y) return true;
		}
	}
	return false;
}

void Snake::changeDirection(Direction newDirection) {
	direction = newDirection;
}

std::deque<std::pair<int, int>>& Snake::getBody() {
	return body;
}

void Snake::eatFood(Food& food) {
	int im = food.getImpact();
	for (int i = 0; i < im; i++) {
		std::pair<int, int> pr = body.back();
		pr.second--;
		body.push_back(pr);
	}
}

bool Snake::checkFood(Food& obj) {
	return pos == obj.getPos();
}

