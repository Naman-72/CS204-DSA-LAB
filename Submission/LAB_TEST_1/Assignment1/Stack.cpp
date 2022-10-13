#include "Stack.h"

Stack::Stack()
{
    valueCount=0;
}
Stack::Stack(int capacity):A(capacity)
{
    valueCount=0;
}
bool Stack::isEmpty()
{
    if(valueCount==0)
    {
        return true;
    }
    return false;
}
bool Stack::isFull()
{
    if(valueCount==A.getCapacity())
    {
        return true;
    }
    return false;
}
bool Stack::push(int value)
{
    if(isFull())
    {
        return false;
    }
    A.setElement(valueCount,value);
    valueCount++;
    return true;
}
int Stack::pop()
{
    if(isEmpty())
    {
        return false;
    }
    valueCount--;
    return A.getElement(valueCount);
}
Stack::~Stack()
{
    //dtor
}
