#include "DLLNode.h"

DLLNode::DLLNode()
{
    data=0;
    next=nullptr;
    prev=nullptr;
}
DLLNode::DLLNode(int value)
{
    data=value;
    next=nullptr;
    prev=nullptr;
}
void DLLNode::setNextPtr(DLLNode*temp)
{
    next = temp;
    return;
}
void DLLNode::setPrevPtr(DLLNode*temp)
{
    prev = temp;
    return;
}
void DLLNode::setData(int value)
{
    data=value;
    return;
}
int DLLNode::getData()
{
    return data;
}
DLLNode* DLLNode::getNextPtr()
{
    return next;
}
DLLNode* DLLNode::getPrevPtr()
{
    return prev;
}
DLLNode::~DLLNode()
{
    //dtor
}
