#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

#define SQ(x) std::pow(x,2.0)

class Vector3 {
public:
    double x, y, z;

    // Constructors
    Vector3(const double x = 0.0, const double y = 0.0, const double z = 0.0):
        x(x), y(y), z(z) {}
    Vector3(const int x = 0, const int y = 0, const int z = 0):
        x(x), y(y), z(z) {}

    // Operator overloading
    Vector3 operator + (const Vector3 &v) const {
        return Vector3(x+v.x,y+v.y,z+v.z);
    }
    Vector3 operator - (const Vector3 &v) const {
        return Vector3(x-v.x,y-v.y,z-v.z);
    }
    Vector3 operator * (const Vector3 &v) const {
        return Vector3(x*v.x,y*v.y,z*v.z);
    }
    Vector3 operator * (const double &d) const {
        return Vector3(x*d,y*d,z*d);
    }
    Vector3 operator / (const Vector3 &v) const {
        return Vector3(x/v.x,y/v.y,z/v.z);
    }
    Vector3 operator / (const double &d) const {
        return Vector3(x/d,y/d,z/d);
    }
    bool operator == (const Vector3 &v) const {
        if (x == v.x && y == v.y && z == v.z)
            return true;
        else
            return false;
    }
    bool operator != (const Vector3 &v) const {
        if (x != v.x || y != v.y || z != v.z)
            return true;
        else
            return false;
    }
    Vector3& operator += (const Vector3 &v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }
    Vector3& operator -= (const Vector3 &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }
    Vector3& operator *= (const Vector3 &v) {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }
    Vector3& operator *= (const double &d) {
        x *= d;
        y *= d;
        z *= d;
        return *this;
    }
    Vector3& operator /= (const Vector3 &v) {
        x /= v.x;
        y /= v.y;
        z /= v.z;
        return *this;
    }
    Vector3& operator /= (const double &d) {
        x /= d;
        y /= d;
        z /= d;
        return *this;
    }

    // Methods
    std::string toString() {
        std::ostringstream oss;
        oss << "(" << x << "," << y << "," << z << ")\n";
        return oss.str();
    }
    void print() {
        std::cout << this->toString();
    }

    double norm() {
        return std::sqrt(SQ(x)+SQ(y)+SQ(z));
    }

    Vector3 normalized() {
        double norm = this->norm();
        return *this*(1/norm);
    }
};
