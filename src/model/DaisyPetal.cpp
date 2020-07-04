#include <GL/glut.h>
#include "DaisyPetal.h"
#include "DaisyCenter.h"
#include "../util/colors.h"

void DaisyPetal::draw()
{
	rotateZ(rotation);
	glTranslatef(radiusFromCenter - 0.4F + (1 - parent->bloomFactor)*0.1F, 0, 0);
	rotateY(-20 - (1 - parent->bloomFactor)*110);
	glScalef(1 - (1 - parent->bloomFactor)*0.3F, 1, 1);
	glTranslatef(0.4F, 0, 0);
	glScalef(1, 0.18F, 0.001F);
	
	glColor3f(1 - (1 - parent->bloomFactor)*0.4F, 1 - (1 - parent->bloomFactor)*0.4F, parent->bloomFactor);
	glutSolidSphere(0.4F, 30, 30);
}