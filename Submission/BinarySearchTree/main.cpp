#include <iostream>
#include "BinaryNode.h"
#include "BinaryTree.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    BinaryTree A(100);
    BinaryNode* ptr = A.getRoot();
    A.AddLeftNode(80,ptr);
   ptr=A.getRoot();
    A.AddRightNode(120,ptr);
   ptr=A.getRoot();
   while(ptr->getLeftChild()!=nullptr)
   {
        ptr = ptr->getLeftChild();
   }
   A.AddLeftNode(40,ptr);
   A.AddRightNode(90,ptr);
   ptr=A.getRoot();
   while(ptr->getLeftChild()!=nullptr)
   {
        ptr = ptr->getLeftChild();
   }
   A.AddRightNode(50,ptr);
   ptr = A.getRoot();
   while(ptr->getRightChild()!=nullptr)
   {
        ptr = ptr->getRightChild();
   }
   A.AddLeftNode(110,ptr);
   A.AddRightNode(500,ptr);
   ptr = A.getRoot();
   A.postPrint(ptr);
    return 0;
}
