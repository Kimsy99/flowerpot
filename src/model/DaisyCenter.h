#pragma once

#include <vector>
#include "GLObject.h"
#include "DaisyPetal.h"

class DaisyCenter : public GLObject
{
		std::vector<DaisyPetal> petals;
	public:
		DaisyCenter(float x, float y, float z, float rotateX, float rotateY, float rotateZ);
		
		void draw() override;
};