#include "graphnode.h"

graphnode::graphnode()
{
    data = 0;
    child = nullptr;
}
graphnode::graphnode(int a)
{
    data = a;
    child = nullptr;
}
bool graphnode::setData(int a)
{
    data = a;
    return true;
}
bool graphnode::setChild(graphnode* ptr)
{
    child = ptr;
    return true;
}
int graphnode::getData()
{
    return data;
}
graphnode* graphnode::getChild()
{
    return child;
}
graphnode::~graphnode()
{
    //dtor
}
