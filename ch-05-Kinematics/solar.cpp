#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <gl/glut.h>

static float day = 0, time = 0, vday = 0;
void MyIdle()
{
  day  = (day + .05);
  vday = (vday + .10);
  time = (time + .2);
  glutPostRedisplay();
}

void MyDisplay()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


  glColor3f(1, 0.3f, 0.3f);
  glutSolidSphere(0.2, 20, 16); // sun
  // glPushMatrix : 앞으로 이뤄질 변환에 대한 내용을 스텍에 저장
  // glPopMatrix : 변환전인 상위 트리로
  glPushMatrix();
  glRotatef(day, 0, 1, 0);
  glTranslatef(0.7, 0, 0);
  glRotatef(time, 0, 1, 0);
  glColor3f(0.5, 0.6, 0.7);
  glutSolidSphere(0.1, 10, 8); // earth
  glPushMatrix();
  glRotatef(time, 0, 1, 0);
  glTranslatef(0.2, 0, 0);
  glColor3f(0.9, 0.8, 0.2);
  glutSolidSphere(0.04, 10, 8); // moon
  glPopMatrix();
  glPushMatrix();
  glRotatef(time, 0, 1, 0);
  glTranslatef(-0.2, 0, 0);
  glColor3f(0.9, 0.2, 0.8);
  glutSolidSphere(0.04, 10, 8); // moon2
  glPopMatrix();
  glPopMatrix();
  glPushMatrix();
  glRotatef(vday, 0, 1, 0);
  glTranslatef(0.3, 0, 0);
  glRotatef(time, 0, 1, 0);
  glColor3f(1., 0.4, 0.0);
  glutSolidSphere(0.07, 10, 8); // vinus
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
    day  = (day + 10); // %360;
    vday = (vday + 20);
    glutPostRedisplay();
    break;

  case 't':
    time = (time + 5); // %360;
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
  glOrtho(-1, 1, -1, 1, -1, 1);

  glutIdleFunc(MyIdle);

  glutDisplayFunc(MyDisplay);
  glutKeyboardFunc(MyKey);
  glEnable(GL_DEPTH_TEST);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  //	InitLight();
  glutMainLoop();
}
