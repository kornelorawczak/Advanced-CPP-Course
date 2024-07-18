#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    float a,b,c;
    clog << "Please insert value of first triangle side: " <<endl; // Version without dane.txt
    cin >> a;
    clog << "Please insert value of second triangle side: " <<endl;
    cin >> b;
    clog << "Please insert value of third triangle side: " <<endl;
    cin >> c;
    if (a<=0 or b<=0 or c<=0 or a+b<=c or a+c<=b or b+c<=a){
        cout << "Inputted values can't make a triangle!" << endl;
    }
    else{
        float perimeter = a+b+c;
        float field = sqrt((perimeter/2)*(perimeter/2-a)*(perimeter/2-b)*(perimeter/2-c));
        cout << "Perimeter = " << setprecision(floor(log10(perimeter)) + 4) << perimeter << " and field = " << setprecision(floor(log10(field)) + 4) << field << endl;

    }
    return 0;
}
