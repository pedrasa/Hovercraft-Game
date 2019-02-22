#pragma once
/* OPENGL_INCLUDES */
#ifndef OPENGL_INCLUDES
#define OPENGL_INCLUDES
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>
#pragma comment(lib, "glew32.lib") 
#endif 
#include <glm/glm.hpp>
# include <map>
#include <iostream>
#include "Collider.h" //gameobjects can have a collider

class GameObject
{
protected:
	unsigned int base;
public:
	static bool debugMode;
	bool active = true;
	Collider* collider = NULL;  ///<Pointer to a collider for the game object. Initially NULL to indicate that we do not want to calculate collisions.
	glm::vec3 heading = glm::vec3(0.0, 0.0, -1.0);  ///<Current heading (direction) the GameObject is facing.
	static std::map <int, bool> specialKeys;
	static std::map <char, bool> keys;  ///<Current heading (direction) the GameObject is facing.
	glm::vec3 position;///<Position of the gameobject.
	GameObject(glm::vec3 position);
	~GameObject();
	virtual void collides(Collider* other); ///<Virtual function to notify this game object that a collision has happened can be overridden (optional).
	virtual unsigned int setupDrawing(unsigned int listBase) = 0;
	virtual void drawScene(); ///Function to perform this object's part of the redraw work. The default version in GameObject will put the object in the right place and redraw it. This can be overridden.

	/* Every GameObject must implement the following pure virtual function or otherwise cause a compile error.*/
	virtual void start() = 0; ///<Pure virtual start function, run once when the engine starts.  Must override in inherited classes.
	virtual void update(int deltaTime) = 0; ///<Pure virtual update function, run periodicity to update the game state. Must override in inherited classes. ///<Virtual function to notify this game object that a collision has happened can be overridden (optional).
};
