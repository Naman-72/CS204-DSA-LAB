#include "Array.h"

Array::Array()
{
    elements=nullptr;
    capacity=0;
}
Array::Array(int arraySize)
{
    elements= new int[arraySize];
    capacity=arraySize;
}
int Array::getCapacity()
{
    return capacity;
}
Array::Array(int arraySize,int default_value)
{
    elements= new int[arraySize];
    capacity=arraySize;
    for(int i =0; i<capacity; i++)
    {
        elements[i]=default_value;
    }
}
int Array::getElement(int index)
{
    if((index>=capacity)||(index<0))
    {
        return -1;
    }
    return elements[index];
}
bool Array::setElement(int index,int value)
{
    if((index>=capacity)||(index<0))
    {
        return false;
    }
    elements[index]=value;
    return true;
}
Array::~Array()
{
    delete[] elements;
}
