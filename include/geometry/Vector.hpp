#ifndef __VECTOR_HPP
#define __VECTOR_HPP

#include <iostream>
#include <cmath>

namespace Geometry
{
    struct Vector
    {
        double x, y;
        Vector(double x, double y) : x(x), y(y) {}
        Vector() : x(0), y(0) {}
        Vector operator+(const Vector &v) const
        {
            return Vector(x + v.x, y + v.y);
        }
        Vector operator-(const Vector &v) const
        {
            return Vector(x - v.x, y - v.y);
        }
        Vector operator*(double c) const
        {
            return Vector(x * c, y * c);
        }
        Vector operator/(double c) const
        {
            return Vector(x / c, y / c);
        }
        double operator*(const Vector &v) const
        {
            return x * v.x + y * v.y;
        }
        double operator^(const Vector &v) const
        {
            return x * v.y - y * v.x;
        }
        double norm() const
        {
            return sqrt(x * x + y * y);
        }
        double norm2() const
        {
            return x * x + y * y;
        }
        Vector normalize() const
        {
            return *this / norm();
        }
        Vector rotate(double angle) const
        {
            return Vector(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
        }
        double angle() const
        {
            return atan2(y, x);
        }
        bool operator==(const Vector &v) const
        {
            return x == v.x && y == v.y;
        }
        bool operator!=(const Vector &v) const
        {
            return x != v.x || y != v.y;
        }
    };
}

#endif // __VECTOR_HPP