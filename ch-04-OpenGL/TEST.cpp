#include "stdafx.h"
#include <windows.h>
#include <gl/glut.h>
void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT );
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POINTS);
		glVertex2i(0,0);
	glEnd();
	glFlush();
}
int _tmain(int argc, _TCHAR* argv[])
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Simple");
	glutDisplayFunc(RenderScene);
	glutMainLoop();
	return 0;
}
