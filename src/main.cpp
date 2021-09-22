#include <iostream>
#include "Vector3.h"
#include "RotationMatrix.h"
#include "Cube.h"

int main(int argc, char **argv) {
    // std::cout << "\033[33;44myellow on blue\n";

    Cube q = Cube();
    std::cout << q << std::endl;
    std::cout << q.toString();

    return 0;
}
