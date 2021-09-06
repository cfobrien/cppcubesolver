#ifndef __FACE
#define __FACE

#include "Vector3.h"

#define WHITE -1
#define YELLOW -2
#define RED -3
#define GREEN -4
#define ORANGE -5
#define BLUE -6

class Face {
public:
    Vector3 normal;
    char colour;

    Face(Vector3 normal, char colour);
    void Rotate(Vector3 axis, double angle);
};

#endif
