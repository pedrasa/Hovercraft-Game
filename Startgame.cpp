#ifndef OPENGL_INCLUDES
#define OPENGL_INCLUDES
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glext.h>
#pragma comment(lib, "glew32.lib")
#endif
#include <vector>;
#include "Obstacle.h";
#include "reader.h"
#include "Hovercraft.h";
#include "Grass.h";
#include "GameEngine/GameEngine.h"
#include "GameEngine/Hovercraft.h"
#include "GameEngine/Obstacle.h"
std::map <int, bool> GameObject::specialKeys;
std::map <char, bool> GameObject::keys;
Reader obj;
std::vector<GameObject*> gameobjects; //A list of game objects
using namespace std;
int oldTimeSinceStart=0;
int newTimeSinceStart=0;
double xx;

void Drawscene()
{
	int i, id;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	// Position the objects for viewing.
	gluLookAt(0.0, 0.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


	for (std::vector<GameObject*>::size_type i = 0; i != gameobjects.size(); i++) {
		gameobjects[i]->drawScene();
	}


	glPushMatrix();
	// Modeling transformations.
	glTranslatef(0.0, 0.0, -6.0);
	glRotatef(25, 1, 0, 0);
	glRotatef(45, 0, 1, 0);
	//glScalef(0.5, 0.5, 0.5);


	///this is for four vertices polygon
	glBegin(GL_QUADS);
	for (i = 0; i < obj.numFaces; i++)
	{
	id = obj.faces[i].id1;
	glNormal3d(obj.normal[id].x, obj.normal[id].y, obj.normal[id].z);
	glVertex3d(obj.vertex[id].x, obj.vertex[id].y, obj.vertex[id].z);
	id = obj.faces[i].id2;
	glNormal3d(obj.normal[id].x, obj.normal[id].y, obj.normal[id].z);
	glVertex3d(obj.vertex[id].x, obj.vertex[id].y, obj.vertex[id].z);
	id = obj.faces[i].id3;
	glNormal3d(obj.normal[id].x, obj.normal[id].y, obj.normal[id].z);
	glVertex3d(obj.vertex[id].x, obj.vertex[id].y, obj.vertex[id].z);
	id = obj.faces[i].id4;
	glNormal3d(obj.normal[id].x, obj.normal[id].y, obj.normal[id].z);
	glVertex3d(obj.vertex[id].x, obj.vertex[id].y, obj.vertex[id].z);
	}
	glEnd();
	glPopMatrix();

	glutSwapBuffers();
}

//initialization routine
void setup(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	unsigned int base = glGenLists(gameobjects.size() + 1); // Generate display list base. 

	for (std::vector<GameObject*>::size_type i = 0; i != gameobjects.size(); i++) {
		base = gameobjects[i]->setupDrawing(base);
	}

	for (std::vector<GameObject*>::size_type i = 0; i != gameobjects.size(); i++) {
		gameobjects[i]->start();
	}
	char filename[] = "Racetrack.obj";
	obj.LoadModel(filename);
	
}

//OpenGL window reshape routine
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	/* set up depth-buffering */
	glEnable(GL_DEPTH_TEST);

	/* turn on default lighting */
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	glLoadIdentity();
	gluPerspective(60.0, (float)w / float(h), 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}
void idle() {
	//Calculate delta time (in mili seconds).
	oldTimeSinceStart = newTimeSinceStart;
	newTimeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	int deltaTime = newTimeSinceStart - oldTimeSinceStart;

	//If the last frame was rendered less than 1 ms ago, the detalaTime will be 0 ms. This causes problems in calculations, so sleep for 1ms to adjust.
	if (deltaTime == 0) {
		Sleep(1);
		newTimeSinceStart = glutGet(GLUT_ELAPSED_TIME);
		deltaTime = newTimeSinceStart - oldTimeSinceStart;
	}

	//Run update for all game objects.
	for (std::vector<GameObject*>::size_type i = 0; i != gameobjects.size(); i++) {
		gameobjects[i]->update(deltaTime);
	}

	//ask glut for a redraw after all the updates
	glutPostRedisplay();
}


void animate() {

	// update state variables 
	xx += .001;

	// refresh screen 
	glutPostRedisplay();
}

void idle()
{
	glutPostRedisplay();
}

//main rooutine
int main(int argc, char **argv)
{
	GameEngine::initEngine(argc, argv, "Hovercraft tutorial", true);

	//Adding an Obstacle.
	GameEngine::addGameObject(new Obstacle(glm::vec3(0.0, 0.0, -25.0), { 0.55f, 0.27f, 0.07f }));

	//Adding an Obstacle with different colour.
	GameEngine::addGameObject(new Obstacle(glm::vec3(5.0, 5.0, -25.0)));

	//Add a movable hovercraft.
	GameEngine::addGameObject(new Hovercraft(glm::vec3(0.0, -5.0, -25.0)), false);

	//Start the game engine.
	GameEngine::startEngine();

	return 0;
	glutIdleFunc(animate);
	//Lambda functions to link our code to glut's keydown and keyup. Our function deals with both regular and special keys in one.
	glutKeyboardFunc([](unsigned char key, int x, int y) {
		GameObject::keys[key] = true;
		//if we press escape, exit the game
		if (key == 27) {
			exit(0);
		}
	});

	glutKeyboardUpFunc([](unsigned char key, int x, int y) {
		GameObject::keys[key] = false;
	});

	glutSpecialFunc([](int key, int x, int y) {
		GameObject::specialKeys[key] = true;
	});

	glutSpecialUpFunc([](int key, int x, int y) {
		GameObject::specialKeys[key] = false;
	});
	GameEngine::addGameObject(new Grass(glm::vec3(0, 0, 0), glm::vec3(5, 0, 5)));
	GameEngine::addGameObject(new Obstacle(glm::vec3(0.0, 0.0, -2.0), { 0.55f, 0.27f, 0.07f }));
	GameEngine::addGameObject(new Obstacle(glm::vec3(4.0, 0.0, 4.0)));
	GameEngine::addGameObject(new Hovercraft(glm::vec3(-2, 0, 2)), false);
	glutIdleFunc(idle);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();
	xx = 0.0;

	glutMainLoop();
}