#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include<cmath>
#include<iostream>

template<typename T>
struct Vec2{
    union{
        struct{T x,y;};
        struct{T u,v;};
        T raw[2];
    };
    Vec2() : x(0), y(0) {}
    Vec2(T _x, T _y) : x(_x), y(_y) {}
    Vec2<T> operator+(const Vec2<T> &v) const { return Vec2<T>(x+v.x, y+v.y); }
    Vec2<T> operator-(const Vec2<T> &v) const { return Vec2<T>(x-v.x, y-v.y); }
    Vec2<T> operator*(T f) const { return Vec2<T>(x*f, y*f); }
    template<typename >
    friend std::ostream& operator<<(std::ostream &s, Vec2<T> &v);
}; 

template<typename T>
struct Vec3{
    union{
        struct{T x,y,z;};
        struct{T u,v,w;};
        T raw[3];
    };
    Vec3() : x(0), y(0), z(0) {}
    Vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}
    Vec3<T> operator^(const Vec3<T> &v) const { return Vec3<T>(y*v.z-z*v.y, z*v.x-x*v.z, x*v.y-y*v.x); }
    Vec3<T> operator+(const Vec3<T> &v) const { return Vec3<T>(x+v.x, y+v.y, z+v.z); }
    Vec3<T> operator-(const Vec3<T> &v) const { return Vec3<T>(x-v.x, y-v.y, z-v.z); }
    Vec3<T> operator*(float f) const { return Vec3<T>(x*f, y*f, z*f); }
    T operator*(const Vec3<T> &v) const { return x*v.x+y*v.y+z*v.z; }
    float norm() const { return std::sqrt(x*x+y*y+z*z); }
    Vec3<T> &normalize(T l=1) { *this = (*this)*(l/norm()); return *this; }
    T dot(const Vec3<T> &v) const { return x*v.x+y*v.y+z*v.z; }
    template<typename >
    friend std::ostream& operator<<(std::ostream &s, Vec3<T> &v);
};

typedef Vec2<int> Vec2i;
typedef Vec2<float> Vec2f;
typedef Vec3<float> Vec3f;
typedef Vec3<int> Vec3i;

template<typename T>
std::ostream& operator<<(std::ostream &s, Vec2<T> &v)
{
    s << "(" << v.x << ", " << v.y << ")\n";
    return s;
}

template<typename T>
std::ostream& operator<<(std::ostream &s, Vec3<T> &v)
{
    s << "(" << v.x << ", " << v.y << ", " << v.z << ")\n";
    return s;
}


#endif // _GEOMETRY_H__