#include <iostream>
#include "Vector3.cpp"
#include "RotationMatrix.cpp"

int main(int argc, char **argv) {
    Vector3 u, v;

    v = Vector3(1,2,3);

    Vector3 axis = Vector3::Z();
    double theta = 90.0;
    RotationMatrix m = RotationMatrix(axis, theta);
    m.toString();

    std::cout << "rotating vector " << v.toString() << " by " << theta << " degrees around " << axis.toString() << "...\n";

    Vector3 rotated = m * v;

    std::cout << "rotated vector: " << rotated.toString() << "\n";

    std::cout << "--------------------------------" << std::endl;

    u = Vector3(-1,2,0);
    v = Vector3(-7,1,-2);
    u.println();
    v.println();
    std::cout << "Biggest elements:" << std::endl;
    Vector3 biggest_elements = Vector3(
        (u.x >= v.x) * u.x + (v.x > u.x) * v.x,
        (u.y >= v.y) * u.y + (v.y > u.y) * v.y,
        (u.z >= v.z) * u.z + (v.z > u.z) * v.z
    );
    biggest_elements.println();

    std::cout << "error:" << std::endl;
    Vector3 error = (u-v).abs();
    error.println();

    (biggest_elements * 0.005).println();

    return 0;
}
