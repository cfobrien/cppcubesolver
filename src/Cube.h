#ifndef __CUBE
#define __CUBE

#include "CubieFace.h"
#include "Cubie.h"
#include "RotationMatrix.h"
#include "Vector3.h"
#include <vector>
#include <ostream>
#include <sstream>

class Cube {
public:
    std::vector<Cubie> cubies;

    Cube();
    void rotateFace(Vector3 normal, double angle);
    std::string toString();
    std::string display();
    std::vector<std::vector<CubieFace>> makeFace(Vector3 normal, Vector3 corner, Vector3 edge);
    CubieFace findqbf(Vector3 pos, Vector3 dir);
    friend std::ostream& operator << (std::ostream& os, Cube cube);

};

#endif //__CUBE
