#include "Cubie.h"

void Cubie::updateCubieStatus(unsigned int numFaces) {
    switch(numFaces) {
        case 1:
            centre = true;
            corner = false;
            edge = false;
            break;
        case 2:
            edge = true;
            corner = false;
            centre = false;
            break;
        case 3:
            corner = true;
            edge = false;
            centre = false;
            break;
        // TODO: Default, too many cubies exception
    };
}

Cubie::Cubie() {
    corner = false;
    edge = false;
    centre = false;
    qbfaces = {};
}

Cubie::Cubie(std::vector<CubieFace> qbfaces) {
    this->pos = Vector3::zeros();
    this->qbfaces = qbfaces;
    if (!this->qbfaces.empty()) {
        updateCubieStatus(qbfaces.size());
        for (auto qbf : qbfaces) {
            this->pos += qbf.normal;
        }
    }
}

Cubie::Cubie(std::vector<CubieFace> qbfaces, Vector3 pos) {
    this->pos = pos;
    this->qbfaces = qbfaces;
    if (!this->qbfaces.empty()) {
        updateCubieStatus(qbfaces.size());
    }
}

void Cubie::rotate(Vector3 axis, double angle) {
    RotationMatrix rm = RotationMatrix(axis, angle);
}

void Cubie::rotate(RotationMatrix rm) {
    for (auto qbf : qbfaces) {
        qbf.rotate(rm);
    }
}

std::string Cubie::toString() {
    std::ostringstream oss;
    oss << "\033[1m";
    if (corner) oss << "Corner ";
    else if (edge) oss << "Edge ";
    else if (centre) oss << "Centre ";

    oss << pos << ":\033[0m" << std::endl;
    for (auto qbf : qbfaces) {
        oss << "\033[" << qbf.colour << "m" << qbf.normal << std::endl;
    }
    oss << "\033[0m";
    return oss.str();
}

std::ostream& operator << (std::ostream& os, Cubie qb) {
    os << qb.toString();
    return os;
}
