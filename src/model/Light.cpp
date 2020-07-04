#include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include "Light.h"
#include "../util/mathhelper.h"
#include "../util/colors.h"
/*
 * light.cpp
 *
 *  Created on: 26 Jun 2020
 *      Author: Kim Sheng Yong
 */

/**
 * Apply lighting to the world
 */
void Light::update() const
{
	float lightLevel;
	if (shineAngle < 45)
		lightLevel = mh::sind(shineAngle*2);
	else if (shineAngle < 135)
		lightLevel = 1;
	else if (shineAngle < 180)
		lightLevel = mh::cosd((shineAngle - 135)*2);
	else
		lightLevel = 0;
	// Reset the currently specified matrix as a unit matrix
	const GLfloat light_ambient[] = {0.06F + lightLevel*0.2F, 0.06F + lightLevel*0.2F, 0.1F + lightLevel*0.16F, 1};
	const GLfloat light_diffuse[] = {lightLevel, lightLevel, lightLevel, 1};
	const GLfloat light_specular[] = {lightLevel, lightLevel, lightLevel, 1};
	const GLfloat light_position[] = {mh::cosd(shineAngle), mh::sind(shineAngle), 0, 0};
	
	const GLfloat mat_ambient[] = {0.7F, 0.7F, 0.7F, 1.0F};
	const GLfloat mat_diffuse[] = {0.8F, 0.8F, 0.8F, 1.0F};
	const GLfloat mat_specular[] = {1.0F, 1.0F, 1.0F, 1.0F};
	const GLfloat high_shininess[] = {100.0F};
	
	glEnable(GL_LIGHT0); // Turn on lighting
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	
	glPushMatrix();
		glTranslatef(mh::cosd(shineAngle)*100, mh::sind(shineAngle)*100, 0.0f);
		setColor(SUN);
		glutSolidSphere(10, 40, 40);
	glPopMatrix();
}

void Light::shiftLighting(int dtheta)
{
	shineAngle += dtheta;
	shineAngle = (shineAngle + 360)%360;
	std::cout << "Lighting Angle Now " << shineAngle << std::endl;
}
