#include "BinaryNode.h"

BinaryNode::BinaryNode()
{
    data = 0;
    parent = nullptr;
    leftC = nullptr;
    rightC = nullptr;
}
BinaryNode::BinaryNode(int value)
{
    data = value;
    parent = nullptr;
    leftC = nullptr;
    rightC = nullptr;
}
bool BinaryNode::setRightChild(BinaryNode*ptr)
{
    rightC = ptr;
    return true;
}
BinaryNode* BinaryNode::getRightChild()
{
    return leftC;
}
bool BinaryNode::setLeftChild(BinaryNode*ptr)
{
    leftC = ptr;
    return true;
}
BinaryNode* BinaryNode::getLeftChild()
{
    return leftC;
}
bool BinaryNode::setParent(BinaryNode*ptr)
{
    parent= ptr;
    return true;
}
BinaryNode* BinaryNode::getParent()
{
    return parent;
}
bool BinaryNode::setData(int value)
{
    data = value;
    return true;
}
int BinaryNode::getData()
{
    return data;
}
BinaryNode::~BinaryNode()
{
    //dtor
}
