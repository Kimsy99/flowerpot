#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Camera.h"
#include "mathhelper.h"

/**
 * Moves the camera around.
 */
void Camera::translateCamera(float dx, float dy, float dz)
{
	this->x += dx;
	this->y += dy;
	this->z += dz;
}

/**
 * Moves the camera forward by d units (if negative, moves backwards instead). Does not affect
 * elevation.
 */
void Camera::moveForward(float d)
{
	translateCamera(d*mh::cosd(-yaw), 0, d*mh::sind(-yaw));
}

/**
 * Moves the camera left or right (positive means to the right, negative means to the left). Does
 * not affect elevation.
 */
void Camera::strafe(float d)
{
	translateCamera(d*mh::cosd(-(yaw - 90)), 0, d*mh::sind(-(yaw - 90)));
}

/**
 * Changes the elevation of the camera, i.e. moves the camera up or down (positive means upwards,
 * negative means downwards.
 */
void Camera::elevate(float d)
{
	translateCamera(0, d, 0);
}

/**
 * Changes the yaw of the camera.
 */
void Camera::rotateYaw(float dyaw)
{
	this->yaw += dyaw;
}

/**
 * Changes the pitch of the camera.
 */
void Camera::rotatePitch(float dpitch)
{
	this->pitch += dpitch;
	// Clamp between -90 to 90
	if (pitch < -90)
		pitch = -90;
	else if (pitch > 90)
		pitch = 90;
}

/**
 * Applies the view of the camera.
 */
void Camera::updateCamera()
{
	lx = mh::cosd(pitch)*mh::cosd(-yaw);
	ly = mh::sind(pitch);
	lz = mh::cosd(pitch)*mh::sind(-yaw);
	float upX = 0, upY = 1, upZ = 0;
	if (pitch == 90) // Looking straight up
	{
		upX = mh::cosd(-yaw + 180);
		upY = 0;
		upZ = mh::sind(-yaw + 180);
	}
	else if (pitch == -90) // Looking straight down
	{
		upX = mh::cosd(-yaw);
		upY = 0;
		upZ = mh::sind(-yaw);
	}
	gluLookAt(x, y, z, x + lx, y + ly, z + lz, upX, upY, upZ);
}
