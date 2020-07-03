#pragma once

#include <vector>
#include "GLObject.h"
#include "Stem.h"

class Pot : public GLObject
{
		std::vector<Stem*> stems;
		
	public:
		Pot(float x, float y, float z);
		
	protected:
		void draw() override;
};