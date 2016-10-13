#include <math.h>
#include "Vect4D.h"


Vect4D::Vect4D()
{
   for(int i=0; i<3 ; i++)
      m[i] = 0;

   m[3] =1;
}

Vect4D::Vect4D(const Vect4D& vect)
{
   for(int i=0; i<4 ; i++)
      m[i] = vect.m[i];
}

Vect4D::Vect4D(double m0,double m1,double m2,double m3)
{
   m[0]=m0; m[1]=m1; m[2]=m2; m[3]=m3;
}

Vect4D::Vect4D(double m0,double m1,double m2)
{
   m[0]=m0; m[1]=m1; m[2]=m2; m[3]=1.;
}

Vect4D::Vect4D(double vec[4])
{
   m[0]=vec[0]; m[1]=vec[1]; m[2]=vec[2]; m[3]=vec[3];
}

Vect4D::~Vect4D(void)
{
}

Vect4D Vect4D::operator=(const Vect4D& vect)
{
   for(int i=0; i<4 ; i++)
      m[i] = vect.m[i];

   return (*this);
}

Vect4D Vect4D::operator+(const Vect4D vect)
{
   Vect4D resV;

   for(int i=0; i< 3; i++)
      resV.m[i] = m[i]+vect.m[i];

   return resV;
}

Vect4D Vect4D::operator-(const Vect4D vect)
{
   Vect4D resV;

   for(int i=0; i< 3; i++)
      resV.m[i] = m[i]-vect.m[i];

   return resV;
}


//vector내적
double Vect4D::operator*(const Vect4D vect)
{
   double res=0;

   for(int i=0; i< 3; i++)
      res += m[i]*vect.m[i];

   return res;
}

Vect4D Vect4D::operator*(const double var)
{
   Vect4D resV;

   for(int i=0; i<3; i++)
      resV.m[i] = m[i]*var;

   return resV;
}

double Vect4D::operator[](const int inx) const
{
   return m[inx];
}

bool Vect4D::operator==(const Vect4D &r) const
{
   if (m[0]==r[0]&&m[1]==r[1]&&m[2]==r[2]) return true;
   else return false;
}

bool Vect4D::operator!=(const Vect4D &r) const
{
   return !(*this==r);
}

void Vect4D::Normalize(void)
{
   double norm = sqrt(m[0]*m[0] + m[1]*m[1] + m[2]*m[2]);

   for(int i=0 ; i<3 ; i++)
      m[i] /= norm;
}

double Vect4D::DotProduct (const Vect4D vect)
{
   return m[0]*vect.m[0] + m[1]*vect.m[1] + m[2]*vect.m[2];
}

Vect4D Vect4D::CrossProduct (const Vect4D vect)
{
   Vect4D resV;

   resV.m[0] = m[1]*vect.m[2] - m[2]*vect.m[1];
   resV.m[1] = m[2]*vect.m[0] - m[0]*vect.m[2];
   resV.m[2] = m[0]*vect.m[1] - m[1]*vect.m[0];

   return resV;
}

Vect4D Vect4D::operator/(const double var)
{
   Vect4D resV;

   for(int i=0; i<3; i++)
      resV.m[i] = m[i]/var;

   return resV;
}
double Vect4D::Magnitude (void)
{
   double Value;

   Value = m[0] * m[0] + m[1] * m[1] + m[2] * m[2];

   return sqrt(Value);
}
