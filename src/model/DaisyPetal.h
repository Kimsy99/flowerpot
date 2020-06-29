#pragma once

#include "GLObject.h"

class DaisyPetal : public GLObject
{
	public:
		DaisyPetal(float x, float y, float z, float rotateX, float rotateY, float rotateZ) : GLObject(x, y, z, rotateX, rotateY, rotateZ) {};
		
		void draw() override;
};