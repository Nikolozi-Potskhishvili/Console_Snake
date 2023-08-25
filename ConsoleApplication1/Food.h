#pragma once
#include "GameObject.h"

class Food : public GameObject {
public:
	
	void move() {};
	int getImpact();
private:
	int impact = 1;
};

