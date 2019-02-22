#pragma once
#include "GameObject.h"
#include <cmath>
#include<glm/gtx/rotate_vector.hpp>
#define TURNING_SPEED 90.0 //<turning speed in degrees per second
#define MOVE_SPEED 40.0 //<move speed in coordinate units per second

class Hovercraft:public GameObject
{
public:
	Hovercraft(glm::vec3 position);
	~Hovercraft();
	Collider* collider = NULL;  ///<Pointer to a collider for the game object. Initially NULL to indicate that we do not want to calculate collisions.
	glm::vec3 startingHeading = heading; ///<Starting facing direction of the Hovercraft.
	float rotationAngle = 0.0; ///<Rotation angle for our Hovercraft
	float pitchAngle = 0.0; ///<Pitch angles for our Hovercraft
	void drawScene();
	void start();
	void update(int deltaTime);
	unsigned int setupDrawing(unsigned int listBase);
	glm::vec3 startingHeading = heading; ///<Starting facing direction of the Hovercraft.
	float rotationAngle, pitchAngle = 0.0; ///<Rotation and pitch angles for our Hovercraft
	void collides(Collider * other); ///<Override method that reacts to a collision.
};

