#include <GL/glut.h>
#include "colors.h"

const int RED = 0;
const int ORANGE = 1;
const int GOLDEN_ROD = 2;
const int YELLOW = 3;
const int DARK_GREEN = 4;
const int WHITE = 5;
const int BROWN = 6;

void setColor(int color_code)
{
	switch (color_code)
	{
		case RED:
			glColor3f(1, 0, 0);
			break;
		case ORANGE:
			glColor3f(1, 0.6823F, 0);
			break;
		case GOLDEN_ROD:
			glColor3f(0.98823F, 0.79216F, 0.01176F);
			break;
		case YELLOW:
			glColor3f(1, 1, 0);
			break;
		case DARK_GREEN:
			glColor3f(0, 0.6705F, 0.0117F);
			break;
		case WHITE:
			glColor3f(1, 1, 1);
			break;
		case BROWN:
			glColor3f(173.0F/255, 101.0F/255, 0);
			break;
	}
}