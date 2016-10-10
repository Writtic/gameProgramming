#ifndef __CUBIC_SPLINE_KANG2006__H
#define __CUBIC_SPLINE_KANG2006__H
#include <vector>
using namespace std;
class C3DVec {
public:
   float x;
   float y;
   float z;
   C3DVec() { x=y=z=0; };
   C3DVec(float a, float b, float c) { x=a; y=b; z=c; }
   void Set(float a, float b, float c) { x=a; y=b; z=c; }
   void Get(float &a, float &b, float &c) const { a=x; b=y; c=z; }
};
class CCubicSpline {
   int mNumPoints;
   vector<C3DVec> mPoints;
   vector<C3DVec> mDerived;
   //C3DVec *mPointArray;
   //C3DVec *mDerivArray;
   public:
   CCubicSpline();
   CCubicSpline(int dim, C3DVec *points);
   void SetPoints(int dim, C3DVec *points);
   void SetDerivative(int idx, const C3DVec &derivative);
   C3DVec &ComputeCurve(int idx, float u) const;
};
#endif
