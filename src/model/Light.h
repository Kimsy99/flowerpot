#pragma once

#include <GL/glut.h>

class Light
{
		/** Angle of the light source. */
		int shineAngle;
	public:
		float lightLevel = 0;
		bool sunlightCycle = false;
		
		Light(float shineAngle) : shineAngle(shineAngle) {};
		
		/**
		 * Apply lighting to the world.
		 */
		void update();
		
		/**
		 * Shift light source angle
		 */
		void shiftLighting(int dtheta);
		
		void toggleSpecular(bool flag);
};