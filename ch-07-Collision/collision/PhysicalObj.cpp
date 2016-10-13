// PhysicalObj.cpp: implementation of the PhysicalObj class.
//
//////////////////////////////////////////////////////////////////////
#include "math.H"
#include "PhysicalObj.h"
#include "vect4d.H"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


PhysicalObj::PhysicalObj(float x, float y, float z)
{
   p.m[0] = p.m[1] = p.m[2] = 0;
   v.m[0] = v.m[1] = v.m[2] = 0;
   a.m[0] = a.m[1] = a.m[2] = 0;
   // 중력가속도
   a.m[1] = -.00001f;
   clock = 0;
   scale = 1.0f;
}

PhysicalObj::~PhysicalObj()
{
}

void PhysicalObj::SetPosition(float x, float y, float z)
{
   p.m[0] = x;
   p.m[1] = y;
   p.m[2] = z;
}
void PhysicalObj::SetVelocity(float x, float y, float z)
{
   v.m[0] = x;
   v.m[1] = y;
   v.m[2] = z;
}
void PhysicalObj::AddVelocity(float x, float y, float z)
{
   // 속도 변환
   v.m[0] += x;
   v.m[1] += y;
   v.m[2] += z;
}

void PhysicalObj::SetAcceleration(float x, float y, float z)
{
   a.m[0] = x;
   a.m[1] = y;
   a.m[2] = z;
}

void PhysicalObj::BoundCheck()
{
   // 바닥, 경계 충돌 계산

   // 충돌할 때마다 e만큼 곱해짐
   float e = 0.8f;

   if(p.m[1] - radius< 0) {
      if( fabs(v.m[1]) < 0.001) { // stop condition
         p.m[1] = radius;
         v.m[1] = 0;
      } else {
         v.m[1] = (float)fabs(v.m[1]) * e;
      }
   }
   // 충돌 후 속도를 뒤집어 줌
   if(p.m[0] - radius < -2.5) {
      p.m[0] = -2.5 + radius;
      v.m[0] = (float)fabs(v.m[0]) * e;
   }
   if(p.m[0] + radius > 2.5) {
      p.m[0] = 2.5 - radius;
      v.m[0] = (float)-fabs(v.m[0]) * e;
   }
   if(p.m[2] - radius < -2.5) {
      p.m[2] = -2.5 + radius;
      v.m[2] = (float)fabs(v.m[2]) * e;
   }
   if(p.m[2] + radius > 2.5) {
      p.m[2] = 2.5 - radius;
      v.m[2] = (float)-fabs(v.m[2]) * e;
   }

}
void PhysicalObj::Move(float current)
{
   // 흐른시간과 속도에 따라 이동
   if(current == -1) { // defafult
      // p' = p + v * t(매번 단위시간이 1초씩 움직인다고 가정하면 t 생략)
      // 오차를 줄이기위한 0.5f를 가속도에 곱함
      p.m[0] += v.m[0] + 0.5f*a.m[0];
      p.m[1] += v.m[1] + 0.5f*a.m[1];
      p.m[2] += v.m[2] + 0.5f*a.m[2];

      v.m[0] += a.m[0];
      v.m[1] += a.m[1];
      v.m[2] += a.m[2];
   }

   BoundCheck();

}

void PhysicalObj::Collision(PhysicalObj *target)
{
   // 공과 공 사이의 충돌 계산
   // 내 공과 상대방 공 사이의 거리
   Vect4D distance = p- target->p;
   double length = distance.Magnitude();
   // 반지름 내부에 들어오는 순간 충돌 판정
   float rsum = radius + target->radius;
   if(rsum > length) { // collision!
      // d vector 를 기반으로 d1, d2 산출
      Vect4D d = target->p - p; // normal
      d.Normalize();
      // 충돌 후 밀리는 방향(mv1==d1, mv2==d2)
      Vect4D d1 = d * (d*v);// d.DotProduct(v);
      Vect4D d2 = d * (d*target->v);//d.DotProduct(target->v);
      // 질량
      float m1 = w;
      float m2 = target -> w;
      // d1, d2 를 완전 탄성 충돌의 u1, u2로 생각
      Vect4D v1 = (d1*(m1-m2)+d2*m2*2) / (m1+m2);
      Vect4D v2 = (d2*(m2-m1)+d1*m1*2) / (m1+m2);
      v = v1 + (v - d1); // v1 + t1
      target->v = v2 + (target->v - d2);

      //v = (v - d1) + d2; // t1 + d2 = (v - d1) + d2 (공식을 한 번에 줄여 쓴 것)
      //target->v = (target->v - d2) + d1;
   }
}

void PhysicalObj::SetRadius(float r)
{
   radius = r*scale;
}
