#pragma once

#include <map>
#include <GL/glut.h>
#include "GLObject.h"

class DaisyCenter;
class Leaf;

class Stem : public GLObject
{
		const int stemPartCount;
		const float stemPartHeight;
		DaisyCenter* daisyCenter;
		std::map<int, Leaf*> leaves;
		
		float stemPartGrowth = 0;
		float dCurvingDirection = 0;
		float dCurveAngleFactor = 0;
		float curvingDirection = 0;
		float curveAngleFactor = 0;
		float curvingAngle = 0;
		float time = 0;
		
	public:
		Stem(float x, float y, float z, int stemPartCount, float stemPartHeight);
		void simulateWind();
		void grow();
		
	protected:
		void draw() override;
};