#include "Grass.h"
static unsigned int texture[2];

Grass::Grass(const glm::vec3 & _pos, const glm::vec3 & _size) : GameObject(_pos) {
	size = _size;
}

unsigned int Grass::setupDrawing(unsigned int listBase) {
	loadExternalTextures();
	this->base = listBase;
	glNewList(this->base, GL_COMPILE);
	glPushMatrix();
	glColor3f(0, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(position.x + size.x, position.y, position.z + size.z);
	glVertex3f(position.x - size.x, position.y, position.z + size.z);
	glVertex3f(position.x - size.x, position.y, position.z - size.z);
	glVertex3f(position.x + size.x, position.y, position.z - size.z);
	glEnd();
	glPopMatrix();
	glEndList();
	return this->base + 1;
}

void Grass::drawScene() {
	glPushMatrix();
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); //GL_REPLACE //GL_MODULATE
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glCallList(this->base); // Draw grass.
	glDisable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glPopMatrix(); // End draw grass.

}

void Grass::start() {
}

void Grass::update(int deltaTime) {
}

void Grass::loadExternalTextures()
{
	// Local storage for bmp image data.
	BitMapFile *image[2];

	// Load the images.
	image[0] = getbmp("./alienscraft/grass.bmp");

	// Bind grass image to texture object texture[0]. 
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[0]->sizeX, image[0]->sizeY, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, image[0]->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}
