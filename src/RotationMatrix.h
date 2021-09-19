#ifndef __ROTATION_MATRIX
#define __ROTATION_MATRIX

#include "Vector3.h"
#include <cmath>
#include <iostream>
#include <sstream>

#define NROWS 4
#define NCOLS 4

class RotationMatrix {
public:
    double m[NROWS*NCOLS];

    RotationMatrix();
    RotationMatrix(Vector3 axis, double theta);
    static RotationMatrix identity();
    std::string toString();

    Vector3 operator * (Vector3& u);
    friend Vector3 operator * (Vector3& u, RotationMatrix const& rm);
    friend std::ostream& operator << (std::ostream& os, RotationMatrix rm);
};

#endif //__ROTATION_MATRIX
