/*
 * Stem.cpp
 *
 *  Version: 1
 *  Updated: 20 Jun 2020
 *   Author: Mister_Bander
 */

#include "Stem.h"

void Stem::showStem() const
{
	GLUquadricObj* quadratic = gluNewQuadric();
	glColor3f(0.0f, 1.0f, 0.0f);
	glTranslatef(xTrans, yTrans, zTrans);
	glRotatef(-90, 1.0, 0.0, 0.0);
	gluCylinder(quadratic, 0.01f, 0.01f, 0.1, 32, 32);
	for (int i = 0; i < 20; i++)
	{
		glTranslatef(0.0f, 0.0f, height);
		glRotatef(rotateAngle, 1.0, 0.0, 0.0);
		gluCylinder(quadratic, 0.01f, 0.01f, height, 32, 32);
		//gluCylinder(quadratic, 0.01f,0.01,)
	}
}