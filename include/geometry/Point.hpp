#ifndef __POINT_HPP
#define __POINT_HPP

#include <iostream>
#include <cmath>

#include "geometry/Vector.hpp"

struct Point
{
    double x, y;
    Point(double x, double y) : x(x), y(y) {}
    Point() : x(0), y(0) {}
    Point operator+(const Point &p) const
    {
        return Point(x + p.x, y + p.y);
    }
    Point operator-(const Point &p) const
    {
        return Point(x - p.x, y - p.y);
    }
    Point operator*(double c) const
    {
        return Point(x * c, y * c);
    }
    Point operator/(double c) const
    {
        return Point(x / c, y / c);
    }
    Point operator+(const Vector &v) const
    {
        return Point(x + v.x, y + v.y);
    }

    double operator*(const Point &p) const
    {
        return x * p.x + y * p.y;
    }
    double operator^(const Point &p) const
    {
        return x * p.y - y * p.x;
    }
    double norm() const
    {
        return sqrt(x * x + y * y);
    }
    double norm2() const
    {
        return x * x + y * y;
    }
    Point normalize() const
    {
        return *this / norm();
    }
    Point rotate(double angle) const
    {
        return Point(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
    }
    double angle() const
    {
        return atan2(y, x);
    }
    bool operator==(const Point &p) const
    {
        return x == p.x && y == p.y;
    }
    bool operator!=(const Point &p) const
    {
        return x != p.x || y != p.y;
    }
    friend std::ostream &operator<<(std::ostream &os, const Point &p)
    {
        return os << "(" << p.x << ", " << p.y << ")";
    }
    friend std::istream &operator>>(std::istream &is, Point &p)
    {
        return is >> p.x >> p.y;
    }

    const SDL_Point *toSDLPoint() const
    {
        SDL_Point *p = new SDL_Point();
        p->x = x;
        p->y = y;
        return p;
    }
};

#endif // __POINT_HPP