#pragma once

#include "GLObject.h"

class Cloud : public GLObject
{
		const float width;
		const float across;
	public:
		Cloud(float x, float y, float z, float width, float across)
		 : GLObject(x, y, z), width(width), across(across) {};
		
		void draw() override;
};