#include <iostream>
#include "DLLNode.h"
#include "CircularDLL.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    CircularDLL A;
    A.printDLL();
    A.addB(100);
    A.printDLL();
    A.findMirrorPts();
    A.addB(200);
    A.printDLL();
    A.findMirrorPts();
    A.addE(200);
    A.printDLL();
    A.findMirrorPts();
    A.addB(100);
    A.printDLL();
    A.findMirrorPts();
    return 0;
}
