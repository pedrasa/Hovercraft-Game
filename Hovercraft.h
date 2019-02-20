#pragma once
#include "GameObject.h"

class Hovercraft:public GameObject
{
public:
	Hovercraft(glm::vec3 position);
	~Hovercraft();
	void start();
	void update(int deltaTime);
	unsigned int setupDrawing(unsigned int listBase);
};

