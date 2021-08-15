#include "Vector3.cpp"

class RotationMatrix {
private:
    static const int SIZE = 4*4;
    int m[SIZE];
public:
    RotationMatrix(Vector3 axis, double theta) {
        Vector3 normalized = axis.normalized();
    }
};
