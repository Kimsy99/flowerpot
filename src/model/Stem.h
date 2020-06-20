#pragma once

#include <GL/glut.h>

class Stem
{
		float xTrans;
		float yTrans;
		float zTrans;
		float height;
		float rotateAngle;
	public:
		Stem(float xTrans, float yTrans, float zTrans, float height, float rotateAngle)
		{
			this->xTrans = xTrans;
			this->yTrans = yTrans;
			this->zTrans = zTrans;
			this->height = height;
			this->rotateAngle = rotateAngle;
		}
		
		void showStem() const;
};