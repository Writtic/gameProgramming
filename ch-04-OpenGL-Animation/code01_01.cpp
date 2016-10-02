// gl06.cpp : Defines the entry point for the console application.
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
int time = 0;
void Draw(int i)
{
	double d;
	glPushMatrix();
	// 회전해서 그려줘!(좌표 설정)
	// 각각의 분마다 6도식 회전해서 그림
	glRotatef(i*6, 0,0,1);
	// 5개마다 삼각형의 크기가 커짐
	if(i%5==0) d=2.0;
	else d = 1.0;
	// 삼각형을 그림
	glBegin(GL_TRIANGLES);
		glVertex3f(-0.01*d, 1.0, 0.0);
		glVertex3f( 0.01*d, 1.0, 0.0);
		glVertex3f( 0.0 , 1.0-0.1*d, 0.0);
	glEnd();
	glPopMatrix();
}

void changeSize(int w, int h)
{
	if(h == 0) h = 1;
	float ratio = 1.0* w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45,ratio,1,1000);
	glMatrixMode(GL_MODELVIEW);
}
void renderScene(void)
{
	// 깨끗하게 만듦
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0,0.0,5.0, 0.0,0.0,-1.0, 0.0f,1.0f,0.0f);
	// 핵심
	// 반복문을 60번 돌며 드로우 함수 호출
	for(int i=0; i<60; i++) { Draw(i); }
	// 바늘을 그림
	glRotatef(time*-6, 0,0,1);
	glColor3f(0,0,0);
	glBegin(GL_LINES);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,1.0,0.0);
	glEnd();
	++time;
	if(time > 60){ time = 0;}
	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{
	if (key == 27) exit(0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("Animation Lecture - 00");
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutKeyboardFunc(processNormalKeys);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.8,0.8,1.0,1.0);
	glutMainLoop();
	return 0;
}
