#include <iostream>
#include "Vector3.h"
#include "RotationMatrix.h"

int main(int argc, char **argv) {
    RotationMatrix rm1 = RotationMatrix(Vector3::X(), M_PI/4);
    // std::cout << rm1;

    Vector3 v1 = Vector3::Y();
    // std::cout << v1 << std::endl;
    // std::cout << "-------------------" << std::endl;
    std::cout << v1 * rm1 << std::endl;
    std::cout << v1 * rm1 << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << rm1 * v1 << std::endl;
    std::cout << rm1 * v1 << std::endl;


    return 0;
}
