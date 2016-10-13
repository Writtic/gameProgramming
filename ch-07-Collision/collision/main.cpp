#include "stdio.h"
#include "math.h"
#include "GL/glut.h"
#include "GL/gl.h"
#include "GL/glu.h"
#include "PhysicalObj.h"
#include "vect4d.H"

#define GLUT_KEY_SPACE 32
// 글로벌 변수로 선언
PhysicalObj            g_PhyBall1;
PhysicalObj               g_PhyBall2;

void InitMeshData()
{
   float radius = 0.3;

   g_PhyBall1.SetRadius(radius);
   g_PhyBall1.SetPosition(1.0, 0, 0);
   g_PhyBall1.SetWeight(1.0);

   g_PhyBall2.SetRadius(radius);
   g_PhyBall2.SetPosition(-1.0, 0, 0);
   g_PhyBall2.SetWeight(10.0);
}

void Action()
{
   g_PhyBall1.Move();
   g_PhyBall2.Move();
   g_PhyBall1.Collision(&g_PhyBall2);
}

void MyIdle()
{
   // 상태가 바뀐것을 기반으로 좌표가 바뀜
   Action();
   // 그림을 다시 그려달라고 요청
   glutPostRedisplay();
}
void MyDisplay() {

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt(0, 7, 10, 0,1,0, 0,1,0);

   // floor
   glColor3f(0.0, 0.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex3f(-2.5, 0,  -2.5);
   glVertex3f(2.5, 0, -2.5);
   glVertex3f(2.5, 0, 2.5);
   glVertex3f(-2.5, 0, 2.5);
   glEnd();

   glPushMatrix();
      // ball1 그림
      glTranslatef(g_PhyBall1.p[0], g_PhyBall1.p[1], g_PhyBall1.p[2]);
      glColor3f(1.0, 0.0, 0.0);
      glutWireSphere(g_PhyBall1.radius, 15, 15);
   glPopMatrix();
   glPushMatrix();
      // ball2 그림
      glTranslatef(g_PhyBall2.p[0], g_PhyBall2.p[1], g_PhyBall2.p[2]);
      glColor3f(0.0, 1.0, 0.0);
      glutWireSphere(g_PhyBall2.radius, 15, 15);
   glPopMatrix();


   glutSwapBuffers();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y){
   float delta = 0.0005f;
   switch (KeyPressed){
   case 'w':
      // physical 객체 g_PhyBall1에 속도를 더하는 함수
      g_PhyBall1.AddVelocity(0, 0, -delta);
      break;
   case 's':
      g_PhyBall1.AddVelocity(0, 0, delta);
      break;
   case 'a':
      g_PhyBall1.AddVelocity(-delta, 0, 0);
      break;
   case 'd':
      g_PhyBall1.AddVelocity(delta, 0, 0);
      break;
   case GLUT_KEY_SPACE:
      g_PhyBall1.AddVelocity(0, delta * 10, 0);
      break;
   }

}

int main(int argc, char** argv) {
   InitMeshData();

   glutInit(&argc,argv);               // GLUT 윈도우 함수
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize(800, 800);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("Perfectly Elastic Collision");

   glEnable(GL_DEPTH_TEST);
   glClearColor(1.0, 1.0, 1.0, 1.0);   // GL 상태변수 설정
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(30, 1.0, 0.1 ,100);

   glutDisplayFunc(MyDisplay);         // GLUT 콜백함수 등록(디스플레이 관련)
   glutKeyboardFunc(MyKeyboard);      // 키보드 이벤트
   glutIdleFunc(MyIdle);            // 여유있을 때 호출
   glutMainLoop();                     // 이벤트 루프 진입
   return 0;
}
