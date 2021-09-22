#include "RotationMatrix.h"
#include "Vector3.h"

#include <cmath>
#include <iostream>
#include <sstream>

RotationMatrix::RotationMatrix() {
    axis = Vector3();
    angle = 0.0;
    for (int i = 0; i < NCOLS*NROWS; i++) {
        m[i] = 0.0;
    }
}

RotationMatrix::RotationMatrix(Vector3 axis, double theta) {
    this->axis = axis;
    this->angle = theta;
    Vector3 normalized = axis.normalized();
    double x = normalized.x;
    double y = normalized.y;
    double z = normalized.z;

    double x2 = x*x;
    double y2 = y*y;
    double z2 = z*z;

    double xy = x*y;
    double xz = x*z;
    double yz = y*z;

    double c = std::cos(theta);
    double s = std::sin(theta);
    double t = 1-c;

    m[0] = x2 + (y2 + z2)*c;
    m[1] = xy*t - z*s;
    m[2] = xz*t + y*s;
    m[3] = 0.0;

	m[4] = xy*t + z*s;
	m[5] = y2 + (x2 + z2)*c;
	m[6] = yz*t - x*s;
    m[7] = 0.0;

	m[8] = xz*t - y*s;
	m[9] = yz*t + x*s;
	m[10] = z2 + (x2 + y2)*c;
    m[11] = 0.0;

    m[12] = 0.0;
    m[13] = 0.0;
    m[14] = 0.0;
    m[15] = 1.0;
}

Vector3 RotationMatrix::operator * (Vector3 u) {
    Vector3 v = Vector3();
    for (char col = 0; col < NCOLS; col++) {
        for (char row = 0; row < NROWS; row++) {
            v[col] += u[row] * m[row*NCOLS + col];
        }
    }
    return v;
}
Vector3 operator * (Vector3 u, RotationMatrix const& rm) {
    Vector3 v = Vector3();
    for (char col = 0; col < NCOLS; col++) {
        for (char row = 0; row < NROWS; row++) {
            v[col] += u[row] * rm.m[NCOLS*row+col];
        }
    }
    return v;
}
std::ostream& operator << (std::ostream& os, RotationMatrix rm) {
    os << rm.toString();
    return os;
}

RotationMatrix RotationMatrix::identity() {
    RotationMatrix rm = RotationMatrix();
    int column_offset = 0;
    for (int i = 0; i < NROWS; i++) {
        rm.m[i*NCOLS + column_offset++] = 1.0;
    }
    return rm;
}

std::string RotationMatrix::toString() {
    std::ostringstream oss;
    int i, j;
    for (i = 0; i < NROWS; i++) {
        oss << "|";
        for (j = 0; j < NCOLS; j++) {
            oss << m[i*NROWS+j] << " ";
        }
        oss << "|\n";
    }
    return oss.str();
}
