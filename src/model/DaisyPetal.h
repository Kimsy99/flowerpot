#pragma once

#include "GLObject.h"

class DaisyCenter;

class DaisyPetal : public GLObject
{
		DaisyCenter* parent;
		
		float radiusFromCenter;
		float rotation;
		
	public:
		DaisyPetal(DaisyCenter* parent, float radiusFromCenter, float rotation)
		 : GLObject(0, 0, 0), parent(parent), radiusFromCenter(radiusFromCenter), rotation(rotation) {};
		
	protected:
		void draw() override;
};