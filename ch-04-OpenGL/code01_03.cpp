// gl06.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <math.h>

// 추가로 요구되는 변수
// Time variables in millisecond
clock_t StartTime, PreviousTime, CurrentTime, TotalElapsedTime, DiffTime;
// Time variables in second
float dT = 0; // time difference between the current frame and the previous frame
float cT = 0; // current time ( time spent since the execution of the program )

// 초기화 작업
float angle_s = 0;
float angle_m = 0;
float angle_h = 0;
void Init(void) {
	StartTime = PreviousTime = clock();
}


void Draw(int i)
{
	double d;
	glPushMatrix();
	glRotatef(i*6, 0,0,1);
	if(i%5==0) d=2.0;
	else d = 1.0;
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	CurrentTime = clock();
	TotalElapsedTime = CurrentTime - StartTime;
	DiffTime = CurrentTime - PreviousTime;
	PreviousTime = CurrentTime;
	dT = double(DiffTime)/CLOCKS_PER_SEC;
	cT = int(TotalElapsedTime)/CLOCKS_PER_SEC;
	printf("elapsed Time = %d (%f)\n", TotalElapsedTime, cT);
	angle_s = cT*6.0;
	angle_m = (cT/60)*6.0;
	angle_h = (cT/3600)*6.0;

	glLoadIdentity();
	gluLookAt(0.0,0.0,5.0, 0.0,0.0,-1.0, 0.0f,1.0f,0.0f);
	for(int i=0; i<60; i++) { Draw(i); }
	// 초침
	glPushMatrix();
		glColor3f(0,0,0);
		glRotatef(-angle_s,0,0,1);
		glBegin(GL_LINES);
			glVertex3f(0.0,0.0,0.0);
			glVertex3f(0.0,1.0,0.0);
		glEnd();
	glPopMatrix();
	// 분침
	glPushMatrix();
		glColor3f(0,0,0);
		glRotatef(-angle_m,0,0,1);
		glBegin(GL_TRIANGLES);
			glVertex3f(-0.05, 0.0, 0.0);
			glVertex3f( 0.05, 0.0, 0.0);
			glVertex3f( 0.0 , 0.9, 0.0);
		glEnd();
	glPopMatrix();
	// 시침
	glPushMatrix();
		glColor3f(0,0,0);
		glRotatef(-angle_h,0,0,1);
		glBegin(GL_TRIANGLES);
			glVertex3f(-0.05, 0.0, 0.0);
			glVertex3f( 0.05, 0.0, 0.0);
			glVertex3f( 0.0 , 0.7, 0.0);
		glEnd();
	glPopMatrix();
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
	Init();
	glutMainLoop();
	return 0;
}
