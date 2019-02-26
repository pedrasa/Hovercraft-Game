#ifndef OPENGL_INCLUDES
#define OPENGL_INCLUDES
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glext.h>
#pragma comment(lib, "glew32.lib")
#endif
#include "Obstacle.h";
#include "reader.h"
#include "Hovercraft.h";
#include "Grass.h";
#include "GameEngine.h";
//main rooutine
int main(int argc, char **argv)
{
	GameEngine::initEngine(argc, argv, "Hovercraft tutorial", true);

	//Adding grass field.
	GameEngine::addGameObject(new Grass(glm::vec3(0, 0, 0), glm::vec3(5, 0, 5)));

	//Adding an Obstacle.
	GameEngine::addGameObject(new Obstacle(glm::vec3(0.0, 0.0, -25.0), { 0.55f, 0.27f, 0.07f }));

	//Adding an Obstacle with different colour.
	GameEngine::addGameObject(new Obstacle(glm::vec3(5.0, 5.0, -25.0)));

	//Add a movable hovercraft.
	GameEngine::addGameObject(new Hovercraft(glm::vec3(0.0, -5.0, -25.0)), false);

	//Start the game engine.
	GameEngine::startEngine();

    return 0;
}