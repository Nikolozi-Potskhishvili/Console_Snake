#pragma once
#include <iostream>
class GameObject {
public:
	GameObject() : pos(-1,-1), exists(true) {
	
	};
	virtual void move() = 0;
	std::pair<int, int> getPos();
	void setPosition(int x, int y);
protected:
	std::pair<int,int> pos;
	bool exists;
};

