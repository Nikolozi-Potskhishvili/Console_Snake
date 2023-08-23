#include "GameObject.h"

std::pair<int, int> GameObject::getPos() {
	return pos;
}

void GameObject::setPosition(int x, int y) {
	pos.first = x;
	pos.second = y;
	exists = true;
}
