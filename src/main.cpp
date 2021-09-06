#include <iostream>
#include "Vector3.h"
#include "RotationMatrix.h"

int main(int argc, char **argv) {
    Vector3 u, v;

    Vector3 x = Vector3::X();
    std::cout << x << std::endl;

    RotationMatrix rm = RotationMatrix::identity();
    std::cout << rm << std::endl;

    std::cout << (x*rm);

    return 0;
}
