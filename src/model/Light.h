#pragma once

#include <GL/glut.h>

class Light
{
		/** Angle of the light source. */
		int shineAngle;
		
	public:
		Light(float shineAngle) : shineAngle(shineAngle) {};
		
		/**
		 * Apply lighting to the world.
		 */
		void update() const;
		
		/**
		 * Shift light source angle
		 */
		void shiftLighting(int dtheta);
};
