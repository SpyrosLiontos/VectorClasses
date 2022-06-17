#include <cmath>
#include <iostream>
#include "Point3D.h"
#include "Vector3D.h"
using namespace std; 

int main() {
  Point3D A(1,0,0);
  Point3D B(2,3,4);
  Point3D C(1,1,1);
  Point3D D(5,3,4);

  Vector3D v1(A,B);
  Vector3D v2(C,D);
  Vector3D v3(1,-2,-7);
  
  cout << "        V1        = " <<      v1     << endl;
  cout << "        V2        = " <<      v2     << endl;
  cout << "        V3        = " <<      v3     << endl;
  cout << "   V1/2 + 2*V2    = " <<  v1/2+2*v2            << endl;
  cout << " 3.5*V1 - V2*4    = " <<  3.5*v1-v2*4          << endl;
  cout << "     V1 . V2      = " <<      v1.inner(v2)     << endl;
  cout << "     V1 . V1      = " <<      v1.inner(v1)     << endl;
  cout << "     V2 . V2      = " <<      v2.inner(v2)     << endl;
  cout << "(V1+V2) . (V1+V2) = " << (v1+v2).inner(v1+v2)  << endl;
  cout << "(V1-V2) . (V1-V2) = " << (v1-v2).inner(v1-v2)  << endl;
  cout << "     V1 x V2      = " <<      v1.cross(v2)     << endl;
  cout << "(V1+V2) x (V1-V2) = " << (v1+v2).cross(v1-v2)  << endl;

  cout << "(V1xV2) x (V1xV3) = " << (v1.cross(v2)).cross(v1.cross(v3))  << endl;
  cout << "(V1.(V2xV3))      = " << (v1.inner(v2.cross(v3)))            << endl;
  cout << "(V1.(V2xV3))V1    = " << (v1.inner(v2.cross(v3)))*v1         << endl;
}
