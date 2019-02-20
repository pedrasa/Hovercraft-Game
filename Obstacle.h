#pragma once
#include <glm/glm.hpp>
#include "GameObject.h"
struct Colour {
	float r, g, b;
};

class Obstacle
{
private :
	Colour colour = { 0.55f, 0.27f, 0.07f };
public:
	Obstacle(glm::vec3 position, Colour col = { 0.55f, 0.27f, 0.07f });
	~Obstacle();
	void drawScene();
	void start();
	void update(int deltaTime);
	unsigned int setupDrawing(unsigned int listBase);
	void setColour(Colour col);

};

