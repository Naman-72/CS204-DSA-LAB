#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include"Array.h"
using namespace std;


class Queue
{
    public:
        Queue();
        Queue(int);
        bool add(int);
        int deleteElement();
        bool isEmpty();
        bool isFull();
        virtual ~Queue();

    protected:

    private:
        Array A;
        int counter;

};

#endif // QUEUE_H
