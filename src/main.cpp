#include <iostream>
#include "Vector3.h"
#include "RotationMatrix.h"

int main(int argc, char **argv) {
    RotationMatrix rm1 = RotationMatrix::identity();
    std::cout << rm1;

    Vector3 v1 = Vector3::Y();

    Vector3 res = Vector3::ones() * RotationMatrix::identity();
    Vector3 res2 = RotationMatrix::identity() * Vector3::ones();
    // Vector3 res = Vector3(1,1,1) * RotationMatrix::identity();
    // Vector3 res2 = RotationMatrix::identity() * Vector3(1,1,1);
    std::cout << res << std::endl;
    std::cout << res2 << std::endl;


    return 0;
}
