#pragma once

#include "GLObject.h"

class Pot : public GLObject
{
	public:
		/**
		 * Initiatize the pot position then it will initialize the whole object position (GLObject)
		 */
		Pot(float x, float y, float z) : GLObject(x, y, z) {};
		
	protected:
		/**
		 * Draw the pot out
		 */
		void draw() override;
};
