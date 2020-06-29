#include <GL/glut.h>
#include "DaisyPetal.h"
#include "../util/colors.h"

void DaisyPetal::draw()
{
	glPushMatrix();
		
	applyTranslation();
	applyRotation();
	glScalef(1, 0.18F, 0.001F);
	
	setColor(WHITE);
	glutSolidSphere(0.4F, 30, 30);
	
	glPopMatrix();
}