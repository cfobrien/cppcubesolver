#include "Vector3.cpp"
#include <cmath>
#include <iostream>

class RotationMatrix {
private:
    static const char ROWS = 4;
    static const char COLS = 4;
    int m[ROWS*COLS];
public:
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

    	m[4] = t*x*y + s*z;
    	m[5] = t*y*y + c;
    	m[6] = t*y*z - s*x;
    	//m[7] = 0;

    	m[8] = t*x*z - s*y;
    	m[9] = t*y*z + s*x;
    	m[10] = t*z*z + c;
    	//m[11] = 0;
    }

    Vector3 operator * (RotationMatrix m) const {
        Vector3 v;
        double * a = v.toArray();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a[i] += m[i*ROWS+j];
            }
        }
        return v;
    }

    void print() {
    	int i, j;
    	for (i = 0; i < 3; i++) {
    		std::cout << "|";
    		for (j = 0; j < 3; j++) {
    			std::cout << m[i*ROWS+j];
    		}
    		std::cout << "|\n";
    	}
    }
};
