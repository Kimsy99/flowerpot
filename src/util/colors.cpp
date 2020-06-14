#include <GL/glut.h>
#include "colors.h"

const int RED = 0;
const int WHITE = 1;
const int ORANGE = 2;
const int YELLOW = 3;
const int DARK_GREEN = 4;
const int BROWN = 5;

void setColor(int color_code)
{
	switch (color_code)
	{
		case RED:
			glColor3f(1, 0, 0);
			break;
		case WHITE:
			glColor3f(1, 1, 1);
			break;
		case ORANGE:
			glColor3f(1, 0.6823F, 0);
			break;
		case YELLOW:
			glColor3f(1, 1, 0);
			break;
		case DARK_GREEN:
			glColor3f(0, 0.6705F, 0.0117F);
			break;
		case BROWN:
			glColor3f(0.5686F, 0.47843F, 0);
			break;
	}
}