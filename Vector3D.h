#pragma once
#include "Point3D.h"

class Vector3D {

  public:
    ~Vector3D();
    Vector3D();
    Vector3D(Point3D&, Point3D&);
    Vector3D(Point3D&);
    Vector3D(double, double, double);

    Point3D getA() const ;
    Point3D getB() const ;
    void setA(const Point3D&);
    void setB(const Point3D&);
    void print();

    friend Vector3D operator+(const Vector3D & lhs, const Vector3D & rhs);
    friend Vector3D operator-(const Vector3D & lhs, const Vector3D & rhs);
    friend Vector3D operator*(const double     lhs, const Vector3D & rhs);
    friend Vector3D operator*(const Vector3D & lhs, const double     rhs);
    friend Vector3D operator/(const Vector3D & lhs, const double     rhs);

    Vector3D& operator+=(const Vector3D & rhs);
    Vector3D& operator-=(const Vector3D & rhs);

    friend std::ostream& operator<<(std::ostream & stream,const Vector3D & rhs);  

    double length();
    double inner(const Vector3D &);

    Vector3D cross ( const Vector3D & );

  private:

    Point3D A;
    Point3D B;
};
