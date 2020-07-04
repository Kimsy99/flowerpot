#include <iostream>
#include <vector>
#include <windows.h>
#include <GL/glut.h>
#include "util/camera.h"
#include "util/mathhelper.h"
#include "util/colors.h"
#include "controller/keycontroller.h"
#include "controller/mousecontroller.h"
#include "model/Pot.h"
#include "model/Stem.h"
#include "model/Light.h"
#include "model/DaisyCenter.h"
#include "model/Cloud.h"

// Global attributes
static const int WINDOW_WIDTH = 800;
static const int WINDOW_HEIGHT = 480;

Light light(45);
Camera camera(0, 3, 5);
float movementSpeed = 0.1F;
Pot pot(0, 0, 0);

/**
 * Called when the window is resized.
 */
void reshape(int window_width, int window_height)
{
	// Prevent a division by zero, when window is too short
	if (window_height == 0)
		window_height = 1;
	float aspect_ratio = window_width*1.0/window_height;

	glMatrixMode(GL_PROJECTION); // Use the projection matrix
	glLoadIdentity();

	glViewport(0, 0, window_width, window_height); // Set the viewport to be the entire window
	gluPerspective(45.0F, aspect_ratio, 0.1F, 120);
	glMatrixMode(GL_MODELVIEW); // Get back to MODELVIEW
}

/*
 * Draw Instruction text on screen
 */
void drawText(const char* text, int length, int x, int y)
{
	glMatrixMode(GL_PROJECTION);
	double* matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, y);
	for (int i = 0; i < length; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
	delete[] matrix;
}

/**
 * Display function
 */
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(135.0/255*light.lightLevel, 206.0/255*light.lightLevel, 235.0/255*light.lightLevel, 1.0);
	
	camera.update();
	light.update();
	
	pot.beginDraw();
	
	light.toggleSpecular(false);
	glPushMatrix();
	setColor(DARK_GREEN);
	glBegin(GL_QUADS);
	glVertex3f(-100, 0, -100);
	glVertex3f(-100, 0, 100);
	glVertex3f(100, 0, 100);
	glVertex3f(100, 0, -100);
	glEnd();
	glPopMatrix();
	
	static std::vector<Cloud*> clouds;
	if (clouds.empty())
	{
		for (int i = 0; i < 30; ++i)
			clouds.push_back(new Cloud(mh::irandom(-50, 50), 20, mh::irandom(-50, 50), mh::irandom(10, 20), mh::irandom(10, 20)));
	}
	for (unsigned int i = 0; i < clouds.size(); ++i)
		clouds.at(i)->beginDraw();
	
	// Draw text
	glDisable(GL_LIGHTING);
	setColor(WHITE);
	
	std::string text;
	text = "Press Alt + F4 to quit";
	drawText(text.data(), text.size(), 0, 122);
	text = "WASD / arrow keys to move the camera (hold Ctrl to move slower)";
	drawText(text.data(), text.size(), 0, 102);
	text = "Use mouse to look around";
	drawText(text.data(), text.size(), 0, 82);
	text = "<Space> to ascend the camera, <shift> to descend the camera";
	drawText(text.data(), text.size(), 0, 62);
	text = "Hold J and K keys to control sunlight position";
	drawText(text.data(), text.size(), 0, 42);
	text = "Press M key to toggle daylight cycle";
	drawText(text.data(), text.size(), 0, 22);
	text = "Press R key to reset blooming animation";
	drawText(text.data(), text.size(), 0, 2);

	glEnable(GL_LIGHTING);
	glutSwapBuffers();
}

/**
 * Main loop.
 */
void update(int index)
{
	handleInput();
	handleLighting();
	glutPostRedisplay();
	glutTimerFunc(1000/60, update, 0);
}

void init()
{
	// Register callbacks
	glutDisplayFunc(display);
	glutTimerFunc(1000/60, update, 0);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyListener);
	glutKeyboardUpFunc(keyUpListener);
	glutSpecialFunc(specialKeyListener);
	glutSpecialUpFunc(specialKeyUpListener);
	
	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF); // Don't repeat keys
	std::cout << std::boolalpha; // Make it so that it prints 'true' and 'false' instead of '1' and '0'
	
	glutMotionFunc(mouseMotionListener);
	glutPassiveMotionFunc(mouseMotionListener);
	glutWarpPointer(WINDOW_WIDTH/2, WINDOW_HEIGHT/2); // Move mouse to center
	
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL); // Set the type of depth-test
	glShadeModel(GL_SMOOTH); // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Nice perspective corrections
	glClearDepth(1.0F); // Set background depth to farthest
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); // Enable lighting
	glEnable(GL_LIGHT0); // Enable light #0
	glEnable(GL_LIGHT1); // Enable light #1
	glEnable(GL_NORMALIZE); // Automatically normalize normals
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - WINDOW_WIDTH)/2, (glutGet(GLUT_SCREEN_HEIGHT) - WINDOW_HEIGHT)/2);
	glutCreateWindow("Flowerpot");
	
	init();
	
	glutMainLoop();
}
