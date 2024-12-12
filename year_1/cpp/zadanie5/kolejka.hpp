#pragma once
#include <stdexcept>

class Queue
{
    private:
        int capacity;
        int start = 0;
        int count = 0;
        std::string *tab;

    public:
        Queue(int capacity);

        Queue();

        Queue(const std::initializer_list<std::string> list);

        Queue(const Queue &other);

        Queue(Queue&& other);

        Queue& operator=(const Queue &other);

        Queue& operator=(Queue &&other);

        ~Queue();

        void push(std::string text);

        std::string remove();

        std::string peek();

        int length();


};