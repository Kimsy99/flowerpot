#pragma once

#include "GLObject.h"

class DaisyPetal : public GLObject
{
		float rotation;
		
	public:
		DaisyPetal(float x, float y, float z, float rotation) : GLObject(x, y, z), rotation(rotation) {};
		
	protected:
		void draw() override;
};