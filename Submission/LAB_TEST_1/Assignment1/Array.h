#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
using namespace std;

class Array
{
public:
    Array();
    Array(int);
    Array(int,int);
    bool setElement(int,int);
    int getCapacity();
    int getElement(int index);
    virtual ~Array();
protected:

private:
    int *elements;
    int capacity;
};

#endif // ARRAY_H
