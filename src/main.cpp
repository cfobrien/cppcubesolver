#include <iostream>
#include "Vector3.cpp"
#include "RotationMatrix.cpp"

int main(int argc, char **argv) {
    Vector3 v = Vector3(1,2,3);

    Vector3 axis = Vector3::Z();
    double theta = 90.0;
    RotationMatrix m = RotationMatrix(axis, theta);
    m.toString();

    std::cout << "rotating vector " << v.toString() << " by " << theta << " degrees around " << axis.toString() << "...\n";

    Vector3 rotated = m * v;

    std::cout << "rotated vector: " << rotated.toString() << "\n";

    return 0;
}
