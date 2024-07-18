#include <iostream>
using namespace std;

class number{
private:
    double current;
    double *history = nullptr;
    const static int size = 3;
    unsigned int index = 0;
    unsigned int status;
public:
    explicit number(double num){
        status = 0;
        current = num;
        history = new double[size];
        history[0] = current;
    }
    number() : number(0){};
    number(number &Num) : number(Num.current){}
    number(number&& other) noexcept : current(other.current), index(other.index), status(other.status) {
        history = other.history;
        other.history = nullptr;
    }
    number& operator=(const number& other) {
        if (this != &other){
            current = other.current;
            index = other.index;
            status = 0;
            history = new double[size];
            history[0] = current;
        }
        return *this;
    }
    number& operator=(number&& other) noexcept{
        if (this != &other){
            current = other.current;
            index = other.index;
            status = other.status;
            history = other.history;
            other.history = nullptr;
        }
        return *this;
    }

    double get_value(){
        return history[index];
    }
    void set_value(double num){
        if (index != size - 1) status += 1;
        current = num;
        index = (index + 1) % size;
        history[index] = num;
    }
    double recover(){
        if (status != 0) {
            index = (index - 1 + size) % size;
            current = history[index];
            status -= 1;
        }
        return current;
    }
    ~number(){
        delete[] history;
    }
};




int main() {
    number test_n = number(10);
    cout<<test_n.recover()<<endl;
    cout<<test_n.recover()<<endl;
    test_n.set_value(20);
    test_n.set_value(30);
    test_n.set_value(40);
    cout<<test_n.get_value()<<endl;
    cout<<test_n.recover()<<endl;
    cout<<test_n.recover()<<endl;
    cout<<test_n.recover()<<endl;
    cout<<test_n.recover()<<endl;
    test_n.set_value(60);
    number t2 = test_n;
    cout<<t2.get_value()<<endl;
    cout<<t2.recover()<<endl;
    number t3;
    t3 = move(test_n);
    cout<<t3.get_value()<<endl;
    cout<<t3.recover()<<endl;
    cout<<t3.recover()<<endl;

    return 0;
}
