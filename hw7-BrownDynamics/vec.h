#ifndef VEC_H
#define VEC_H
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Vec {
public:
    vector<double> data;

    Vec(){}
    Vec(int);
    void init(const vector<double>&);

    Vec add(const Vec&) const;
    Vec sub(const Vec&) const;
    Vec mult(double) const;
    Vec div(double) const;
    double dot(const Vec&) const;
    
    double model() const;
    int ndim() const;

    Vec operator+(const Vec&) const;
    Vec operator-(const Vec&) const;
    Vec operator*(double) const;
    Vec operator/(double) const;
    double operator*(const Vec&) const;

    friend ostream& operator<<(ostream&, const Vec&);
};

Vec::Vec(int n) {
    data = vector<double> (n,0);
}

void Vec::init(const vector<double>& v) {
    int idim = ndim();

    if (idim != v.size()) {
        cerr << "Dimensions of two vectors are not equal!" << endl;
        exit(1);
    }

    for (int i=0; i<idim; ++i) {
        data[i] = v[i];
    }
}

Vec Vec::add(const Vec& v) const {
    int idim = ndim();

    if (idim != v.ndim()) {
        cerr << "Dimensions of two vectors are not equal!" << endl;
        exit(1);
    }

    Vec w(idim);
    for (int i=0; i<idim; ++i) {
        w.data[i] = data[i] + v.data[i];
    }
    return w;
}

Vec Vec::sub(const Vec& v) const {
    int idim = ndim();

    if (idim != v.ndim()) {
        cerr << "Dimensions of two vectors are not equal!" << endl;
        exit(1);
    }

    Vec w(idim);
    for (int i=0; i<idim; ++i) {
        w.data[i] = data[i] - v.data[i];
    }
    return w;
}

Vec Vec::mult(double a) const {
    int idim = ndim();

    Vec v(idim);
    for (int i=0; i<idim; ++i) {
        v.data[i] = data[i] * a;
    }
    return v;
}

Vec Vec::div(double a) const {
    int idim = ndim();

    Vec v(idim);
    for (int i=0; i<idim; ++i) {
        v.data[i] = data[i] / a;
    }
    return v;
}

double Vec::dot(const Vec& v) const {
    int idim = ndim();

    if (idim != v.ndim()) {
        cerr << "Dimensions of two vectors are not equal!" << endl;
        exit(1);
    }

    double ans = 0.0;
    for (int i=0; i<idim; ++i) {
        ans += (data[i] * v.data[i]);
    }
    return ans;
}

double Vec::model() const {
    int idim = ndim();
    double ans = 0.0;

    for (int i=0; i<idim; ++i) {
        ans += (data[i] * data[i]);
    }
    return sqrt(ans);
}

int Vec::ndim() const {
    return data.size();
}

Vec Vec::operator+(const Vec& v) const {
    return add(v);
}

Vec Vec::operator-(const Vec& v) const {
    return sub(v);
}

Vec Vec::operator*(double a) const {
    return mult(a);
}

Vec Vec::operator/(double a) const {
    return div(a);
}

double Vec::operator*(const Vec& v) const {
    return dot(v);
}

ostream& operator<<(ostream& out, const Vec& v) {
    int idim = v.ndim();

    for (int i=0; i<idim; ++i) {
        out << v.data[i] << " ";
    }
    return out;
}

#endif