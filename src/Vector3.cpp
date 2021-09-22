#include "Vector3.h"

#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

// Constructors
Vector3::Vector3(): x(0.0), y(0.0), z(0.0) {}
Vector3::Vector3(const double x, const double y, const double z):
    x(x), y(y), z(z) {}
Vector3::Vector3(const int x, const int y, const int z):
    x(double(x)), y(double(y)), z(double(z)) {}
Vector3::Vector3(double * a): x(a[0]), y(a[1]), z(a[2]) {}

// Vector3::operator overloading
Vector3 Vector3::operator + (const Vector3 &v) const {
    return Vector3(x+v.x,y+v.y,z+v.z);
}
Vector3 Vector3::operator + (double const& d) const {
    return Vector3(x+d,y+d,z+d);
}
Vector3 operator + (double const& d, Vector3 const& v) {
    return Vector3(v.x+d,v.y+d,v.z+d);
}

Vector3 Vector3::operator - () const {
    return Vector3(-x, -y, -z);
}
Vector3 Vector3::operator - (const Vector3 &v) const {
    return Vector3(x-v.x,y-v.y,z-v.z);
}
Vector3 Vector3::operator - (double const& d) const {
    return Vector3(x-d,y-d,z-d);
}
Vector3 operator - (double const& d, Vector3 const& v) {
    return Vector3(v.x-d,v.y-d,v.z-d);
}

Vector3 Vector3::operator * (const Vector3 &v) const {
    return Vector3(x*v.x,y*v.y,z*v.z);
}
Vector3 Vector3::operator * (const double &d) const {
    return Vector3(x*d,y*d,z*d);
}
Vector3 operator * (double const& d, Vector3 const& v) {
    return Vector3(v.x*d,v.y*d,v.z*d);
}

Vector3 Vector3::operator / (const Vector3 &v) const {
    return Vector3(x/v.x,y/v.y,z/v.z);
}
Vector3 Vector3::operator / (const double &d) const {
    return Vector3(x/d,y/d,z/d);
}
Vector3 operator / (double const& d, Vector3 const& v) {
    return Vector3(v.x/d,v.y/d,v.z/d);
}

bool Vector3::operator < (const Vector3 &v) const {
    const Vector3 &u = *this;
    if (u.x < v.x && u.y < v.y && u.z < v.z)
        return true;
    else
        return false;
}

bool Vector3::operator <= (const Vector3 &v) const {
    const Vector3 &u = *this;
    if (u.x <= v.x && u.y <= v.y && u.z <= v.z)
        return true;
    else
        return false;
}

bool Vector3::operator > (const Vector3 &v) const {
    const Vector3 &u = *this;
    if (u.x > v.x && u.y > v.y && u.z > v.z)
        return true;
    else
        return false;
}

bool Vector3::operator >= (const Vector3 &v) const {
    const Vector3 &u = *this;
    if (u.x >= v.x && u.y >= v.y && u.z >= v.z)
        return true;
    else
        return false;
}

bool Vector3::operator == (const Vector3 &v) const {
    const Vector3 &u = *this;
    Vector3 error = (u-v).abs();
    if (error.x <= VECT_COMP_TOLERANCE &&
        error.y <= VECT_COMP_TOLERANCE &&
        error.z <= VECT_COMP_TOLERANCE) {
        return true;
    } else {
        return false;
    }
}

bool Vector3::operator != (const Vector3 &v) const {
    const Vector3 &u = *this;
    if (u == v) {
        return false;
    } else {
        return true;
    }
}

Vector3& Vector3::operator += (const Vector3 &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3& Vector3::operator -= (const Vector3 &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vector3& Vector3::operator *= (const Vector3 &v) {
    x *= v.x;
    y *= v.y;
    z *= v.z;
    return *this;
}
Vector3& Vector3::operator *= (const double &d) {
    x *= d;
    y *= d;
    z *= d;
    return *this;
}

Vector3& Vector3::operator /= (const Vector3 &v) {
    x /= v.x;
    y /= v.y;
    z /= v.z;
    return *this;
}
Vector3& Vector3::operator /= (const double &d) {
    x /= d;
    y /= d;
    z /= d;
    return *this;
}

std::ostream& operator << (std::ostream& os, Vector3 v) {
    os << v.toString();
    return os;
}

double& Vector3::operator[](int index) {
    switch(index) {
        case 0: return x; break;
        case 1: return y; break;
        case 2: return z; break;
        case 3: return one; break;
        default: return zero;
    }
}

// Static methods
Vector3 Vector3::zeros() {
    return Vector3(0,0,0);
}
Vector3 Vector3::ones() {
    return Vector3(1,1,1);
}
Vector3 Vector3::X() {
    return Vector3(1,0,0);
}
Vector3 Vector3::Y() {
    return Vector3(0,1,0);
}
Vector3 Vector3::Z() {
    return Vector3(0,0,1);
}

// Methods
std::string Vector3::toString() {
    std::ostringstream oss;
    oss << "(" << x << "," << y << "," << z << ")";
    return oss.str();
}

double Vector3::norm() {
    return std::sqrt(SQ(x)+SQ(y)+SQ(z));
}

Vector3 Vector3::normalized() {
    double norm = this->norm();
    return *this*(1/norm);
}

Vector3 Vector3::abs() {
    return Vector3(
        std::abs(x),
        std::abs(y),
        std::abs(z)
    );
}

Vector3 Vector3::magnetize() {
    return Vector3(
        std::nearbyint(x),
        std::nearbyint(y),
        std::nearbyint(z)
    );
}

bool Vector3::contains(Vector3 v) {
    const Vector3 &u = *this;
    Vector3 error = (u-v).abs();
    return ((std::abs(v.x) > VECT_COMP_TOLERANCE) && (error.x <= VECT_COMP_TOLERANCE)) ||
           ((std::abs(v.y) > VECT_COMP_TOLERANCE) && (error.y <= VECT_COMP_TOLERANCE)) ||
           ((std::abs(v.z) > VECT_COMP_TOLERANCE) && (error.z <= VECT_COMP_TOLERANCE));
}
