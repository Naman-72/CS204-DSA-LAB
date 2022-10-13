#include <iostream>
using namespace std;
class Array
{
public:
    Array();
    Array(int);
    Array(int, int);
    bool setElement(int, int);
    int getCapacity();
    int getElement(int index);
    virtual ~Array();

protected:
private:
    int *elements;
    int capacity;
};
Array::Array()
{
    elements = nullptr;
    capacity = 0;
}
Array::Array(int arraySize)
{
    elements = new int[arraySize];
    capacity = arraySize;
}
int Array::getCapacity()
{
    return capacity;
}
Array::Array(int arraySize, int default_value)
{
    elements = new int[arraySize];
    capacity = arraySize;
    for (int i = 0; i < capacity; i++)
    {
        elements[i] = default_value;
    }
}
int Array::getElement(int index)
{
    if ((index >= capacity) || (index < 0))
    {
        return -1;
    }
    return elements[index];
}
bool Array::setElement(int index, int value)
{
    if ((index >= capacity) || (index < 0))
    {
        return false;
    }
    elements[index] = value;
    return true;
}
Array::~Array()
{
    delete[] elements;
}
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

Queue::Queue()
{
    counter = 0;
}
Queue::Queue(int capacity) : A(capacity)
{
    counter = 0;
    //CREATE A NEW QUEUE USING ARRAY of Capacity as same of queue
}
bool Queue::add(int value)
{
    if (isFull())
    {
        return false;
    }
    A.setElement(counter, value);
    counter++;
    return true;
}
bool Queue::isFull()
{
    if (counter == A.getCapacity())
    {
        return true;
    }
    return false;
}
bool Queue::isEmpty()
{
    if (counter == 0)
    {
        return true;
    }
    return false;
}
int Queue::deleteElement()
{
    if (isEmpty())
    {
        return -1;
    }
    int answer = A.getElement(0);
    for (int i = 1; i < counter; i++)
    {
        A.setElement(i - 1, A.getElement(i));
    }
    counter--;
    return answer;
}

Queue::~Queue()
{
    //dtor
}
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
Stack::Stack()
{
    valueCount = 0;
}
Stack::Stack(int capacity) : A(capacity)
{
    valueCount = 0;
}
bool Stack::isEmpty()
{
    if (valueCount == 0)
    {
        return true;
    }
    return false;
}
bool Stack::isFull()
{
    if (valueCount == A.getCapacity())
    {
        return true;
    }
    return false;
}
bool Stack::push(int value)
{
    if (isFull())
    {
        return false;
    }
    A.setElement(valueCount, value);
    valueCount++;
    return true;
}
int Stack::pop()
{
    if (isEmpty())
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
class InvertingStack
{
public:
    InvertingStack() = delete;
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

InvertingStack::InvertingStack(int c) : S1(c), Q1(c)
{
    capacity = c;
}
void InvertingStack::pushInvert(int value)
{
    while (!isFull())
    {
        while (!S1.isEmpty())
        {
            Q1.add(S1.pop());
        }
        Q1.add(value);
        while (!Q1.isEmpty())
        {
            S1.push(Q1.deleteElement());
        }
        return;
    }
    return;
}
void InvertingStack::popInvert()
{
    while (!isEmpty())
    {
        S1.pop();
        while (!S1.isEmpty())
        {
            Q1.add(S1.pop());
        }
        while (!Q1.isEmpty())
        {
            S1.push(Q1.deleteElement());
        }
        return;
    }
    return;
}
void InvertingStack::print()
{
    int l = 0;
    while (!S1.isEmpty())
    {
        Q1.add(S1.pop());
        l++;
    }
    cout << l << " elements:";
    while (!Q1.isEmpty())
    {
        S1.push(Q1.deleteElement());
    }
    while (!S1.isEmpty())
    {
        int k = S1.pop();
        Q1.add(k);
        cout << " " << k;
    }
    while (!Q1.isEmpty())
    {
        S1.push(Q1.deleteElement());
    }
    cout << endl;
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

int main()
{
    int a;
    int b;
    cin >> a >> b;
    InvertingStack I(b);
    while (cin >> a)
    {
        if (a == 2)
        {
            int c;
            cin >> c;
            I.pushInvert(c);
        }
        else if (a == 3)
        {
            I.popInvert();
        }
        else if (a == 7)
        {
            I.print();
        }
    }
    return 0;
}
