#include "Vector3.cpp"
#include "RotationMatrix.cpp"

int main(int argc, char **argv) {
    Vector3 v = Vector3(1,2,3);
    v.print();

    Vector3 axis = Vector3(0,0,1);
    double theta = 90.0;
    RotationMatrix m = RotationMatrix(axis, theta);
    m.print();

    return 0;
}
