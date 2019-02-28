#include "Racetrack.h"
using namespace std;
Reader obj;
double xx;
static unsigned int texture[2];
Racetrack::Racetrack(glm::vec3 position) :GameObject(position)
{
}

Racetrack::~Racetrack()
{
}

void Racetrack::setup(void)
{
	char filename[] = "Racetrack.obj";
	obj.LoadModel(filename);
	if (obj.numPts == 0)
	{
		cout << "File did not load" << endl;
	}
}

void Racetrack::animate()
{
	// update state variables 
	xx += .001;

	// refresh screen 
	glutPostRedisplay();
}

void Racetrack::drawScene()
{
	glPushMatrix();

	glColor3f(1, 0, 0);
	glTranslatef(this->position.x, this->position.y, this->position.z);
	glScalef(12, 0.0, 12);
	glCallList(this->base); // Draw grass.
	glPopMatrix(); // End draw grass.
}

unsigned int Racetrack::setupDrawing(unsigned int listBase)
{
	int i, id;
	setup();
	this->base = listBase;
	glNewList(this->base, GL_COMPILE);
	glPushMatrix();
	glBegin(GL_QUADS);
	for (i = 0; i < obj.numFaces; i++)
	{
		id = obj.faces[i].id1;
		//glNormal3d(obj.normal[id].x, obj.normal[id].y, obj.normal[id].z);
		glVertex3d(obj.vertex[id].x, obj.vertex[id].y, obj.vertex[id].z);
		id = obj.faces[i].id2;
		//glNormal3d(obj.normal[id].x, obj.normal[id].y, obj.normal[id].z);
		glVertex3d(obj.vertex[id].x, obj.vertex[id].y, obj.vertex[id].z);
		id = obj.faces[i].id3;
		//glNormal3d(obj.normal[id].x, obj.normal[id].y, obj.normal[id].z);
		glVertex3d(obj.vertex[id].x, obj.vertex[id].y, obj.vertex[id].z);
		id = obj.faces[i].id4;
		//glNormal3d(obj.normal[id].x, obj.normal[id].y, obj.normal[id].z);
		glVertex3d(obj.vertex[id].x, obj.vertex[id].y, obj.vertex[id].z);
	}
	glEnd();
	glPopMatrix();
	glEndList();
	return this->base + 1;
	animate();
	xx = 0.0;
}

void Racetrack::start()
{
}

void Racetrack::update(int deltaTime)
{
}
