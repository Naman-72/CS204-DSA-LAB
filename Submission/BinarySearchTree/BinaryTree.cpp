#include "BinaryTree.h"
#include "BinaryNode.h"
using namespace std;
BinaryTree::BinaryTree()
{
    root = nullptr;
}
BinaryTree::BinaryTree(int value)
{  root = new BinaryNode();
    root->setData(value);
    root->setRightChild(nullptr);
    root->setLeftChild(nullptr);
    root->setParent(nullptr);
}
void BinaryTree::postPrint(BinaryNode*ptr)
{
    if(ptr==nullptr)
    {
        return;
    }
    cout<<ptr->getData()<<" ";
    postPrint(ptr->getLeftChild());
    postPrint(ptr->getRightChild());
}
BinaryNode* BinaryTree::getRoot()
{
    return root;
}
void BinaryTree::AddLeftNode(int data,BinaryNode*ptrp)
{
    BinaryNode*ptrc=new BinaryNode(data);
   if(root!=nullptr){
    ptrp->setLeftChild(ptrc);
    ptrc->setParent(ptrp);
   }
   return;
}
void BinaryTree::AddRightNode(int data,BinaryNode*ptrp)
{
    BinaryNode*ptrc=new BinaryNode(data);
   if(root!=nullptr){
    ptrp->setRightChild(ptrc);
    ptrc->setParent(ptrp);
   }
   return;
}

BinaryTree::~BinaryTree()
{
    //dtor
}
