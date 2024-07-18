#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <utility>
#include <iomanip>
#include "wyrazenie.hpp"
using namespace std;



vector<pair<string, double> > Zmienna::zmienne;


int main() {
    cout << fixed << setprecision(2);
    Wyrazenie* expr1 = new Dodaj(
            new Mnozenie(new Pi, new Zmienna("x")),
            new Odejmij(new Liczba(5), new Odwrot(new Liczba(-4)))
            );
    double x = 0;
    for(int i = 0; i < 10; i++){
        x += 0.1;
        Zmienna::dodajZmienna("x", x);
        cout << "Wyrazenie 1: " << expr1->zapis() << " = " << expr1->oblicz() << endl;
    }
    Zmienna::dodajZmienna("y", 3);
    Wyrazenie* expr2 = new Potega(
            new Sin(new Cos(new Abs(
                    new Dzielenie(new Liczba(10), new Przeciw(new Zmienna("y")) )))),
                    new Liczba(2)
            );
    cout << "Wyrazenie 2: " << expr2->zapis() << " = " << expr2->oblicz() << endl;
    delete expr1;
    delete expr2;
    Zmienna::wyczysc();
    return 0;
}
