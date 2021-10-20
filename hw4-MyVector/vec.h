#ifndef VEC_H
#define VEC_H
#include <vector>
#include <iostream>

using namespace std;

class Vec {
public:
    vector<double> data;

    Vec(int);
    void init(const vector<double>&);

    Vec add(const Vec&) const;
    Vec sub(const Vec&) const;
    Vec mult(double) const;
    Vec div(double) const;
    double dot(const Vec&) const;
    double angleBetween(const Vec&) const;
    
    double mag() const;
    void setMag(double);
    void normalize();
    void random();
    int ndim() const;


    Vec operator+(const Vec&) const;
    Vec operator-(const Vec&) const;
    Vec operator*(double) const;
    Vec operator/(double) const;
    double operator*(const Vec&) const;

    friend ostream& operator<<(ostream&, const Vec&);
};

#endif