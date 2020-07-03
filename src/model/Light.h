#pragma once

#include <GL/glut.h>

class Light
{
		/**
		 * angle of the light source
		 */
		int rotateAngle;
	public:
		Light(float rotateAngle)
		{
			this->rotateAngle = rotateAngle;
		}
		
		/**
		 * Apply lighting on the world
		 */
		void startLighting() const;
		/**
		 * Shift light source angle
		 */
		void shiftLighting(int changingAngle);
};
