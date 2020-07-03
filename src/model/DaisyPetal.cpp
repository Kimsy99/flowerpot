#include <GL/glut.h>
#include "GLObject.h"
#include "DaisyPetal.h"
#include "../util/colors.h"

void DaisyPetal::draw()
{
	rotateZ(rotation);
	glScalef(1, 0.18F, 0.001F);
	
	setColor(WHITE);
	glutSolidSphere(0.4F, 30, 30);
}