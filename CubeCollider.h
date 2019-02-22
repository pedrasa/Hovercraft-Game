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
class CubeCollider : public Collider
{
public:
	protected:
	public:
		virtual bool collidesWith(Collider* other); ///<pure virtual function. very collider must implement collidesWith, which calculates whethwer this collider collides with other.
		float length = 0.0, width = 0.0, height = 0.0;
		/* Every collider must implement the following pure virtual function or otherwise cause a compile error.*/
		float minX();
		float maxX();
		float minY();
		float maxY();
		float minZ();
		float maxZ();
	    CubeCollider(glm::vec3 * centre, float cubeWidth, float cubeHeight, float cubeLength);
	    ~CubeCollider();
		void Draw();
};

