#ifndef __ROTATION_MATRIX
#define __ROTATION_MATRIX

#include "Vector3.h"
#include <cmath>
#include <iostream>
#include <sstream>

#define NROWS 3
#define NCOLS 3

class RotationMatrix {
public:
    double m[NROWS*NCOLS];
    RotationMatrix(Vector3 axis, double theta);
    RotationMatrix identity();
    std::string toString();
    void print();

    Vector3 operator * (Vector3 u) const;
    friend Vector3 operator * (Vector3& u, RotationMatrix const& rm) {
        double v_arr[NCOLS];
        double * u_arr = u.toArray();

        for (char col = 0; col < NCOLS; col++) {
            for (char row = 0; row < NROWS; row++) {
                v_arr[col] += u_arr[row] * rm.m[NCOLS*row+col];
            }
        }
        return Vector3(v_arr);
    }
};

#endif //__ROTATION_MATRIX
