#include <iostream>
#include "queue.hpp"
using namespace std;

Queue::Queue(int vol) : volume(vol), tab(new string[vol]) {}
Queue::Queue() : Queue(1) {}
Queue::Queue(initializer_list<string> list) {
    tab = new string[list.size()];
    copy(list.begin(), list.end(), tab);
    volume = status = list.size();
}
Queue::Queue(Queue &q){
    tab = new string[q.length()];
    if (!q.is_empty()){
        tab[0] = q.pop();
        status = 1;
    }
    index = (index + 1) % q.volume;
}
Queue::Queue(Queue &&other) noexcept : tab(other.tab), volume(other.volume), start(other.start), index(other.index), status(other.status){
    other.tab = nullptr;
    other.status = 0;
}

Queue& Queue::operator = (Queue& other){
    if (this != &other){
        tab = new string[other.length()];
        if (!other.is_empty()){
            index = (index + 1) % other.length();
            status = 1;
            tab[start] = other.pop();
        }
        volume = other.length();
        return *this;
    }
}

Queue& Queue::operator = (Queue&& other) noexcept {
    if (this != &other){
        tab = other.tab;
        index = other.index;
        status = other.status;
        start = other.status;
        volume = other.volume;
        other.tab = nullptr;
        other.status = 0;
    }
    return *this;
}

void Queue::put(string element){
    if (status == volume){
        throw "Queue is full!";
    }
    else{
        status+=1;
        tab[index] = element;
        index = (index + 1) % volume;
    }
}

string Queue::pop(){
    if (status > 0){
        string to_pop = tab[start];
        status-=1;
        start = (start + 1) % volume;
        return to_pop;
    }
    else{
        throw "Queue is empty!";
    }
}

string Queue::see_front(){
    if (status > 0){
        return tab[start];
    }
    else{
        throw "Queue is empty!";
    }
}

int Queue::length(){
    return status;
}

bool Queue::is_empty(){
    return status == 0;
}

Queue::~Queue(){
    delete[] tab;
}

