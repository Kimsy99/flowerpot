#pragma once

#include "GLObject.h"

class Leaf : public GLObject
{
		float rotation;
		
	public:
		float growthFactor = 0;
		
		Leaf();
		
	protected:
		void draw() override;
};