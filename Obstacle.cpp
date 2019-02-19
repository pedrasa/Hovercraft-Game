#include "Obstacle.h"


Obstacle::Obstacle(glm::vec3 position)
{
	this->position = position;
}

Obstacle::~Obstacle()
{

}

void Obstacle::drawScene()
{
	glPushMatrix();
	glColor3f(colour.r, colour.g, colour.b);
	glTranslatef(this->position.x, this->position.y, this->position.z);
	glCallList(this->base);
	glPopMatrix();
}

void Obstacle::start()
{

}

void Obstacle::update(int deltaTime)
{

}

unsigned int Obstacle::setupDrawing(unsigned int listBase)
{
	this->base = ++listBase;
	glNewList(this->base, GL_COMPILE);
	glPushMatrix();
	//glColor3f(r, g, b);

	glutSolidSphere(1.0, 40, 40);
	glPopMatrix();
	glEndList();
	return this->base;
}

void Obstacle::setColour(Colour col)
{
	this->colour = col;
}


