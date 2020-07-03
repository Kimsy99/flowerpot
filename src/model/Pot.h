#pragma once

#include "GLObject.h"

class Pot : public GLObject
{
	public:
		Pot(float x, float y, float z) : GLObject(x, y, z) {};
		
	protected:
		void draw() override;
};