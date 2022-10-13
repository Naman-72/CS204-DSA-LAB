#ifndef STACK_H
#define STACK_H
#include "Array.h"

class Stack
{
public:
    Stack();
    Stack(int);
    bool isEmpty();
    bool isFull();
    int pop();
    bool push(int);
    virtual ~Stack();

protected:

private:
    Array A;
    int valueCount;
};

#endif // STACK_H
