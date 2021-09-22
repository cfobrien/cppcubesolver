#include "Cube.h"

#define X Vector3::X()
#define Y Vector3::Y()
#define Z Vector3::Z()

Cube::Cube() {
    cubies = {
        // Centres:
        Cubie({
            CubieFace(X, BLUE)
        }),
        Cubie({
            CubieFace(Y, RED)
        }),
        Cubie({
            CubieFace(Z, YELLOW)
        }),
        Cubie({
            CubieFace(-X, GREEN)
        }),
        Cubie({
            CubieFace(-Y, ORANGE)
        }),
        Cubie({
            CubieFace(-Z, WHITE)
        }),
        // Edges:
        Cubie({
            CubieFace(X, BLUE),
            CubieFace(Z, YELLOW)
        }),
        Cubie({
            CubieFace(Y, RED),
            CubieFace(Z, YELLOW)
        }),
        Cubie({
            CubieFace(-X, GREEN),
            CubieFace(Z, YELLOW)
        }),
        Cubie({
            CubieFace(-Y, ORANGE),
            CubieFace(Z, YELLOW)
        }),

        Cubie({
            CubieFace(X, BLUE),
            CubieFace(-Z, WHITE)
        }),
        Cubie({
            CubieFace(Y, RED),
            CubieFace(-Z, WHITE)
        }),
        Cubie({
            CubieFace(-X, GREEN),
            CubieFace(-Z, WHITE)
        }),
        Cubie({
            CubieFace(-Y, ORANGE),
            CubieFace(-Z, WHITE)
        }),

        Cubie({
            CubieFace(X, BLUE),
            CubieFace(Y, RED)
        }),
        Cubie({
            CubieFace(Y, RED),
            CubieFace(-X, GREEN)
        }),
        Cubie({
            CubieFace(-X, GREEN),
            CubieFace(-Y, ORANGE)
        }),
        Cubie({
            CubieFace(X, BLUE),
            CubieFace(-Y, ORANGE)
        }),

        // Corners:
        Cubie({
            CubieFace(X, BLUE),
            CubieFace(Y, RED),
            CubieFace(Z, YELLOW)
        }),
        Cubie({
            CubieFace(-X, GREEN),
            CubieFace(Y, RED),
            CubieFace(Z, YELLOW)
        }),
        Cubie({
            CubieFace(-X, GREEN),
            CubieFace(-Y, ORANGE),
            CubieFace(Z, YELLOW)
        }),
        Cubie({
            CubieFace(X, BLUE),
            CubieFace(-Y, ORANGE),
            CubieFace(Z, YELLOW)
        }),

        Cubie({
            CubieFace(X, BLUE),
            CubieFace(Y, RED),
            CubieFace(-Z, WHITE)
        }),
        Cubie({
            CubieFace(-X, GREEN),
            CubieFace(Y, RED),
            CubieFace(-Z, WHITE)
        }),
        Cubie({
            CubieFace(-X, GREEN),
            CubieFace(-Y, ORANGE),
            CubieFace(-Z, WHITE)
        }, -X-Y-Z),
        Cubie({
            CubieFace(X, BLUE),
            CubieFace(-Y, ORANGE),
            CubieFace(-Z, WHITE)
        })

    };
}
void Cube::rotateFace(Vector3 normal, double angle) {
    for (auto qb : cubies) {
        //TODO: matches, not equal to. Dot product?
        if (qb.pos == normal) {
            qb.rotate(normal, angle);
        }
    }
}

std::string Cube::toString() {
    std::ostringstream oss;
    for (auto qb : cubies) {
        oss << qb.toString();
    }
    return oss.str();
}

CubieFace Cube::findqbf(Vector3 pos, Vector3 dir) {
    CubieFace cubieface = CubieFace(Vector3::zeros(), -1);
    for (auto qb : cubies)
        if (qb.pos == pos)
            for (auto qbf : qb.qbfaces)
                if (qbf.normal == dir)
                    cubieface = qbf;
    return cubieface;
}

std::vector<std::vector<CubieFace>> Cube::makeFace(Vector3 normal, Vector3 corner, Vector3 edge) {
    std::vector<CubieFace> row1;
    std::vector<CubieFace> row2;
    std::vector<CubieFace> row3;

    RotationMatrix rm = RotationMatrix(normal, -M_PI/2);
    row1.push_back(findqbf(corner, normal)); // 1
    row1.push_back(findqbf(edge, normal)); // 2
    corner = (corner * rm).magnetize();
    edge = (edge * rm).magnetize();
    row1.push_back(findqbf(corner, normal)); // 3

    // 4 missing
    row2.push_back(findqbf(normal, normal)); // 5
    row2.push_back(findqbf(edge, normal)); // 6

    // 7 missing
    corner = (corner * rm).magnetize();
    edge = (edge * rm).magnetize();
    row3.push_back(findqbf(edge, normal)); // 8
    row3.push_back(findqbf(corner, normal)); // 9

    corner = (corner * rm).magnetize();
    edge = (edge * rm).magnetize();

    row2.emplace(row2.begin(), findqbf(edge, normal));

    row3.emplace(row3.begin(), findqbf(corner, normal));

    std::vector<std::vector<CubieFace>> face = {row1, row2, row3};
    return face;
}

std::string Cube::display() {
    std::ostringstream oss;

    auto yface = makeFace(Z, X-Y+Z, -Y+Z);
    auto bface = makeFace(X, X-Y+Z, X+Z);
    auto rface = makeFace(Y, X+Y+Z, Y+Z);
    auto gface = makeFace(-X, -X+Y+Z, -X+Z);
    auto oface = makeFace(-Y, -X-Y+Z, -Y+Z);
    auto wface = makeFace(-Z, X+Y-Z, Y-Z);

    for (auto qbf_vec : yface) {
        for (auto qbf : qbf_vec) {
            oss << qbf << " ";
        }
        oss << "\n";
    }

    for (auto qbf_vec : bface) {
        for (auto qbf : qbf_vec) {
            oss << qbf << " ";
        }
        oss << "\n";
    }
    for (auto qbf_vec : rface) {
        for (auto qbf : qbf_vec) {
            oss << qbf << " ";
        }
        oss << "\n";
    }
    for (auto qbf_vec : gface) {
        for (auto qbf : qbf_vec) {
            oss << qbf << " ";
        }
        oss << "\n";
    }
    for (auto qbf_vec : oface) {
        for (auto qbf : qbf_vec) {
            oss << qbf << " ";
        }
        oss << "\n";
    }
    for (auto qbf_vec : wface) {
        for (auto qbf : qbf_vec) {
            oss << qbf << " ";
        }
        oss << "\n";
    }

    return oss.str();
}

std::ostream& operator << (std::ostream& os, Cube cube) {
    os << cube.display();
    return os;
}
