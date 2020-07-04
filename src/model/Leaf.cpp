#include <cmath>
#include <GL/glut.h>
#include "Leaf.h"
#include "../util/mathhelper.h"
#include "../util/colors.h"

Leaf::Leaf() : GLObject(0, 0, 0)
{
	rotation = mh::frandom(0, 360);
}

void Leaf::draw()
{
	const int DIVISIONS = 16;
	glScalef(0.5F*growthFactor, 0.5F*growthFactor, 0.5F*growthFactor);
	rotateY(rotation);
	
	// Draw leaf-half 1
	glPushMatrix();
	glColor3f(16.0F/255, 115.0F/255, 18.0F/255);
	rotateX(-30);
	glNormal3f(0, 1, 0);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i <= DIVISIONS; ++i)
	{
		float theta = 60 + 60.0F*i/DIVISIONS;
		glVertex3f(0.5F + mh::cosd(theta), 0, -sqrt(3)/2 + mh::sind(theta));
	}
	glVertex3f(1, 0, 0);
	glEnd();
	glPopMatrix();
	
	// Draw leaf-half 2
	glPushMatrix();
	glColor3f(14.0F/255, 140.0F/255, 17.0F/255);
	rotateX(30);
	glNormal3f(0, 1, 0);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i <= DIVISIONS; ++i)
	{
		float theta = 240 + 60.0F*i/DIVISIONS;
		glVertex3f(0.5F + mh::cosd(theta), 0, sqrt(3)/2 + mh::sind(theta));
	}
	glVertex3f(0, 0, 0);
	glEnd();
	glPopMatrix();
	
	glFlush();
}