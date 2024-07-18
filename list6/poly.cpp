#include <iostream>
#include "poly.hpp"
using namespace std;


int n; // polynomial degree
double *a; // factors

poly::poly (){
    n = 0;
    a = new double[1];
    a[0] = 1.0;
}
poly::poly (int degree, const double factors[]){
    if (degree != 0 && factors[degree] == 0){
        throw invalid_argument("Wrong factors input!");
    }
    n = degree;
    a = new double[n + 1];
    copy(factors, factors + degree + 1, a);
}
poly::poly (initializer_list<double> factors){
    if (factors.size() != 1 && *(factors.end() - 1) == 0){
        throw invalid_argument("Wrong factors input!");
    }
    n = factors.size() - 1;
    a = new double[factors.size() + 1];
    copy(factors.begin(), factors.end(), a);
}
poly::poly (const poly &p) : a(p.a), n(p.n) {}
poly::poly (poly &&p) noexcept : a(p.a), n(p.n){
    p.a = nullptr;
    p.n = 0;
}
poly& poly::operator = (const poly &other){
    if (this != &other){
        n = other.n;
        a = other.a;
    }
    return *this;
}
poly& poly::operator = (poly &&other) noexcept {
    if (this != &other){
        n = other.n;
        a = other.a;
        other.n = 0;
        other.a = nullptr;
    }
    return *this;
}

poly& poly::operator += (const poly &v){
//    if (v.n > n){
//        double *new_a = new double[v.n + 1];
//        for (int i = n + 1; i < v.n + 1; i++){
//            new_a[i] = v.a[i];
//        }
//        for (int i = 0; i < n + 1; i++){
//            new_a[i] = a[i] + v.a[i];
//        }
//        a = new_a;
//        delete[] new_a;
//        n = v.n;
//    }
//    else{
//        for (int i = 0; i < v.n + 1; i++){
//            a[i] += v.a[i];
//        }
//    }
    *this = *this + v;
    return *this;
}
poly& poly::operator -= (const poly &v){
//    if (v.n > n){
//        double *new_a = new double[v.n + 1];
//        for (int i = n + 1; i < v.n + 1; i++){
//            new_a[i] = -1 * v.a[i];
//        }
//        for (int i = 0; i < n + 1; i++){
//            new_a[i] = a[i] - v.a[i];
//        }
//        a = new_a;
//        delete[] new_a;
//        n = v.n;
//    }
//    else{
//        for (int i = 0; i < v.n + 1; i++){
//            a[i] -= v.a[i];
//        }
//    }
    *this = *this - v;
    return *this;
}

poly& poly::operator *= (const poly &v){
//    const int degree = n + v.n;
//    double *coefficients = new double[degree + 1];
//    for (int i = 0; i <= degree; i++){
//        coefficients[i] = 0;
//    }
//    for (int i = 0; i <= n; i++){
//        for (int j = 0; j <= v.n; j++){
//            coefficients[i + j] += (a[i] * v.a[j]);
//        }
//    }
//    n = degree;
//    a = coefficients;
//    delete[] coefficients;
    *this = *this * v;
    return *this;
}

poly& poly::operator *= (const double c){
    *this = *this * c;
    return *this;
}

double poly::operator () (double x) const{
    double res = a[n];
    for (int i = n - 1; i >= 0; i--){
        res = res * x + a[i];
    }
    return res;
}

double poly::operator [] (int i) const{
    if (i < 0 || i > n) { throw invalid_argument("Index given is out of range!"); }
    return a[i];
}

double& poly::operator [] (int i){
    if (i < 0 || i > n) { throw invalid_argument("Index given is out of range!"); }
    if (i == n && n != 0 && a[i] == 0) { throw invalid_argument("Highest coefficient can't be set to 0"); }
    return a[i];
}

int poly::get_degree(){
    return n;
}

poly::~poly(){
    delete[] a;
}


poly operator + (const poly &u, const poly &v){
    if (u.n >= v.n){
        const int degree = u.n;
        double *coefficients;
        coefficients = new double[degree + 1];
        copy(u.a, u.a + degree + 1, coefficients);
        for (int i = 0; i <= v.n; i++){
            coefficients[i] += v.a[i];
        }
        poly returnal = poly(degree, coefficients);
        delete[] coefficients;
        return returnal;
    }
    else{
        const int degree = v.n;
        double *coefficients;
        coefficients = new double[degree + 1];
        copy(v.a, v.a + degree + 1, coefficients);
        for (int i = 0; i <= u.n; i++){
            coefficients[i] += u.a[i];
        }
        poly returnal = poly(degree, coefficients);
        delete[] coefficients;
        return returnal;
    }
}

poly operator - (const poly &u, const poly &v){
    if (u.n >= v.n){
        const int degree = u.n;
        double *coefficients;
        coefficients = new double[degree + 1];
        copy(u.a, u.a + degree + 1, coefficients);
        for (int i = 0; i <= v.n; i++){
            coefficients[i] -= v.a[i];
        }
        poly returnal = poly(degree, coefficients);
        delete[] coefficients;
        return returnal;
    }
    else{
        const int degree = v.n;
        double *coefficients;
        coefficients = new double[degree + 1];
        copy(v.a, v.a + degree + 1, coefficients);
        for (int i = 0; i <= u.n; i++){
            coefficients[i] -= u.a[i];
        }
        poly returnal = poly(degree, coefficients);
        delete[] coefficients;
        return returnal;
    }
}

poly operator * (const poly &u, const poly &v) {
    const int degree = u.n + v.n;
    double *coefficients;
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; i++){
        coefficients[i] = 0;
    }
    for (int i = 0; i <= u.n; i++){
        for (int j = 0; j <= v.n; j++){
            coefficients[i + j] += (u.a[i] * v.a[j]);
        }
    }
    poly returnal = poly(degree, coefficients);
    return returnal;
}

poly operator * (const poly &u, const double c){
    if (c == 0){ throw invalid_argument("Can't do that!"); }
    for (int i = 0; i <= u.n; i++){
        u.a[i] *= c;
    }
    return u;
}


istream& operator >> (istream &we, poly &w){
    cout << "Insert the degree of a polynomial: ";
    we >> w.n;
    w.a = new double[w.n + 1];
    cout << "Insert coefficients one by one: ";
    for (int i = 0; i <= w.n; i++){
        we >> w.a[i];
    }
    if (w.a[w.n] == 0){
        throw invalid_argument("Wrong input!");
    }
    return we;
}

ostream& operator << (ostream &wy, poly &w){
    wy << "Degree of a polynomial: " << w.n << endl;
    wy << "Polynomial in a sum: ";
    if (w.n > 0){
        wy << w.a[w.n] << "x^" << w.n;
    }
    for (int i = w.n - 1; i > 0; i--){
        if (w.a[i] < 0){
            wy << " - " << -1 * w.a[i] << "x^" << i;
        }
        else if (w.a[i] > 0){
            wy << " + " << w.a[i] << "x^" << i;
        }
    }
    if (w.a[0] < 0){
        wy << " - " << -1 * w.a[0];
    }
    else if (w.a[0] > 0){
        wy << " + " << w.a[0];
    }
    cout << endl;
    return wy;
}