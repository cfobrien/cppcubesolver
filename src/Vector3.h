#ifndef __VECTOR3__
#define __VECTOR3__

#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

#define SQ(x) std::pow(x,2.0)
#define VECT_COMP_TOLERANCE 0.005

class Vector3 {
public:
    double x, y, z;

    // Constructors
    Vector3();
    Vector3(const double x, const double y, const double z);
    Vector3(const int x, const int y, const int z);
    Vector3(double * a);

    // Operator overloading
    Vector3 operator + (const Vector3 &v) const;
    Vector3 operator + (const double &d) const;
    friend Vector3 operator + (double const& d, Vector3 const& v) {
        return Vector3(
            this.x+d,
            this.y+d,
            this.z+d
        );
    }
    Vector3 operator - (const Vector3 &v) const;
    Vector3 operator - (const double &d) const;
    friend Vector3 operator - (double const& d, Vector3 const& v) {
        return Vector3(
            this.x-d,
            this.y-d,
            this.z-d
        );
    }
    Vector3 operator * (const Vector3 &v) const;
    Vector3 operator * (const double &d) const;
    friend Vector3 operator * (double const& d, Vector3 const& v) {
        return Vector3(
            this.x*d,
            this.y*d,
            this.z*d
        );
    }
    Vector3 operator / (const Vector3 &v) const;
    Vector3 operator / (const double &d) const;
    friend Vector3 operator / (double const& d, Vector3 const& v) {
        return Vector3(
            this.x/d,
            this.y/d,
            this.z/d
        );
    }
    bool operator < (const Vector3 &v) const;
    bool operator <= (const Vector3 &v) const;
    bool operator > (const Vector3 &v) const;
    bool operator >= (const Vector3 &v) const;
    bool operator == (const Vector3 &v) const;
    bool operator != (const Vector3 &v) const;
    Vector3& operator += (const Vector3 &v);
    Vector3& operator -= (const Vector3 &v);
    Vector3& operator *= (const Vector3 &v);
    Vector3& operator *= (const double &d);
    Vector3& operator /= (const Vector3 &v);
    Vector3& operator /= (const double &d);

    // Static methods
    static Vector3 zeros();
    static Vector3 ones();
    static Vector3 X();
    static Vector3 Y();
    static Vector3 Z();

    // Methods
    std::string toString();

    double * toArray();

    //TODO: overload << operator instead
    void print();
    void println();

    double norm();

    Vector3 normalized();

    Vector3 abs();
};

#endif //__VECTOR3
