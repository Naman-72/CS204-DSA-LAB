#include "graph.h"

graph::graph()
{
    root = nullptr;
    last = nullptr;
}

graph::graph(int a)
{
   graphnode* ptr = new graphnode;
   ptr->setData(a);
   ptr->setChild(nullptr);
   root = ptr;
   last = ptr;
}
bool graph::addE(int a)
{
    if(root ==nullptr)
    {
        graphnode* ptr = new graphnode;
        ptr->setData(a);
        root = ptr;
        last= ptr;
        return true;
    }
    graphnode* ptr = new graphnode;
    ptr->setData(a);
    last->setChild(ptr);
    last = ptr;
    return true;
}
graphnode* graph::getLast()
{
    return last;
}
graphnode* graph::getRoot()
{
    return root;
}
graph::~graph()
{
    //dtor
}
