#pragma once

#include <GL/glut.h>

class Light
{
		int shineAngle;
	public:
		Light(float shineAngle) : shineAngle(shineAngle) {};
		
		void update() const;
		void shiftLighting(int dtheta);
};
