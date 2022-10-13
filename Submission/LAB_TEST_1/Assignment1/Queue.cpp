#include "Queue.h"

Queue::Queue()
{
    counter=0;
}
Queue::Queue(int capacity):A(capacity)
{
     counter=0;
    //CREATE A NEW QUEUE USING ARRAY of Capacity as same of queue
}
bool Queue::add(int value)
{
    if(isFull())
    {
        return false;
    }
    A.setElement(counter,value);
    counter++;
    return true;
}
bool Queue::isFull()
{
    if(counter == A.getCapacity())
    {
        return true;
    }
    return false;
}
bool Queue::isEmpty()
{
    if(counter == 0)
    {
        return true;
    }
    return false;
}
int Queue::deleteElement()
{
    if(isEmpty())
    {
        return -1;
    }
   int answer = A.getElement(0);
   for(int i =1;i<counter;i++)
   {
       A.setElement(i-1,A.getElement(i));
   }
   counter--;
   return answer;
}

Queue::~Queue()
{
    //dtor
}
