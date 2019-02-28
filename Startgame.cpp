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
#include "Racetrack.h";
//main rooutine
int main(int argc, char **argv)
{
	GameEngine::initEngine(argc, argv, "Hovercraft tutorial", true);

	//Adding grass field.
	GameEngine::addGameObject(new Grass(glm::vec3(0, 0, 0), glm::vec3(1000, 0, 1000)));

	GameEngine::addGameObject(new Racetrack(glm::vec3(0, 0.8, 0)));

	//Adding an Obstacle.
	GameEngine::addGameObject(new Obstacle(glm::vec3(30.0, 1.5, -50.0), { 0.55f, 0.27f, 0.07f }));

	//Adding an Obstacle with different colour.
	GameEngine::addGameObject(new Obstacle(glm::vec3(5.0, 1.5, 165.0)));

	//Add a movable hovercraft.
	GameEngine::addGameObject(new Hovercraft(glm::vec3(20.0, 1.5, -55.0)), true);

	//Start the game engine.
	GameEngine::startEngine();

    return 0;
}