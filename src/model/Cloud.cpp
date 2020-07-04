#include <GL/glut.h>
#include "Cloud.h"
#include "../util/colors.h"

static void cuboid(float tx, float ty, float tz, float width, float height, float across)
{
	glTranslatef(tx, ty, tz);
	glScalef(width, height, across);
	glutSolidCube(1);
}

void Cloud::draw()
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	
	glColor4f(1, 1, 1, 0.5F);
	cuboid(x, y, z, width, 1.5F, across);
	glDisable(GL_CULL_FACE);
}