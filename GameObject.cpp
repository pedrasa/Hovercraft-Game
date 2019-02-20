#include "GameObject.h"



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
}
