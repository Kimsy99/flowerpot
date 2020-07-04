#pragma once

#include <vector>
#include "GLObject.h"

class DaisyPetal;

class DaisyCenter : public GLObject
{
		std::vector<DaisyPetal*> petals;
		
	public:
		float bloomFactor = 0;
		
		DaisyCenter(float x, float y, float z);
		
	protected:
		void draw() override;
};