#ifndef __CUBIE_FACE
#define __CUBIE_FACE

#include "Vector3.h"
#include "RotationMatrix.h"
#include <ostream>

#define WHITE 37
#define YELLOW 33
#define RED 31
#define GREEN 32
#define ORANGE 35
#define BLUE 34

class CubieFace {
public:
    Vector3 normal;
    int colour;

    CubieFace(Vector3 normal, char colour);
    void rotate(Vector3 axis, double angle);
    void rotate(RotationMatrix rm);

    friend std::ostream& operator << (std::ostream& os, CubieFace qbf);
};

#endif //__CUBIE_FACE
