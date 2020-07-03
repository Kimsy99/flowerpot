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
		
		/**
		 * Moves the camera around.
		 */
		void translateCamera(float dx, float dy, float dz);
		
		/**
		 * Moves the camera forward by d units (if negative, moves backwards instead). Does not affect
		 * elevation.
		 */
		void moveForward(float d);
		
		/**
		 * Moves the camera left or right (positive means to the right, negative means to the left). Does
		 * not affect elevation.
		 */
		void strafe(float d);
		
		/**
		 * Changes the elevation of the camera, i.e. moves the camera up or down (positive means upwards,
		 * negative means downwards.
		 */
		void elevate(float d);
		
		/**
		 * Changes the yaw of the camera.
		 */
		void rotateYaw(float dyaw);
		
		/**
		 * Changes the pitch of the camera.
		 */
		void rotatePitch(float dpitch);
		
		/**
		 * Applies the view of the camera.
		 */
		void update();
};