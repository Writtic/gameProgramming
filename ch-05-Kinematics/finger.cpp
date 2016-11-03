#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <gl/glut.h>
#include <math.h>

static float day = 0, time = 0, radian = 0;

void MyIdle()
{
  day  = (day + 0.005);
  time = (time + 0.005);
  glutPostRedisplay();
}

void MyDisplay()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


  glColor3f(1, 0.3f, 0.3f);
  glutWireCube(0.2);
  glPushMatrix();
  glTranslatef(0, 0.2, 0);
  glutWireSphere(0.1, 20, 16); // joint 1
  glRotatef(cos(day) * 45, 1, 0, 0);
  glPushMatrix();
  glTranslatef(0, 0.2, 0);
  glColor3f(0.5, 0.6, 0.7);
  glutWireCube(0.2);
  glPushMatrix();
  glTranslatef(0, 0.2, 0);
  glutWireSphere(0.1, 20, 16); // joint 2
  glRotatef(cos(time) * 45, 1, 0, 0);
  glPushMatrix();
  glTranslatef(0, 0.2, 0);
  glColor3f(0.9, 0.8, 0.2);
  glutWireCube(0.2);
  glPopMatrix();
  glPopMatrix();
  glPopMatrix();
  glPopMatrix();
  glutSwapBuffers();
}

void MyKey(unsigned char key, int x, int y)
{
  switch (key)
  {
  case 'q':
  case 27:
    exit(0);

  case 'd':
    day = (day + 10.);
    glutPostRedisplay();
    break;

  case 't':
    time = (time + 5.);
    glutPostRedisplay();
    break;
  }
}

void main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowSize(800, 800);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("gl06");


  glClearColor(1, 1, 1, 1);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1, 1, -1, 1, -2, 2);

  glutIdleFunc(MyIdle);

  glutDisplayFunc(MyDisplay);
  glutKeyboardFunc(MyKey);
  glEnable(GL_DEPTH_TEST);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  gluLookAt(0.2, 0.3, 1, 0, 0, 0, 0, 1, 0);

  glutMainLoop();
}
