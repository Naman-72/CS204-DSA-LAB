#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <iostream>
using namespace std;

class BinaryNode
{
    public:
        BinaryNode();
        BinaryNode(int);
        bool setRightChild(BinaryNode*ptr);
        BinaryNode* getRightChild();
        bool setLeftChild(BinaryNode*ptr);
        BinaryNode* getLeftChild();
        bool setParent(BinaryNode*ptr);
        BinaryNode* getParent();
        bool setData(int);
        int getData();
        virtual ~BinaryNode();

    protected:

    private:
        BinaryNode*parent;
        BinaryNode*leftC; //leftChild
        BinaryNode*rightC; //RightChild
        int data;
};

#endif // BINARYNODE_H
