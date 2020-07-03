
#include <GL/glut.h>
#include <GL/gl.h>
#ifdef Q_OS_WIN
#include <gl/glu.h>
#endif
#include <GL/glu.h>
#include "mathhelper.h"
#include "Shadow.h"

void Shadow::createShadow(){
	const unsigned int shadow_width = 1024, shadow_height=1024;
	unsigned int depthMapFBO;
	glGenFramebuffers(1, &depthMapFBO);
}
