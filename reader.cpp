//reader.cpp
#include <GL/freeglut.h>
#include <fstream>
#include <iostream>
#include <string>

#include "reader.h"

using namespace std;

Reader::Reader()
{
	numPts = 0;
	for (int i = 0; i < 5000; i++) {
		vertex[i].x = 0;
		vertex[i].y = 0;
		vertex[i].z = 0;

		texCoord[i].x = 0;
		texCoord[i].y = 0;
		texCoord[i].z = 0;
	}

	for (int i = 0; i < 5000; i++) {
		faces[i].id1 = 0;
		faces[i].id2 = 0;
		faces[i].id3 = 0;
		faces[i].id4 = 0;

		texfaces[i].id1 = 0;
		texfaces[i].id2 = 0;
		texfaces[i].id3 = 0;
		texfaces[i].id4 = 0;
	}
}

Reader::~Reader()
{

}

void Reader::loadVertex(char* filename)
{
	ifstream file;
	file.open(filename);

	string str;

	while (!file.eof()) //while we are still in the file
	{
		getline(file, str); //move one line down
		if (str[0] == 'v'&&str[1] != 't') break; //if we have a vertex line, stop
	}

	int v = 0;

	while (str[0] == 'v'&&str[1] != 't') {

		//convert data into X,Y,Z
		str[0] = ' ';
		sscanf_s(str.c_str(), "%f %f %f ",							// Read floats from the line: v X Y Z
			&vertex[v].x,
			&vertex[v].y,
			&vertex[v].z);

		v++;
		getline(file, str);
	}

	numPts = v;
}

void Reader::LoadTexCoord(char* filename)
{
	ifstream file;
	file.open(filename);

	string str;

	while (!file.eof()) //while we are still in the file
	{
		getline(file, str); //move one line down
		if (str[0] == 'v'&&str[1] == 't') break; //if we have a vertex line, stop
	}

	int v = 0;

	while (str[0] == 'v'&&str[1] == 't') {

		//convert data into X,Y,Z
		str[0] = ' '; str[1] = ' ';
		/*sscanf(str.c_str(), "%f %f",							// Read floats from the line: vt X Y
			&texCoord[v].x,
			&texCoord[v].y);*/

		sscanf_s(str.c_str(), "%f %f %f",							// Read floats from the line: vt X Y Z
			&texCoord[v].x,
			&texCoord[v].y,
			&texCoord[v].z);

		v++;
		getline(file, str);
	}

	numPts = v;
}

void Reader::LoadFace(char *filename)
{
	int count;
	ifstream file;
	file.open(filename);

	string str;

	while (true)
	{
		getline(file, str);
		if (str[0] == 'f') {
			break;
		}
	}

	count = 0;
	while (str[0] == 'f')
	{
		str[0] = ' ';
		/*sscanf_s(str.c_str(), "%d %d %d",
			&faces[count].id1,
			&faces[count].id2,
			&faces[count].id3);*/

		///this is for four vertice polygon
		sscanf_s(str.c_str(), "%d/%d %d/%d %d/%d %d/%d",
			&faces[count].id1, &texfaces[count].id1,
			&faces[count].id2, &texfaces[count].id2,
			&faces[count].id3, &texfaces[count].id3,
			&faces[count].id4, &texfaces[count].id4 );

		faces[count].id1--;
		faces[count].id2--;
		faces[count].id3--;
		faces[count].id4--;

		texfaces[count].id1--;
		texfaces[count].id2--;
		texfaces[count].id3--;
		texfaces[count].id4--;

		count++;

		getline(file, str);
	}

	numFaces = count;
}

void Reader::LoadModel(char *filename)
{
	loadVertex(filename);
	LoadTexCoord(filename);
	LoadFace(filename);

}

