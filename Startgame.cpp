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
Reader obj;
using namespace std;
double xx;

void Drawscene()
{
	int i, id;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	// Position the objects for viewing.
	gluLookAt(0.0, 0.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

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

void animate() {

	// update state variables 
	xx += .001;

	// refresh screen 
	glutPostRedisplay();
}


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
	glutIdleFunc(animate);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();
	xx = 0.0;

	glutMainLoop();
}