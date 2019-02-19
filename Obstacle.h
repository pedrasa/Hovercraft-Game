#pragma once
#ifndef OPENGL_INCLUDES
#define OPENGL_INCLUDES
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>
#pragma comment(lib, "glew32.lib") 
#endif
#include <glm/glm.hpp>
struct Colour {
	float r, g, b;
};

class Obstacle
{
private :
	glm::vec3 position;
	unsigned int base;
	Colour colour = { 0.55f, 0.27f, 0.07f };
public:
	Obstacle(glm::vec3 position);
	~Obstacle();
	void drawScene();
	void start();
	void update(int deltaTime);
	unsigned int setupDrawing(unsigned int listBase);
	void setColour(Colour col);

};

