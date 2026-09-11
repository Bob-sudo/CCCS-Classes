#ifndef VEC2_H
#define VEC2_H

#include <iostream>
#include <cmath>

class ValueError
{};

template < typename T >
class vec2
{
  public:
  vec2()
      : x_(T()), y_(T())
    {}
    
  vec2(T x, T y)
      : x_(x), y_(y)
    {}
    
    bool operator==(const vec2<T> & v) const
        {
            return !(*this == v);
        }

    bool operator!=(const vec2<T> & v) const
    {
        return !(*this != v);
    }
    
    T get_x() const
    {
        return x_;
    }

    T get_y() const
    {
        return y_;
    }
    
    void set_x(T x)
    {
        x_ = x;
    }

    void set_y(T y)
    {
        y_ = y;
    }

    
    T operator[](int i) const
    {
        if(i > 1 || i < 0) throw ValueError();
        return (i == 0) ? x_ : y_;
    }

    T & operator[](int i)
    {
        if(i > 1 || i < 0) throw ValueError();
        return (i == 0) ? x_ : y_;
    }
    
    vec2<T> operator+() const
    {
        return *this;
    }

    vec2<T> & operator+=(const vec2<T> & v)
    {
        x_ += v.x_;
        y_ += v.y_;
        return *this;
    }

    vec2<T> operator+(const vec2<T> & v) const
    {
        return (vec2(*this) += v);
    }
   
    vec2<T> operator-() const
    {
        return *this;
    }

    vec2<T> & operator-=(const vec2<T> & v)
    {
        x_ -= v.x_;
        y_ -= v.y_;
        return *this;
    }

    vec2<T> operator-(const vec2<T> & v) const
    {
        return (vec2(*this) -= v);
    }

    vec2<T> & operator*=(double d)
    {
        x_ *= d;
        y_ *= d;
        return (*this);
    }
    
    vec2<T> operator*(double d) const
    {
        return (vec2(*this) *= d);
    }

    vec2<T> & operator/=(T d)
    {
        x_ /= d;
        y_ /= d;
        return (*this);
    }
    
    vec2<T> operator/(T d) const
    {
        return (vec2(*this) /= d);
    }
    
    double len() const
    {
        return std::sqrt(x_ * x_ + y_ * y_);
    }
  private:
    T x_, y_;
};

template <typename T>
vec2<T> operator*(T c, const vec2<T> & v)
{
    return v * c;
}

template <typename T>
double len(const vec2<T> & v)
{
    return v.len();
}

template <typename T>
T dotprod(const vec2<T> & u, const vec2<T> & v)
{
    return u.get_x() * v.get_x() + u.get_y() * v.get_y();
}

template <typename T>
vec2<T> norm(const vec2<T> & v)
{
    return v / v.len();
}

template <typename T>
std::ostream & operator<<(std::ostream & cout, const vec2<T> & v)
{
    cout << '<' << v.get_x() << ", " << v.get_y() << '>';
    return cout;
}

template <typename T>
std::istream & operator>>(std::istream & cin, vec2<T> & v)
{
    T x, y;
    cin >> x >> y;
    
    if (cin)
    {
        v.set_x(x);
        v.set_y(y);
    }
    
    return cin;
}

#endif
