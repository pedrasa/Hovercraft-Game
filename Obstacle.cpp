#include "Obstacle.h"

Obstacle::Obstacle(glm::vec3 position, Colour col):GameObject(position)
{
	setColour(col);
}

Obstacle::~Obstacle()
{

}


void Obstacle::start()
{

}

void Obstacle::update(int deltaTime)
{

}

unsigned int  Obstacle::setupDrawing(unsigned int listBase)
{
	this->base = ++listBase;
	glNewList(this->base, GL_COMPILE);
	glPushMatrix();
	glColor3f(this->colour.r, this->colour.g, this->colour.b);
	glRotatef(-45, 1, 0, 0);
	glutSolidCone(0.5, 0.75, 30, 30);
	glPopMatrix();
	glEndList();
	return this->base;
}

void Obstacle::setColour(Colour col)
{
	this->colour = col;
}


