#pragma once

#include <GL/glut.h>

class Light
{
		int rotateAngle;
	public:
		Light(float rotateAngle)
		{
			this->rotateAngle = rotateAngle;
		}
		
		void startLighting() const;
		void shiftLighting(int changingAngle);
};
