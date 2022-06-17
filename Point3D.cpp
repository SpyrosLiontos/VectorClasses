#include <iostream>
#include <cmath>
#include "Point3D.h"
using namespace std;

Point3D::Point3D() {
  X=0;
  Y=0;
  Z=0;
}

Point3D::Point3D(double a, double b,double c){
  X=a;
  Y=b;
  Z=c;
}

Point3D::~Point3D() {}

double Point3D::Distance(){
  return sqrt(X*X+Y*Y+Z*Z);
}

double Point3D::getX() const {return X;}
double Point3D::getY() const {return Y;}
double Point3D::getZ() const {return Z;}
void Point3D::setX(double a) {X=a;}
void Point3D::setY(double b) {Y=b;}
void Point3D::setZ(double c) {Z=c;}
void Point3D::print() {
  std::cout<< "(" << X << "," << Y <<  "," << Z <<")";
}
