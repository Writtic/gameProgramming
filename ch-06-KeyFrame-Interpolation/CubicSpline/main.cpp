#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include "Timer.h"
#include "DataLoader.h"
#include "CubicSpline.h"

#define CTRL_NUM 5
CTimer myTimer;
CDataLoader myData;
CCubicSpline mySpline;

void Init(void) {
   myTimer.Init();
   myData.Load("AniData.txt");

   float data[CTRL_NUM][3] = {{0,0,0}, {1,0,0}, {1,1,0}, {0,1,0}, {-0.5,0.5,0}};
   C3DVec points[CTRL_NUM];
   for(int i=0; i<CTRL_NUM; i++) {
      points[i].Set(data[i][0], data[i][1], data[i][2]);
   }
   mySpline.SetPoints(CTRL_NUM, points);
}

void changeSize(int w, int h) {
   if(h == 0) h = 1;
   float ratio = 1.0* w / h;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glViewport(0, 0, w, h);
   gluPerspective(45,ratio,1,1000);
   glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glLoadIdentity();
   gluLookAt(0.0,1.0,5.0, 0.0,0.0,-1.0, 0.0f,1.0f,0.0f);
   myTimer.UpdateTime();
   float elapsed = myTimer.GetElapsedTime();
   float end = myData.GetEndTime();
//   if(elapsed > end) myTimer.Reset();
   float loc[3] = {0,0,0};
   myData.GetLoc(elapsed, loc[0], loc[1], loc[2]);
   glPushMatrix();

   if(false) {
      glTranslatef(loc[0], loc[1], loc[2]);
   } else {
      C3DVec pos;
      int p = int(elapsed) % (CTRL_NUM-2);
      float q = elapsed - floor(elapsed);
      pos = mySpline.ComputeCurve(p, q);
      glTranslatef(pos.x, pos.y, pos.z);
   }

   glColor3f(1,0.5,0.5);
   glutSolidTeapot(0.5);

   glColor3f(0,0,0);
   glutWireTeapot(0.5);
   glPopMatrix();


   C3DVec vec;
   glBegin(GL_LINE_STRIP);
   for(int i=0;i<CTRL_NUM-2;i++) {
      for(int j=0;j<20;j++) {
         vec = mySpline.ComputeCurve(i, float(j)/20.);
         glVertex3f(vec.x, vec.y, vec.z);
      }
   }
   glEnd();

   glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y) {
   if (key == 27) exit(0);
}

int main(int argc, char **argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
   glutInitWindowPosition(100,100);
   glutInitWindowSize(800,800);
   glutCreateWindow("Animation Lecture - 01");
   glutDisplayFunc(renderScene);
   glutIdleFunc(renderScene);
   glutReshapeFunc(changeSize);
   glutKeyboardFunc(processNormalKeys);
   glEnable(GL_DEPTH_TEST);
   glClearColor(0.8f,0.8f,1.0f,1.0f);
   Init();
   glutMainLoop();
   return 0;
}
