#include <vector>
#include <iostream>
#include <cmath>
#include <ctime>
#include "vec.h"

using namespace std;

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

double Vec::angleBetween(const Vec& v) const {
    return acos(dot(v) / (mag() * v.mag()));
}

double Vec::mag() const {
    int idim = ndim();
    double ans = 0.0;

    for (int i=0; i<idim; ++i) {
        ans += (data[i] * data[i]);
    }
    return sqrt(ans);
}

void Vec::setMag(double a) {
    int idim = ndim();
    double L = mag();

    for (int i=0; i<idim; ++i) {
        data[i] = data[i] / L * a;
    }
}

void Vec::normalize() {
    setMag(1.0);
}

void Vec::random() {
    int idim = ndim();

    for (int i=0; i<idim; ++i) {
        data[i] = rand() / (float)RAND_MAX;
    }
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

    out << "( ";
    for (int i=0; i<idim; ++i) {
        out << v.data[i] << " ";
    }
    out << ")";
    return out;
}

int main() {
    srand(time(NULL));

    Vec v(5);
    cout << v << endl;
    v.init(vector<double>{1,2,3,4,5});
    cout << v << endl;

    Vec w(5);
    w.init(vector<double>{2,4,6,8,10});
    cout << v.add(w) << endl;
    cout << v.sub(w) << endl;
    cout << v.mult(2.0) << endl;
    cout << v.div(2.0) << endl;
    cout << v.dot(w) << endl;
    cout << v.angleBetween(w) << endl;
    cout << v.mag() << endl;
    cout << v + w << endl;
    cout << w - v << endl;
    cout << v * 2.0 << endl;
    cout << v / 2.0 << endl;
    cout << v * w << endl;

    v.setMag(2.0);
    cout << v << endl;
    v.normalize();
    cout << v << endl;
    v.random();
    cout << v << endl;
}