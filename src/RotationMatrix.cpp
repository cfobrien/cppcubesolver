#include "RotationMatrix.h"
#include "Vector3.h"

#include <cmath>
#include <iostream>
#include <sstream>

RotationMatrix::RotationMatrix() {}

RotationMatrix::RotationMatrix(Vector3 axis, double theta) {
    Vector3 normalized = axis.normalized();
    double x = normalized.x;
    double y = normalized.y;
    double z = normalized.z;

    double c = std::cos(theta);
    double s = std::sin(theta);
    double t = 1-c;

    m[0] = t*x*x + c;
    m[1] = t*x*y - s*z;
    m[2] = t*x*z + s*y;

	m[3] = t*x*y + s*z;\
	m[4] = t*y*y + c;
	m[5] = t*y*z - s*x;

	m[6] = t*x*z - s*y;
	m[7] = t*y*z + s*x;
	m[8] = t*z*z + c;
}

Vector3 RotationMatrix::operator * (Vector3 u) const {
    double v_arr[NCOLS];
    double * u_arr = u.toArray();

    for (char col = 0; col < NCOLS; col++) {
        for (char row = 0; row < NROWS; row++) {
            v_arr[col] += u_arr[row] * m[NCOLS*row+col];
        }
    }
    return Vector3(v_arr);
}
Vector3 operator * (Vector3 u, RotationMatrix const& rm) {
    double v_arr[NCOLS];
    double * u_arr = u.toArray();

    for (char col = 0; col < NCOLS; col++) {
        for (char row = 0; row < NROWS; row++) {
            v_arr[col] += u_arr[row] * rm.m[NCOLS*row+col];
        }
    }
    return Vector3(v_arr);
}
std::ostream& operator << (std::ostream& os, RotationMatrix rm) {
    os << rm.toString();
    return os;
}

RotationMatrix RotationMatrix::identity() {
    RotationMatrix rm = RotationMatrix();
    int row = -1;
    int i;
    for (i = 0; i < NROWS*NCOLS; i++) {
        if (!(i%NCOLS))
            row++;
        if (!(i%(NCOLS+row)) || i+1==NROWS*NCOLS) {
            rm.m[i] = 1.0;
        } else {
            rm.m[i] = 0.0;
        }
    }
    return rm;
}

std::string RotationMatrix::toString() {
    std::ostringstream oss;
    int i, j;
    for (i = 0; i < 3; i++) {
        oss << "|";
        for (j = 0; j < 3; j++) {
            oss << m[i*NROWS+j];
        }
        oss << "|\n";
    }
    return oss.str();
}
