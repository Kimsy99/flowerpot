#include <GL/glut.h>
#include "Pot.h"
#include "../util/colors.h"

Pot::Pot(float x, float y, float z) : GLObject(x, y, z)
{
	stems.push_back(new Stem(x, y + 3, z, 10, 0.1F));
}

void cuboid(float tx, float ty, float tz, float width, float height, float across)
{
	glTranslatef(tx, ty, tz);
	glScalef(width, height, across);
	glutSolidCube(1);
}

void potSide(float tx, float ty, float tz, float width, float height, float across)
{
	glPushMatrix();
	setColor(BROWN);
	cuboid(tx, ty + height/6, tz, width, height/3, across);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(194.0F/255, 120.0F/255, 16.0F/255);
	cuboid(tx, ty + 3*height/6 + 0.01F, tz, width, height/3, across);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(219.0F/255, 139.0F/255, 26.0F/255);
	cuboid(tx, ty + 5*height/6 + 0.02F, tz, width, height/3, across);
	glPopMatrix();
}

void Pot::draw()
{
	// Draw the pot
	potSide(0, 0, 0.5F, 3, 1, 0.15F);
	rotateY(90);
	potSide(0, 0, 1.5F, 1, 1, 0.15F);
	rotateY(90);
	potSide(0, 0, 0.5F, 3, 1, 0.15F);
	rotateY(90);
	potSide(0, 0, 1.5F, 1, 1, 0.15F);
	
	// Draw the soil
	rotateY(90);
	glColor3f(102.0F/255, 83.0F/255, 56.0F/255);
	cuboid(0, 0.5F, 0, 3, 0.5F, 1);
	
	// Draw the stems
	for (unsigned int i = 0; i < stems.size(); ++i)
	{
		
	}
}