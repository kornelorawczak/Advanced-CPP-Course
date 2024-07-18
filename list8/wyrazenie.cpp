#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <utility>
#include <iomanip>
#include "wyrazenie.hpp"

using namespace std;


Liczba::Liczba(double wartosc) : Wyrazenie(), wartosc(wartosc) {}
double Liczba::oblicz() const { return wartosc; }
string Liczba::zapis() const {
    if (wartosc == floor(wartosc)){
        return to_string(static_cast<int>(wartosc));
    }
    return to_string(wartosc); }

Zmienna::Zmienna(const string& nazwa) : Wyrazenie() {
    this->nazwa = nazwa;
}
void Zmienna::dodajZmienna(const string& nazwa, double wartosc) {
    for (auto& para : zmienne) {
        if (para.first == nazwa) {
            para.second = wartosc;
            return;
        }
    }
    zmienne.push_back(make_pair(nazwa, wartosc));
}
void Zmienna::usunZmienna(const string& nazwa) {
    for (auto& para : zmienne) {
        if (para.first == nazwa) {
            zmienne.erase(find(zmienne.begin(), zmienne.end(), para));
            return;
        }
    }
    throw invalid_argument("Nie da się usunąć zmiennej której nie ma!");
}
void Zmienna::wyczysc(){
    zmienne.clear();
}
double Zmienna::oblicz() const  {
    for (const auto& para : zmienne) {
        if (para.first == nazwa) {
            return para.second;
        }
    }
    throw invalid_argument("Nie znaleziono zmiennej o nazwie: " + nazwa);
}
string Zmienna::zapis() const  { return nazwa; }




Stala::Stala(const string& nazwa, double wartosc) : Wyrazenie(), nazwa(nazwa), wartosc(wartosc) {}
double Stala::oblicz() const { return wartosc; }
string Stala::zapis() const { return nazwa; }



Pi::Pi() : Stala("pi", M_PI) {}


E::E() : Stala("e", M_E) {}


Fi::Fi() : Stala("fi", (1 + sqrt(5)) / 2) {}



Operator1arg::Operator1arg(Wyrazenie* expr) : wyrazenie(expr) {}



Sin::Sin(Wyrazenie* expr) : Operator1arg(expr) {}
double Sin::oblicz() const {
    return sin(wyrazenie->oblicz());
}
string Sin::zapis() const {
    return "sin(" + wyrazenie->zapis() + ")";
}


Cos::Cos(Wyrazenie* expr) : Operator1arg(expr) {}
double Cos::oblicz() const {
    return cos(wyrazenie->oblicz());
}
string Cos::zapis() const {
    return "cos(" + wyrazenie->zapis() + ")";
}


Tg::Tg(Wyrazenie* expr) : Operator1arg(expr) {}
double Tg::oblicz() const {
    return tan(wyrazenie->oblicz());
}
string Tg::zapis() const {
    return "tg(" + wyrazenie->zapis() + ")";
}


Ln::Ln(Wyrazenie* expr) : Operator1arg(expr) {}
double Ln::oblicz() const {
    return log(wyrazenie->oblicz());
}
string Ln::zapis() const {
    return "ln(" + wyrazenie->zapis() + ")";
}



Abs::Abs(Wyrazenie* expr) : Operator1arg(expr) {}
double Abs::oblicz() const {
    return abs(wyrazenie->oblicz());
}
string Abs::zapis() const {
    return "|" + wyrazenie->zapis() + "|";
}


Przeciw::Przeciw(Wyrazenie* expr) : Operator1arg(expr) {}
double Przeciw::oblicz() const {
    return (-1) * (wyrazenie->oblicz());
}
string Przeciw::zapis() const {
    return "-(" + wyrazenie->zapis() + ")";
}


Odwrot::Odwrot(Wyrazenie* expr) : Operator1arg(expr) {}
double Odwrot::oblicz() const {
    return 1/(wyrazenie->oblicz());
}
string Odwrot::zapis() const {
    return "1/(" + wyrazenie->zapis() + ")";
}


Operator2arg::Operator2arg(Wyrazenie* expr1, Wyrazenie* expr2) : wyrazenie1(expr1), wyrazenie2(expr2) {}

Dodaj::Dodaj(Wyrazenie* e1, Wyrazenie* e2) : Operator2arg(e1, e2) {}
double Dodaj::oblicz() const {
    return wyrazenie1->oblicz() + wyrazenie2->oblicz();
}
string Dodaj::zapis() const {
    return "(" + wyrazenie1->zapis() + " + " + wyrazenie2->zapis() + ")";
}


Odejmij::Odejmij(Wyrazenie* e1, Wyrazenie* e2) : Operator2arg(e1, e2) {}
double Odejmij::oblicz() const {
    return wyrazenie1->oblicz() - wyrazenie2->oblicz();
}
string Odejmij::zapis() const {
    return "(" + wyrazenie1->zapis() + " - " + wyrazenie2->zapis() + ")";
}

Mnozenie::Mnozenie(Wyrazenie* e1, Wyrazenie* e2) : Operator2arg(e1, e2) {}
double Mnozenie::oblicz() const {
    return wyrazenie1->oblicz() * wyrazenie2->oblicz();
}
string Mnozenie::zapis() const {
    return wyrazenie1->zapis() + " * " + wyrazenie2->zapis();
}


Dzielenie::Dzielenie(Wyrazenie* e1, Wyrazenie* e2) : Operator2arg(e1, e2){
    if (e2->oblicz() == 0) {
        throw new invalid_argument("Divide by 0 error!");
    }
}
double Dzielenie::oblicz() const {
    return wyrazenie1->oblicz() / wyrazenie2->oblicz();
}
string Dzielenie::zapis() const {
    return wyrazenie1->zapis() + " / " + wyrazenie2->zapis();
}


Potega::Potega(Wyrazenie* podstawa, Wyrazenie* wykladnik) : Operator2arg(podstawa, wykladnik) {}
double Potega::oblicz() const {
    return pow(wyrazenie1->oblicz(), wyrazenie2->oblicz());
}
string Potega::zapis() const {
    return wyrazenie1->zapis() + "^" + wyrazenie2->zapis();
}


Logarytm::Logarytm(Wyrazenie* podstawa, Wyrazenie* argument) : Operator2arg(podstawa, argument) {}
double Logarytm::oblicz() const {
    double wartoscPodstawy = wyrazenie1->oblicz();
    double wartoscArgumentu = wyrazenie2->oblicz();
    if (wartoscPodstawy <= 0 || wartoscPodstawy == 1 || wartoscArgumentu <= 0) throw runtime_error("Invalid logarithm base or argument");
    return log(wartoscArgumentu) / log(wartoscPodstawy);
}
string Logarytm::zapis() const {
    return "log(" + wyrazenie1->zapis() + ")_(" + wyrazenie2->zapis() + ")";
}
