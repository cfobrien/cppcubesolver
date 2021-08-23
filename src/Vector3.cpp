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

    // Static methods
    static Vector3 zeros() {
        return Vector3(0,0,0);
    }
    static Vector3 ones() {
        return Vector3(1,1,1);
    }
    static Vector3 X() {
        return Vector3(1,0,0);
    }
    static Vector3 Y() {
        return Vector3(0,1,0);
    }
    static Vector3 Z() {
        return Vector3(0,0,1);
    }

    // Methods
    std::string toString() {
        std::ostringstream oss;
        oss << "(" << x << "," << y << "," << z << ")\n";
        return oss.str();
    }

    double * toArray() {
        static double a[3];
        a[0] = x; a[1] = y; a[2] = z;
        return a;
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
