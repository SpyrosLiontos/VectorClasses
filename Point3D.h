#pragma once
class Point3D{
  
 public:
  Point3D();
  Point3D(double,double,double);
  ~Point3D();
  double Distance();
  double getX() const;
  double getY() const;
  double getZ() const;
  void setX(double);
  void setY(double);
  void setZ(double);
  void print();

  
 private:
  double X;
  double Y;
  double Z;
  };
  
