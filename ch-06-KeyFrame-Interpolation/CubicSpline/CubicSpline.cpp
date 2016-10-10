#include "CubicSpline.h"

CCubicSpline::CCubicSpline()
{
   mNumPoints = 0;
}

CCubicSpline::CCubicSpline(int dim, C3DVec *points)
{
   mNumPoints = dim;
   for(int i=0;i<dim;i++) {
      mPoints.push_back(points[i]);
      mDerived.push_back(C3DVec(1,1,0));
   }
}

void CCubicSpline::SetPoints(int dim, C3DVec *points)
{
   mPoints.clear();
   mDerived.clear();
   mNumPoints = dim;
   for(int i=0;i<dim;i++) {
      mPoints.push_back(points[i]);
      mDerived.push_back(C3DVec(1,1,0));
   }
}

void CCubicSpline::SetDerivative(int idx, const C3DVec &derivative)
{
   mDerived[idx].Set(derivative.x, derivative.y, derivative.z);
}

C3DVec &CCubicSpline::ComputeCurve(int idx, float u) const
{
   float ps[3], pe[3], vs[3], ve[3];
   mPoints[idx].Get(ps[0], ps[1], ps[2]);
   mPoints[idx+1].Get(pe[0], pe[1], pe[2]);
   mDerived[idx ].Get(vs[0], vs[1], vs[2]);
   mDerived[idx+1].Get(ve[0], ve[1], ve[2]);
   float res[3];
   for(int i=0;i<3;i++) {
      res[i] = ps[i]+vs[i]*u + (3*(pe[i]-ps[i]) - 2*vs[i]-ve[i])*u*u + (2*(ps[i]-pe[i])+vs[i]+ve[i])*u*u*u;
   }
   return C3DVec(res[0],res[1],res[2]);
}
