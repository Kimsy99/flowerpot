#include <GL/glut.h>
#include "../util/Camera.h"

/**
 * Handles all mouse events.
 */

extern Camera camera;
static float sensitivity = 0.5F;

void mouseMotionListener(int mx, int my)
{
	int cx = glutGet(GLUT_WINDOW_WIDTH)/2;
	int cy = glutGet(GLUT_WINDOW_HEIGHT)/2;
	
	// Calculate movement distance
	int dx = mx - cx;
	int dy = my - cy;
	
	// Now orient the camera
	camera.rotateYaw(-dx*sensitivity);
	camera.rotatePitch(-dy*sensitivity);
	
	glutWarpPointer(cx, cy);
}