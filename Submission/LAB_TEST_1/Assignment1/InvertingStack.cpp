#include "InvertingStack.h"

InvertingStack::InvertingStack(int c):S1(c),Q1(c)
{
  capacity=c;
}
void InvertingStack::pushInvert(int value)
{
    while(!isFull())
    {
      while(!S1.isEmpty())
      {
          Q1.add(S1.pop());
      }
    Q1.add(value);
      while(!Q1.isEmpty())
      {
          S1.push(Q1.deleteElement());
      }
      return ;
    }
    return ;
}
void InvertingStack::popInvert()
{
    while(!isEmpty())
    {
        S1.pop();
        while(!S1.isEmpty())
        {
            Q1.add(S1.pop());
        }
        while(!Q1.isEmpty())
        {
            S1.push(Q1.deleteElement());
        }
        return ;
    }
    return ;
}
void InvertingStack::print()
{   int l=0;
    while(!S1.isEmpty())
    {
        Q1.add(S1.pop());
        l++;
    }
    cout<<l<<" elements:";
    while(!Q1.isEmpty())
    {
        S1.push(Q1.deleteElement());
    }
    while(!S1.isEmpty())
    {
        int k = S1.pop();
        Q1.add(k);
        cout<<" "<<k;
    }
    while(!Q1.isEmpty())
    {
        S1.push(Q1.deleteElement());
    }
    cout<<endl;
}
bool InvertingStack::isEmpty()
{
    return S1.isEmpty();
}
bool InvertingStack::isFull()
{
    return S1.isFull();
}
InvertingStack::~InvertingStack()
{
    //dtor
}
