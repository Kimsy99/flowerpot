#pragma once

#include <GL/glut.h>
#include "GLObject.h"

class Stem : public GLObject
{
		const int stemPartCount;
		const float stemPartHeight;
		float curvingDirection = 30;
		float curvingAngle = 5;
		
	public:
		Stem(float x, float y, float z, int stemPartCount, float stemPartHeight)
		 : GLObject(x, y, z), stemPartCount(stemPartCount), stemPartHeight(stemPartHeight) {}
		
	protected:
		void draw() override;
};