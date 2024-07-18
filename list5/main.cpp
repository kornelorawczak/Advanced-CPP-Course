#include <iostream>
#include <utility>
#include "queue.hpp"

using namespace std;


int main() {
    Queue queue = Queue(3);
    queue.put("1");
    queue.put("2");
    queue.put("3");
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.see_front() << endl;
    Queue queue2 = {"raz", "dwa", "trzy", "cztery"};
    cout << queue2.see_front() << endl;
    cout << queue2.pop() << endl;
    cout << queue2.length() << endl;
    queue2.put("pięć");
    cout << queue2.length() << endl;
    Queue queue3 = queue2;
    cout << queue3.length() << endl;
    cout << queue3.pop() << endl;
    Queue queue4 = move(queue2);
    cout << queue4.length() << endl;
    cout << queue4.pop() << endl;
    cout << queue4.see_front() << endl;
    return 0;
}
