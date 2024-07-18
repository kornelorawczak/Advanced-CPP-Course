#include <iostream>
using namespace std;

class Queue{
private:
    int volume;
    int start = 0;
    int status = 0;
    int index = 0;
    string *tab;
public:
    explicit Queue(int vol);
    Queue();
    Queue(initializer_list<string> list);
    Queue(Queue &q);
    Queue(Queue &&other) noexcept;

    Queue& operator = (Queue& other);

    Queue& operator = (Queue&& other) noexcept;

    void put(string element);

    string pop();

    string see_front();

    int length();

    bool is_empty();

    ~Queue();
};
