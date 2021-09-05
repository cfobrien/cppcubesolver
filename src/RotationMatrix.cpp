#include "RotationMatrix.h"
#include "Vector3.h"

#include <cmath>
#include <iostream>
#include <sstream>

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

RotationMatrix RotationMatrix::identity() {
    char row = -1;
    for (char i = 0; i < NROWS*NCOLS; i++) {
        // row in increments at the start of each row
        row += (int)(i/NCOLS == ceil(i/NCOLS));

        if ((i-row)/NCOLS == ceil((i-1)/NCOLS)) {
            m[i] = 1.0;
            std::cout << i << std::endl;
        } else {
            m[i] = 0.0;
        }
    }
    return *this;
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

void RotationMatrix::print() {
    std::cout << this->toString();
}

// Vector3 operator * (Vector3 /*const*/ &u, RotationMatrix &rm) {
//     double v_arr[NCOLS];
//     double * u_arr = u.toArray();
//
//     for (char col = 0; col < NCOLS; col++) {
//         for (char row = 0; row < NROWS; row++) {
//             v_arr[col] += u_arr[row] * rm.m[NCOLS*row+col];
//         }
//     }
//     return Vector3(v_arr);
// }
