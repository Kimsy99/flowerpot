#include <GL/glut.h>
#include "GLObject.h"

/**
 * Setup to draw the object.
 */
void GLObject::beginDraw()
{
	glPushMatrix();
	glTranslatef(x, y, z);
	draw();
	glPopMatrix();
}

/**
 * Rotates the object along the x-axis.
 */
void GLObject::rotateX(float degrees) const
{
	glRotatef(degrees, 1, 0, 0);
}

/**
 * Rotates the object along the y-axis.
 */
void GLObject::rotateY(float degrees) const
{
	glRotatef(degrees, 0, 1, 0);
}

/**
 * Rotates the object along the z-axis.
 */
void GLObject::rotateZ(float degrees) const
{
	glRotatef(degrees, 0, 0, 1);
}