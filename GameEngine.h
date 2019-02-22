#pragma once
#include "GameObject.h"
#include <vector>
class GameEngine
{
private:
	static std::vector<GameObject*> gameobjects; ///<Vector of (pointers to) game objects: all the objects in the game.
	static void updateGame(); ///<Function that updates the game state, by updating all game objects and checking for collision.
	static int oldTimeSinceStart; ///<The old time since the start of the game (from previous frame) for delta tikme calculation.
	static int newTimeSinceStart; ///<The time since the start of the game  for delta tikme calculation.
	static GameObject* cameraFollow; ///<Pointer to an object that the camera will follow.
	static bool debugMode;
	static unsigned int base; // Generate display list base.
public:
	GameEngine();
	~GameEngine();
	static void initEngine(int argc, char **argv, const char* windowTitle = "New Game", bool debugMode = false, int width = 500, int height = 500); ///<Initialises the engine, initilising glut and OpenGL.
	static void displayFunc();
	static void reshapeFunc(int w, int h);
	static void addGameObject(GameObject* gameobject, bool camFollow = false); ///<Adds a GameObject to the game.
	static void startEngine(); ///<Start the engine (and the main game loop).
	static void cleanup(); ///<Function to clean up and delete any pointers and anything else when the game exists to prevent memory leaks.
};

