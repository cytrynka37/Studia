#include "kolejka.hpp"
#include <stdexcept>

void Queue :: push(std::string text) {
    if (count >= capacity) throw std::out_of_range ("Przekroczona pojemnosc");
    tab[(count + start) % capacity] = text;
    count++;
}

std::string Queue :: remove() {
    if (count <= 0) throw std::out_of_range ("Kolejka jest pusta");
    std::string temp = tab[start];
    start = (start + 1) % capacity;
    count--;
    return temp;
}

std::string Queue :: peek() {
    if (count <= 0) throw std::out_of_range ("Kolejka jest pusta");
    return tab[start];
}

int Queue :: length(){
    return count;
}

Queue :: Queue(int capacity) : capacity(capacity) {
    if (capacity < 1) throw std::out_of_range ("Pojemnosc nie moze byc mniejsza od 1");
    tab = new std::string[capacity];
}

Queue :: Queue() : Queue(1) {};

Queue :: Queue(const std::initializer_list<std::string> list) : capacity(list.size()) {
    tab = new std::string[capacity];
    for (const auto& element : list){
        push(element);
    }
}

Queue :: ~Queue() {
    delete[] tab;
}

Queue :: Queue(const Queue &other) : capacity(other.capacity) {
    tab = new std::string[capacity];
    count = other.count;
    for (int i = 0; i < other.count; i++){
        tab[i] = other.tab[(other.start + i) % other.capacity];
    }
}

Queue :: Queue(Queue &&other) : capacity(other.capacity), start(other.start), count(other.count), tab(other.tab) {
    other.capacity = 0;
    other.start = 0;
    other.count = 0;
    other.tab = nullptr;
}

Queue& Queue :: operator=(const Queue &other) {
    if (this != &other){
        delete[] tab;
        capacity = other.capacity;
        count = other.count;
        start = 0;
        tab = new std::string[capacity];
        for (int i = 0; i < other.count; i++){
            tab[i] = other.tab[(other.start + i) % other.capacity];
        }
    }    
    return *this;
}

Queue& Queue :: operator=(Queue &&other) {
    if (this != &other){
        delete[] tab;
        capacity = other.capacity;
        start = other.start;
        count = other.count;
        tab = other.tab;

        other.capacity = 0;
        other.start = 0;
        other.count = 0;
        other.tab = nullptr;
    }
    return *this;
}