#pragma once

#include <vector>
#include "GLObject.h"
#include "Stem.h"

class Pot : public GLObject
{
		std::vector<Stem*> stems;
		
	public:
		/**
		 * Initiatize the pot position then it will initialize the whole object position (GLObject)
		 */
		Pot(float x, float y, float z);
		
	protected:
		/**
		 * Draw the pot out
		 */
		void draw() override;
};
