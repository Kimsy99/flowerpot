#include <GL/glut.h>
#include "Pot.h"

void Pot::drawPot()
{
	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
	// Top face (y = 1.0f)
	// Define vertices in counter-clockwise (CCW) order with normal pointing out
	
	glColor3f(0.4f, 0.2f, 0.0f);     // Green
	//top soil
	glVertex3f(0.45f / 2, 0.4f / 2, -0.45f / 2);
	glVertex3f(-0.45f / 2, 0.4f / 2, -0.45f / 2);
	glVertex3f(-0.45f / 2, 0.4f / 2, 0.45f / 2);
	glVertex3f(0.45f / 2, 0.4f / 2, 0.45f / 2);
	// Bottom face (y = -1.0f)
	
	glColor3f(1.0f, 0.6f, 0.2f);
	glVertex3f(0.3f / 2, -0.5f / 2, 0.3f / 2);
	glVertex3f(-0.3f / 2, -0.5f / 2, 0.3f / 2);
	glVertex3f(-0.3f / 2, -0.5f / 2, -0.3f / 2);
	glVertex3f(0.3f / 2, -0.5f / 2, -0.3f / 2);
	
	// Front face  (z = 1.0f)
	glVertex3f(0.5f / 2, 0.5f / 2, 0.5f / 2);
	glVertex3f(-0.5f / 2, 0.5f / 2, 0.5f / 2);
	glVertex3f(-0.3f / 2, -0.5f / 2, 0.3f / 2);
	glVertex3f(0.3f / 2, -0.5f / 2, 0.3f / 2);
	
	// Back face (z = -1.0f)
	//lColor3f(1.0f, 1.0f, 0.0f);     // Yellow
	glVertex3f(0.3f / 2, -0.5f / 2, -0.3f / 2);
	glVertex3f(-0.3f / 2, -0.5f / 2, -0.3f / 2);
	glVertex3f(-0.5f / 2, 0.5f / 2, -0.5f / 2);
	glVertex3f(0.5f / 2, 0.5f / 2, -0.5f / 2);
	
	// Left face (x = -1.0f)
	// Blue
	glVertex3f(-0.5f / 2, 0.5f / 2, 0.5f / 2);
	glVertex3f(-0.5f / 2, 0.5f / 2, -0.5f / 2);
	glVertex3f(-0.3f / 2, -0.5f / 2, -0.3f / 2);
	glVertex3f(-0.3f / 2, -0.5f / 2, 0.3f / 2);
	
	// Right face (x = 1.0f)
	//glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
	glVertex3f(0.5f / 2, 0.5f / 2, -0.5f / 2);
	glVertex3f(0.5f / 2, 0.5f / 2, 0.5f / 2);
	glVertex3f(0.3f / 2, -0.5f / 2, 0.3f / 2);
	glVertex3f(0.3f / 2, -0.5f / 2, -0.3f / 2);
	
	glEnd();  // End of drawing
}