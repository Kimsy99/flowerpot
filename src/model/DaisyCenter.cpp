#include <iostream>
#include <GL/glut.h>
#include "DaisyCenter.h"
#include "DaisyPetal.h"
#include "../util/colors.h"
#include "../util/mathhelper.h"

DaisyCenter::DaisyCenter(float x, float y, float z) : GLObject(x, y, z)
{
	const int NUMBER_OF_PETALS = 24;
	for (int i = 0; i < NUMBER_OF_PETALS; ++i)
	{
		float rand = mh::frandom(0.65F, 0.72F);
		petals.push_back(new DaisyPetal(this, rand, i*360.0F/NUMBER_OF_PETALS));
	}
}

void DaisyCenter::draw()
{
	glScalef(0.4F, 0.4F, 0.4F);
	rotateX(45);
	rotateZ(-90);
	rotateY(-90);
	
	glPushMatrix();
	glScalef(1, 1, 0.25F);
	setColor(GOLDEN_ROD);
	glutSolidSphere(0.4F, 30, 30);
	glPopMatrix();
	
	for (unsigned int i = 0; i < petals.size(); ++i)
		petals.at(i)->beginDraw();
}