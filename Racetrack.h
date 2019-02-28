#pragma once
#include "GameObject.h"
#include "reader.h"
#include "getbmp.h"
class Racetrack:public GameObject
{
public:
	Racetrack(glm::vec3 position);
	~Racetrack();
	static void setup(void);
	static void animate();
	void drawScene();
	unsigned int setupDrawing(unsigned int listBase);
	void start();
	void update(int deltaTime);
};

