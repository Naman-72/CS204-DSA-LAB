#ifndef INVERTINGSTACK_H
#define INVERTINGSTACK_H
#include "Stack.h"
#include "Queue.h"
class InvertingStack
{
    public:
        InvertingStack()=delete;
        InvertingStack(int);
        void popInvert();
        void pushInvert(int);
        bool isEmpty();
        bool isFull();
        void print();
        virtual ~InvertingStack();

    protected:

    private:
        Stack S1;
        Queue Q1;
        int capacity;
};

#endif // INVERTINGSTACK_H
