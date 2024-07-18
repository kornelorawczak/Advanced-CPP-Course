#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <utility>
#include <iomanip>
#ifndef WYRAZENIA_HPP
#define WYRAZENIA_HPP
using namespace std;

class Wyrazenie {
public:
    Wyrazenie() {}
    virtual double oblicz() const = 0;
    virtual string zapis() const = 0;
    virtual ~Wyrazenie() {}
private:
    Wyrazenie(const Wyrazenie&) = delete;
    Wyrazenie& operator=(const Wyrazenie&) = delete;
    Wyrazenie(Wyrazenie&&) = delete;
    Wyrazenie& operator=(Wyrazenie&&) = delete;
};

class Liczba : public Wyrazenie {
private:
    double wartosc;
public:
    Liczba(double wartosc);
    double oblicz() const override;
    string zapis() const override;
};

class Zmienna : public Wyrazenie {
private:
    static vector<pair<string, double> > zmienne;
    string nazwa;
public:
    Zmienna(const string& nazwa);
    static void dodajZmienna(const string& nazwa, double wartosc) ;
    static void usunZmienna(const string& nazwa) ;
    static void wyczysc();
    double oblicz() const override;
    string zapis() const override;
};


class Stala : public Wyrazenie {
private:
    double wartosc;
    string nazwa;
public:
    Stala(const string& nazwa, double wartosc);
    double oblicz() const override;
    string zapis() const override;
};

class Pi : public Stala {
public:
    Pi();
};

class E : public Stala {
public:
    E();
};

class Fi : public Stala {
public:
    Fi();
};

class Operator1arg : public Wyrazenie {
protected:
    unique_ptr<Wyrazenie> wyrazenie;
public:
    explicit Operator1arg(Wyrazenie* expr);
};

class Sin : public Operator1arg {
public:
    explicit Sin(Wyrazenie* expr);
    double oblicz() const override;
    string zapis() const override;
};

class Cos : public Operator1arg {
public:
    explicit Cos(Wyrazenie* expr);
    double oblicz() const override;
    string zapis() const override;
};

class Tg : public Operator1arg {
public:
    explicit Tg(Wyrazenie *expr);

    double oblicz() const override;

    string zapis() const override;
};
class Ln : public Operator1arg {
public:
    explicit Ln(Wyrazenie* expr) ;
    double oblicz() const override;
    string zapis() const override;
};

class Abs : public Operator1arg {
public:
    explicit Abs(Wyrazenie* expr);
    double oblicz() const override;
    string zapis() const override;
};

class Przeciw : public Operator1arg {
public:
    explicit Przeciw(Wyrazenie* expr) ;
    double oblicz() const override;
    string zapis() const override;
};

class Odwrot : public Operator1arg {
public:
    explicit Odwrot(Wyrazenie* expr);
    double oblicz() const  override;
    string zapis() const  override;
};

class Operator2arg : public Wyrazenie {
protected:
    unique_ptr<Wyrazenie> wyrazenie1;
    unique_ptr<Wyrazenie> wyrazenie2;
public:
    explicit Operator2arg(Wyrazenie* expr1, Wyrazenie* expr2);
};

class Dodaj : public Operator2arg {
public:
    Dodaj(Wyrazenie* e1, Wyrazenie* e2);
    double oblicz() const  override;
    string zapis() const  override;
};

class Odejmij : public Operator2arg {
public:
    Odejmij(Wyrazenie* e1, Wyrazenie* e2) ;
    double oblicz() const  override;
    string zapis() const  override;
};

class Mnozenie : public Operator2arg {
public:
    Mnozenie(Wyrazenie* e1, Wyrazenie* e2);
    double oblicz() const  override;
    string zapis() const  override;
};

class Dzielenie : public Operator2arg {
public:
    Dzielenie(Wyrazenie* e1, Wyrazenie* e2) ;
    double oblicz() const  override;
    string zapis() const  override;
};

class Potega : public Operator2arg {
public:
    Potega(Wyrazenie* podstawa, Wyrazenie* wykladnik);
    double oblicz() const  override;
    string zapis() const  override;
};

class Logarytm : public Operator2arg {
public:
    Logarytm(Wyrazenie *podstawa, Wyrazenie *argument);

    double oblicz() const override;

    string zapis() const override;
};



#endif