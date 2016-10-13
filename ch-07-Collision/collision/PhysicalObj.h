// PhysicalObj.h: interface for the PhysicalObj class.
//
//////////////////////////////////////////////////////////////////////


#if !defined(AFX_PHYSICALOBJ_H__49719AF0_6560_45FB_A928_78DD371377F2__INCLUDED_)
#define AFX_PHYSICALOBJ_H__49719AF0_6560_45FB_A928_78DD371377F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "vect4d.H"

class PhysicalObj
{
public:
   // p : 포지션
   // v : 속도
   // a : 가속도
   Vect4D p, v, a;
   // w : 질량
   float w;
   float clock;
   float scale;

   float radius;

public:
   PhysicalObj(float x=0, float y=0, float z=0);
   void SetWeight(float x) { w=x; };
   void SetPosition(float x, float y, float z);
   void SetVelocity(float x, float y, float z);
   void SetAcceleration(float x, float y, float z);
   void AddVelocity(float x, float y, float z);
   void Move(float current=-1);
   void BoundCheck();
   void Collision(PhysicalObj *target);
   void SetRadius(float r);
   virtual ~PhysicalObj();

};

#endif // !defined(AFX_PHYSICALOBJ_H__49719AF0_6560_45FB_A928_78DD371377F2__INCLUDED_)
