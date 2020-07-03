#include "Stem.h"
#include "../util/mathhelper.h"
#include "../util/colors.h"

void Stem::draw()
{
	static GLUquadricObj* quadric = gluNewQuadric();
	setColor(DARK_GREEN);
	
	rotateY(curvingDirection);
	
	glPushMatrix();
	rotateX(-90);
	gluCylinder(quadric, 0.03F, 0.03F, stemPartHeight, 32, 32);
	glPopMatrix();
	
	for (int i = 1; i <= stemPartCount; i++)
	{
		float d = stemPartHeight*mh::sind(curvingAngle);
		glTranslatef(0, stemPartHeight*0.99F, 0);
		
		glPushMatrix();
		rotateZ(-curvingAngle*i);
		rotateX(-90);
		gluCylinder(quadric, 0.03F, 0.03F, stemPartHeight, 32, 32);
		glPopMatrix();
		
		glTranslatef(d*i, 0, 0);
	}
}