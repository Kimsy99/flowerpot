#include <iostream>
#include <windows.h>
#include <GL/glut.h>
#include "util/camera.h"
#include "util/mathhelper.h"
#include "controller/keycontroller.h"
#include "controller/mousecontroller.h"
#include "model/Pot.h"
#include "model/Stem.h"
#include "model/Light.h"
#include "model/DaisyCenter.h"

// Global attributes
static const int WINDOW_WIDTH = 800;
static const int WINDOW_HEIGHT = 480;

Light light(45);
Camera camera(0, 1, 5);
float movementSpeed = 0.1F;

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
	gluPerspective(45.0F, aspect_ratio, 0.1F, 100);
	glMatrixMode(GL_MODELVIEW); // Get back to MODELVIEW
//	light.startLighting();
}

void drawSnowMan()
{
	glColor3f(1, 1, 1);

	// Draw body
	glTranslatef(0, 0.75F, 0);
	glutSolidSphere(0.75F, 20, 20);

	// Draw head
	glTranslatef(0, 1, 0);
	glutSolidSphere(0.25F, 20, 20);

	// Draw eyes
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0.05F, 0.1F, 0.18F);
	glutSolidSphere(0.05F, 10, 10);
	glTranslatef(-0.1F, 0, 0);
	glutSolidSphere(0.05F, 10, 10);
	glPopMatrix();

	// Draw nose
	glColor3f(1, 0.5F, 0.5F);
	glutSolidCone(0.08F, 0.5F, 10, 2);
}
/*
 * Draw Instruction text on screen
 */
void drawText(const char *text, int length, int x, int y){
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0,800,0,600,-5,5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x,y);
	for(int i=0; i<length; i++){
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}

/**
 * Display function
 */
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	
	camera.update();
	light.update();
	
	// Set up flower pot
	static Pot pot(0, 0, 0);
	pot.beginDraw();
	
	// Set up stem
//	static Stem stem(0, 0.2F, 0, 3, 0.3F);
//	stem.beginDraw();
	
	glPushMatrix();
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
	glVertex3f(-100, 0, -100);
	glVertex3f(-100, 0, 100);
	glVertex3f(100, 0, 100);
	glVertex3f(100, 0, -100);
	glEnd();
	
	// Draw 36 snowmen
	for (int i = -3; i < 3; i++)
	{
		for (int j = -3; j < 3; j++)
		{
			glPushMatrix();
			glTranslatef(i*10.0 + 5, 0, j*10.0 + 5);
			drawSnowMan();
			glPopMatrix();
		}
	}
	
	static DaisyCenter daisy(0, 3, 0);
	daisy.beginDraw();
	

	glPopMatrix();


	std::string text;
	text ="Press alt + F4 to leave";
	drawText(text.data(), text.size(),0,0);

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
