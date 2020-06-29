#include <iostream>
#include <GL/glut.h>
#include "GLObject.h"
#include "DaisyCenter.h"
#include "DaisyPetal.h"
#include "../util/colors.h"
#include "../util/mathhelper.h"

DaisyCenter::DaisyCenter(float x, float y, float z, float rotateX, float rotateY, float rotateZ)
 : GLObject(x, y, z, rotateX, rotateY, rotateZ)
{
	const int NUMBER_OF_PETALS = 24;
	for (int i = 0; i < NUMBER_OF_PETALS; ++i)
	{
		float rand = mh::frandom(0.65F, 0.75F);
		petals.push_back(DaisyPetal(rand*mh::cosd(i*360.0F/NUMBER_OF_PETALS), rand*mh::sind(i*360.0F/NUMBER_OF_PETALS), 0, 0, 0, i*360.0F/NUMBER_OF_PETALS));
	}
}

void DaisyCenter::draw()
{
	glPushMatrix();
	
	applyTranslation();
	applyRotation();
	glScalef(1, 1, 0.25F);
	
	setColor(YELLOW);
	glutSolidSphere(0.4F, 30, 30);
	
	for (unsigned int i = 0; i < petals.size(); ++i)
		petals.at(i).draw();
	
	glPopMatrix();
}