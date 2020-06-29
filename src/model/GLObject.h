#pragma once

class GLObject
{
	protected:
		/** The position of the object */
		float x, y, z;
		
		/** The rotation of the object in degrees */
		float rotateX, rotateY, rotateZ;
		
		GLObject(float x, float y, float z, float rotateX, float rotateY, float rotateZ) : x(x), y(y), z(z), rotateX(rotateX), rotateY(rotateY), rotateZ(rotateZ) {};
		virtual ~GLObject() {};
		
	public:
		virtual void draw() = 0;
		void applyTranslation() const;
		void applyRotation() const;
};