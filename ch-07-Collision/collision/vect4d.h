#ifndef __VECT4D_H__
#define __VECT4D_H__

class Vect4D{
public:
   double m[4];

   Vect4D();
   Vect4D(const Vect4D& v);
   Vect4D(double m0,double m1,double m2, double m3);
   Vect4D(double m0,double m1,double m2);
   Vect4D(double vec[4]);
   ~Vect4D();

   Vect4D operator=(const Vect4D& vect);
   Vect4D operator+(const Vect4D vect);
   Vect4D operator-(const Vect4D vect);

   double operator*(const Vect4D vect);
   Vect4D operator*(const double var);

   Vect4D operator/(const double var);
   double Magnitude (void);
   Vect4D CrossProduct (const Vect4D vect);
   double DotProduct (const Vect4D vect);

   double operator[](const int inx) const;
   bool operator==(const Vect4D &r) const;
   bool operator!=(const Vect4D &r) const;

   void Normalize(void);

};
#endif //__VECT4D_H__
