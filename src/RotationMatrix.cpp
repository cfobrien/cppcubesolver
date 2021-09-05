#include "Vector3.h"
#include <cmath>
#include <iostream>
#include <sstream>

#define NROWS 3
#define NCOLS 3

class RotationMatrix {
private:
    // static const char NROWS = 3;
    // static const char NCOLS = 3;
public:
    double m[NROWS*NCOLS];

    RotationMatrix(Vector3 axis, double theta) {
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
    	//m[3] = 0;

    	m[3] = t*x*y + s*z;\
    	m[4] = t*y*y + c;
    	m[5] = t*y*z - s*x;
    	//m[7] = 0;

    	m[6] = t*x*z - s*y;
    	m[7] = t*y*z + s*x;
    	m[8] = t*z*z + c;
    	//m[11] = 0;
    }

    // Vector3 __MATRIX_VECTOR_TRANSFORM(Vector3 u, RotationMatrix rm) {
    //
    // }

    Vector3 operator * (Vector3 u) const {
        double v_arr[NCOLS];
        double * u_arr = u.toArray();

        for (char col = 0; col < NCOLS; col++) {
            for (char row = 0; row < NROWS; row++) {
                v_arr[col] += u_arr[row] * m[NCOLS*row+col];
            }
        }
        return Vector3(v_arr);
    }

    friend Vector3 operator * (Vector3 /*const*/ &, RotationMatrix const &);


    RotationMatrix identity() {
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

    std::string toString() {
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

    void print() {
        std::cout << this->toString();
    }
};

Vector3 operator * (Vector3 /*const*/ &u, RotationMatrix &rm) {
    double v_arr[NCOLS];
    double * u_arr = u.toArray();

    for (char col = 0; col < NCOLS; col++) {
        for (char row = 0; row < NROWS; row++) {
            v_arr[col] += u_arr[row] * rm.m[NCOLS*row+col];
        }
    }
    return Vector3(v_arr);
}
