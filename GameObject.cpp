#include "GameObject.h"

std::map <int, bool> specialKeys;
std::map <char, bool> keys;

GameObject::GameObject(glm::vec3 pos) 
{
	this->position = pos;
}


GameObject::~GameObject()
{
}

unsigned int GameObject::setupDrawing(unsigned int listBase)
{
	return 0;
}


void GameObject::drawScene()
{
	glPushMatrix();
	glTranslatef(this->position.x, this->position.y, this->position.z);
	glCallList(this->base);
	glPopMatrix();
}
