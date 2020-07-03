#pragma once

/**
 * Represents an OpenGL object in the world that could be drawn.
 */
class GLObject
{
	protected:
		/** The world coordinates of the object */
		float x, y, z;
		
		GLObject(float x, float y, float z) : x(x), y(y), z(z) {};
		virtual ~GLObject() {};
		
		/**
		 * Actually draws the object.
		 */
		virtual void draw() = 0;
		
	public:
		/**
		 * Setup to draw the object.
		 */
		void beginDraw();
		
		/**
		 * Rotates the object along the x-axis.
		 */
		void rotateX(float degrees) const;
		
		/**
		 * Rotates the object along the y-axis.
		 */
		void rotateY(float degrees) const;
		
		/**
		 * Rotates the object along the z-axis.
		 */
		void rotateZ(float degrees) const;
};