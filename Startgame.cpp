#ifndef OPENGL_INCLUDES
#define OPENGL_INCLUDES
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glext.h>
#pragma comment(lib, "glew32.lib")
#endif
#include "Obstacle.h";
#include "reader.h"
Reader obj;

using namespace std;

double xx;

Obstacle firstObstacle = Obstacle(glm::vec3(0, 0, 0));
Obstacle secondObstacle = Obstacle(glm::vec3(2, 2, 2));


void Drawscene()
{
	int i, id;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	// Position the objects for viewing.
	gluLookAt(0.0, 0.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	//grass field
	glPushMatrix();
	glColor3f(0, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(5, 0, 5);
	glVertex3f(-5, 0, 5);
	glVertex3f(-5, 0, -5);
	glVertex3f(5, 0, -5);
	glEnd();
	glPopMatrix();

	firstObstacle.setColour({ 0.55f, 0.27f, 0.07f });
	secondObstacle.setColour({0.67f, 0.45f, 0.37f});
	firstObstacle.drawScene();
	secondObstacle.drawScene();

	//hovercraft
	glPushMatrix();
	glColor3f(-2, 0, 2);
	glTranslatef(-2, 0, 2);
	glRotatef(-90, 0, 1, 0);
	glutSolidCone(0.5, 0.75, 30, 30);
	glPushMatrix();
	glTranslatef(0, 0, -0.4);
	glColor3f(1, 1, 1);
	glutSolidCube(0.8);
	glPopMatrix();
	glPopMatrix();

	// Modeling transformations.
	glTranslatef(0.0, 0.0, -6.0);
	glRotatef(25, 1, 0, 0);
	glRotatef(45, 0, 1, 0);
	//glScalef(0.5, 0.5, 0.5);

	glBegin(GL_TRIANGLES);
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
	}
	glEnd();

	///this is for four vertices polygon
	/*glBegin(GL_QUADS);
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
	glEnd();*/

	glutSwapBuffers();
}

//initialization routine
void setup(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	unsigned int base = glGenLists(2);
	base = firstObstacle.setupDrawing(base);
	base = secondObstacle.setupDrawing(base);
	char filename[] = "Racetrack.obj";
	obj.LoadModel(filename);
	
	firstObstacle.start();
	secondObstacle.start();
}

//OpenGL window reshape routine
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	/* set up depth-buffering */
	glEnable(GL_DEPTH_TEST);

	/* turn on default lighting */
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLoadIdentity();
	gluPerspective(60.0, (float)w / float(h), 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}


void animate() {

	/* update state variables */
	xx += .001;

	/* refresh screen */
	glutPostRedisplay();
}

//keyboard input processing routine
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

void idle()
{
	glutPostRedisplay();
}

//main rooutine
int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hovercraft Program");
	glutDisplayFunc(Drawscene);
	glutReshapeFunc(resize);
	//glutIdleFunc(animate);
	glutKeyboardFunc(keyInput);
	glutIdleFunc(idle);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();
	xx = 0.0;

	glutMainLoop();
}