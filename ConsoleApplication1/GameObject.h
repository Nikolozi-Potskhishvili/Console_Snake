#pragma once
#include <iostream>
class GameObject {
public:
	GameObject() : pos(-1,-1), exists(false) {
	
	};
	virtual void move() = 0;
	std::pair<int, int> getPos();
	void setPosition(int x, int y);
	bool doesExist();
	void setSatus(bool satus);
protected:
	std::pair<int,int> pos;
	bool exists;
};

