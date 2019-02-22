#include "Obstacle.h"
#include "CubeCollider.h"

Obstacle::Obstacle(glm::vec3 position, Colour col):GameObject(position)
{
	setColour(col);
	Obstacle::collider = new CubeCollider(&this->position, 2, 2, 2);
}

Obstacle::~Obstacle()
{
	delete Obstacle::collider;
	Obstacle::collider = NULL;
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
	return this->base + 1;
}

void Obstacle::setColour(Colour col)
{
	this->colour = col;
}

void Obstacle::collides(Collider* other) {
	if (debugMode) {
		std::cout << "Obstacle collides, Obstacle will be removed!" << std::endl;
	}
	this->active = false;
}


