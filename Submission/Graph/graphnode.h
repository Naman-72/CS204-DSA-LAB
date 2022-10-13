#ifndef GRAPHNODE_H
#define GRAPHNODE_H
#include <iostream>
using namespace std;

class graphnode
{
    public:
        graphnode();
        graphnode(int);
        bool setChild(graphnode*);
        bool setData(int);
        graphnode* getChild();
        int getData();
        virtual ~graphnode();

    protected:

    private:
        int data;
        graphnode* child;
};

#endif // GRAPHNODE_H
