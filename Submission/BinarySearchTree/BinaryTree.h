#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "BinaryNode.h"

class BinaryTree
{
    public:
        BinaryTree();
        BinaryTree(int);
        BinaryNode* getRoot();
        void AddLeftNode(int data,BinaryNode*parent);
        void AddRightNode(int data,BinaryNode*parent);
        void postPrint(BinaryNode*);
        virtual ~BinaryTree();

    protected:

    private:
        BinaryNode*root;
};

#endif // BINARYTREE_H
