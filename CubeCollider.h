#pragma once
#pragma once
#include "Collider.h"
/* OPENGL_INCLUDES */
#ifndef OPENGL_INCLUDES
#define OPENGL_INCLUDES
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>
#pragma comment(lib, "glew32.lib") 
#endif
class CubeCollider
{
public:
	protected:
	public:
		virtual bool collidesWith(Collider* other); ///<pure virtual function. very collider must implement collidesWith, which calculates whethwer this collider collides with other.
		float length = 0.0, width = 0.0, height = 0.0;
		/* Every collider must implement the following pure virtual function or otherwise cause a compile error.*/
		virtual float minX() = 0; ///<Lowest x value for the collider. Must override in inherited classes.
		virtual float maxX() = 0; ///<Highest x value for the collider. Must override in inherited classes.
		virtual float minY() = 0; ///<Lowest y value for the collider. Must override in inherited classes.
		virtual float maxY() = 0; ///<Highest y value for the collider. Must override in inherited classes.
		virtual float minZ() = 0; ///<Lowest z value for the collider. Must override in inherited classes.
		virtual float maxZ() = 0; ///<Highest z value for the collider. Must override in inherited classes.
		virtual void Draw() = 0; ///<Draw method for debug mode. Must override in inherited classes.
	    CubeCollider(glm::vec3 * centre, float cubeWidth, float cubeHeight, float cubeLength);
	    ~CubeCollider();
		void Draw();
};

