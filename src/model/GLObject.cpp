#include <GL/glut.h>
#include "GLObject.h"

/**
 * Represents an OpenGL object in the world that could be drawn.
 */

void GLObject::applyTranslation() const
{
	glTranslatef(x, y, z);
}

void GLObject::applyRotation() const
{
	glRotatef(rotateX, 1, 0, 0);
	glRotatef(rotateY, 0, 1, 0);
	glRotatef(rotateZ, 0, 0, 1);
}