#pragma once
#include <glm/glm.hpp>
#include "GameObject.h"

struct Colour {
	float r, g, b;
};

class Hovercraft
{
public:
	Hovercraft(glm::vec3 position, Colour col = { 0.55f, 0.27f, 0.07f });
	~Hovercraft();
	void drawScene();
	void start();
	void update(int deltaTime);
	unsigned int setupDrawing(unsigned int listBase);
	void setColour(Colour col);
};

