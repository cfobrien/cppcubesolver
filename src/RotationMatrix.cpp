#include "Vector3.cpp"
#include <cmath>
#include <iostream>

class RotationMatrix {
private:
    static const char ROWS = 4;
    static const char COLS = 4;
    int rm[ROWS*COLS];
public:
    RotationMatrix(Vector3 axis, double theta) {
        Vector3 normalized = axis.normalized();
        double x = normalized.x;
        double y = normalized.y;
        double z = normalized.z;

        double c = std::cos(theta);
        double s = std::sin(theta);
        double t = 1-c;

        rm[0] = t*x*x + c;
        rm[1] = t*x*y - s*z;
        rm[2] = t*x*z + s*y;
    	//m[3] = 0;

    	rm[4] = t*x*y + s*z;
    	rm[5] = t*y*y + c;
    	rm[6] = t*y*z - s*x;
    	//m[7] = 0;

    	rm[8] = t*x*z - s*y;
    	rm[9] = t*y*z + s*x;
    	rm[10] = t*z*z + c;
    	//m[11] = 0;
    }

    Vector3 operator * (Vector3 &v) const {
        double * a = v.toArray();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a[i] += rm[i*ROWS+j];
            }
        }
        return Vector3(a);
    }

    std::string toString() {
        std::ostringstream oss;
        int i,j;
        for (i=0; i<3; i++) {
            oss << "|";
            for (j=0; j<3; j++) {
                oss << rm[i*ROWS+j];
            }
            oss << "|\n";
        }
        return oss.str();
    }

    void print() {
    	std::cout << this->toString();
    }

    void println() {
        std::cout << this->toString();
    }
};
