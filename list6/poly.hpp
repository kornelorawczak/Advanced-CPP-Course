#include <initializer_list>
#include <iostream>

using namespace std;

class poly{
private:
    int n; // polynomial degree
    double *a; // factors
public:
    explicit poly ();
    poly (int degree, const double factors[]);
    poly (initializer_list<double> factors);
    poly (const poly &p);
    poly (poly &&p) noexcept;
    poly& operator = (const poly &other);
    poly& operator = (poly &&other) noexcept;
    friend istream& operator >> (istream &we, poly &w);
    friend ostream& operator << (ostream &wy, poly &w);
    friend poly operator + (const poly &u, const poly &v);
    friend poly operator - (const poly &u, const poly &v);
    friend poly operator * (const poly &u, const poly &v);
    friend poly operator * (const poly &u, const double c);
    poly& operator += (const poly &v);
    poly& operator -= (const poly &v);
    poly& operator *= (const poly &v);
    poly& operator *= (const double c);
    double operator () (double x) const;
    double operator [] (int i) const;
    double& operator [] (int i);
    int get_degree();
    ~poly();
};

