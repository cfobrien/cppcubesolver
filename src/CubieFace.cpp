#include "CubieFace.h"

CubieFace::CubieFace(Vector3 normal, char colour): normal(normal), colour(colour) {}

void CubieFace::rotate(Vector3 axis, double angle) {
    normal = normal * RotationMatrix(axis, angle);
}

void CubieFace::rotate(RotationMatrix rm) {
    normal = normal * rm;
}

std::ostream& operator << (std::ostream& os, CubieFace qbf) {
    os << "\033[" << qbf.colour+10 << "m  \033[0m";
    return os;
}
