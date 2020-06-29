#pragma once

/**
 * Utility class that models the abstract idea of a camera. Contains useful functions for controlling
 * the camera such as moving the camera, and changing where the camera looks.
 */
class Camera
{
		/** The position of the camera */
		float x = 0, y = 1, z = 0;
		
		/**
		 * yaw represents the direction the camera is facing, ranges from 0 to 360 where 0 points eastwards
		 * and increases anti-clockwise
		 */
		float yaw = 0;
		/**
		 * pitch represents the direction the up-down angle of the camera, ranges from -90 to 90 where -90
		 * points directly downwards and 90 points directly upwards
		 */
		float pitch = 0;
		
		/** The look-at vector */
		float lx = 0, ly = 0, lz = -1;
	public:
		Camera() {};
		Camera(float x, float y, float z) : x(x), y(y), z(z) {}
		
		void translateCamera(float dx, float dy, float dz);
		void moveForward(float d);
		void strafe(float d);
		void elevate(float d);
		void rotateYaw(float dyaw);
		void rotatePitch(float dpitch);
		void updateCamera();
};