#ifndef __CUBIE
#define __CUBIE

#include "CubieFace.h"
#include "Vector3.h"
#include "RotationMatrix.h"
#include <vector>
#include <sstream>
#include <ostream>

class Cubie {
private:
    void updateCubieStatus(unsigned int numFaces);
public:
    bool corner, edge, centre;
    std::vector<CubieFace> qbfaces;
    Vector3 pos;

    Cubie();
    Cubie(std::vector<CubieFace> qbfaces);
    Cubie(std::vector<CubieFace> qbfaces, Vector3 pos);
    // void addFace(CubieFace qbface);
    void rotate(Vector3 axis, double angle);
    void rotate(RotationMatrix rm);
    std::string toString();

    friend std::ostream& operator << (std::ostream& os, Cubie qb);
};

#endif //__CUBIE
