#include "Face.h"
#include "Vector3.h"
#include "RotationMatrix.h"

Face::Face(Vector3 normal, char colour): normal(normal), colour(colour) {}
void Face::Rotate(Vector3 axis, double angle) {
    normal = normal * RotationMatrix(axis, angle);
}
