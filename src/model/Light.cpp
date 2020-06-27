/*
 * light.cpp
 *
 *  Created on: 26 Jun 2020
 *      Author: Kim Sheng Yong
 */

#include <iostream>
#include "Light.h"
void Light::startLighting() const{
	glLoadIdentity();	// Reset the currently specified matrix as a unit matrix
		const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
	    const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
	    const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	    const GLfloat light_position[] = { GLfloat(rotateAngle), 100.0f, 0.0f, 1.0f};

	    const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
	    const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
	    const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
	    const GLfloat high_shininess[] = { 100.0f };

	    glEnable(GL_LIGHT0);                                            // Turn on lighting
	    glEnable(GL_NORMALIZE);
	    glEnable(GL_COLOR_MATERIAL);
	    glEnable(GL_LIGHTING);

	    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
	    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
	    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
	    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
	    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
	    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
		glEnable(GL_DEPTH_TEST);				// Open depth test
}
void Light::shiftLighting(int changingAngle){
	this->rotateAngle = (this->rotateAngle+changingAngle) % 360;
	std::cout << "Lighting Angle Now " << this->rotateAngle << std::endl;
	glutPostRedisplay();
}
