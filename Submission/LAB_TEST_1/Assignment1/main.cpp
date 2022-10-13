#include <iostream>
#include "InvertingStack.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    InvertingStack I(5);
    I.pushInvert(50);
    I.pushInvert(71);
    I.print();
    I.pushInvert(99);
    I.print();
    I.pushInvert(125);
    I.pushInvert(192);
    I.print();
    I.popInvert();
    I.print();
    I.popInvert();
    I.print();

    return 0;
}
