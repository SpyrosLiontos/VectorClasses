#include <iostream>
#include <cmath>
#include "Point3D.h"
#include "Vector3D.h"

Vector3D::~Vector3D() {}
Vector3D::Vector3D() {
  A.setX(0);
  A.setY(0);
  A.setZ(0);
  B.setX(0);
  B.setY(0);
  B.setZ(0);
}
Vector3D::Vector3D(Point3D& a,Point3D& b) {
  A=a;
  B=b;
}
Vector3D::Vector3D(Point3D& b) {
  A.setX(0);
  A.setY(0);
  A.setZ(0);
  B=b;
}
Vector3D::Vector3D(double x, double y, double z) {
  A.setX(0);
  A.setY(0);
  A.setZ(0);
  B.setX(x);
  B.setY(y);
  B.setZ(z);
}

void Vector3D::setA(const Point3D& a)  { A=a; }
void Vector3D::setB(const Point3D& a)  { B=a; }
Point3D Vector3D::getA()  const        { return A; }
Point3D Vector3D::getB()  const        { return B; }
void Vector3D::print() {
  double Ax=A.getX();  double Ay=A.getY();   double Az=A.getZ();
  double Bx=B.getX();  double By=B.getY();   double Bz=B.getZ();
  std::cout <<     "(" << Ax << "," << Ay << "," << Az << ")" <<
               "->(" << Bx << "," << By << "," << Bz << ")" ;
}

Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs) {
  double Ax=lhs.A.getX(); double Ay=lhs.A.getY(); double Az=lhs.A.getZ();
  double Bx=lhs.B.getX(); double By=lhs.B.getY(); double Bz=lhs.B.getZ();
  double Cx=rhs.A.getX(); double Cy=rhs.A.getY(); double Cz=rhs.A.getZ();
  double Dx=rhs.B.getX(); double Dy=rhs.B.getY(); double Dz=rhs.B.getZ();
  Vector3D F;
  F.B.setX(Bx-Ax+Dx-Cx);
  F.B.setY(By-Ay+Dy-Cy);
  F.B.setZ(Bz-Az+Dz-Cz);
  return F;
}

Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs) {
  double Ax=lhs.A.getX(); double Ay=lhs.A.getY(); double Az=lhs.A.getZ();
  double Bx=lhs.B.getX(); double By=lhs.B.getY(); double Bz=lhs.B.getZ();
  double Cx=rhs.A.getX(); double Cy=rhs.A.getY(); double Cz=rhs.A.getZ();
  double Dx=rhs.B.getX(); double Dy=rhs.B.getY(); double Dz=rhs.B.getZ();
  Vector3D F;
  F.B.setX(Bx-Ax-Dx+Cx);
  F.B.setY(By-Ay-Dy+Cy);
  F.B.setZ(Bz-Az-Dz+Cz);
  return F;
}

Vector3D operator*(const double lhs, const Vector3D & rhs) {
  double a1=rhs.A.getX(); double a2=rhs.A.getY(); double a3=rhs.A.getZ();
  double b1=rhs.B.getX(); double b2=rhs.B.getY(); double b3=rhs.B.getZ();
  Vector3D F;
  F.B.setX(lhs*(b1-a1));
  F.B.setY(lhs*(b2-a2));
  F.B.setZ(lhs*(b3-a3));
  return F;
}

Vector3D operator*(const Vector3D & lhs, const double rhs) {
  return rhs*lhs;
}

Vector3D operator/(const Vector3D & lhs, const double rhs) {
  return (1./rhs)*lhs;
}



Vector3D& Vector3D::operator+=(const Vector3D& rhs) {
  double Ax=(*this).A.getX(); double Ay=(*this).A.getY(); double Az=(*this).A.getZ();
  double Bx=(*this).B.getX(); double By=(*this).B.getY(); double Bz=(*this).B.getZ();
  double Cx=rhs.A.getX(); double Cy=rhs.A.getY(); double Cz=rhs.A.getZ();
  double Dx=rhs.B.getX(); double Dy=rhs.B.getY(); double Dz=rhs.B.getZ();
  (*this).A.setX(0);
  (*this).A.setY(0);
  (*this).A.setZ(0);
  (*this).B.setX(Bx-Ax+Dx-Cx);
  (*this).B.setY(By-Ay+Dy-Cy);
  (*this).B.setZ(Bz-Az+Dz-Cz);
  return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D& rhs) {
  double Ax=(*this).A.getX(); double Ay=(*this).A.getY(); double Az=(*this).A.getZ();
  double Bx=(*this).B.getX(); double By=(*this).B.getY(); double Bz=(*this).B.getZ();
  double Cx=rhs.A.getX(); double Cy=rhs.A.getY(); double Cz=rhs.A.getZ();
  double Dx=rhs.B.getX(); double Dy=rhs.B.getY(); double Dz=rhs.B.getZ();
  (*this).A.setX(0);
  (*this).A.setY(0);
  (*this).A.setZ(0);
  (*this).B.setX(Bx-Ax-Dx+Cx);
  (*this).B.setY(By-Ay-Dy+Cy);
  (*this).B.setZ(Bz-Az-Dz+Cz);
  return *this;
}

std::ostream& operator<<(std::ostream& stream, const Vector3D& rhs) {
  double Ax=rhs.A.getX(); double Ay=rhs.A.getY(); double Az=rhs.A.getZ();
  double Bx=rhs.B.getX(); double By=rhs.B.getY(); double Bz=rhs.B.getZ();
  stream << "(" << Ax << "," << Ay << "," << Az << ")->(" << Bx << "," << By << "," << Bz << ")";
  return stream;
}
 
double Vector3D::length() {
  double Ax=A.getX();  double Ay=A.getY();  double Az=A.getZ();
  double Bx=B.getX();  double By=B.getY();  double Bz=B.getZ();
  return sqrt( pow(Bx-Ax,2) + pow(By-Ay,2) + pow(Bz-Az,2) );
}

double Vector3D::inner(const Vector3D& vec) {
  double a1 =     B.getX() -     A.getX();
  double a2 =     B.getY() -     A.getY();
  double a3 =     B.getZ() -     A.getZ();
  double b1 = vec.B.getX() - vec.A.getX();
  double b2 = vec.B.getY() - vec.A.getY();
  double b3 = vec.B.getZ() - vec.A.getZ();
  return a1*b1 + a2*b2 + a3*b3;
}

Vector3D Vector3D::cross(const Vector3D &v1){
  Vector3D v2;
  Point3D p1A=v1.getA();
  Point3D p1B=v1.getB();
  Point3D p2A;
  Point3D p2B;
  double x,y,z;
  x=(B.getY()-A.getY())*(p1B.getZ()-p1A.getZ())-(B.getZ()-A.getZ())*(p1B.getY()-p1A.getY());
  y=(B.getZ()-A.getZ())*(p1B.getX()-p1A.getX())-(B.getX()-A.getX())*(p1B.getZ()-p1A.getZ());
  z=(B.getX()-A.getX())*(p1B.getY()-p1A.getY())-(B.getY()-A.getY())*(p1B.getX()-p1A.getX());
  p2B.setX(x);
  p2B.setY(y);
  p2B.setZ(z);
  v2.setA(p2A);
  v2.setB(p2B);
  return v2;

}
