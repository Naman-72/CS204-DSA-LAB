#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "graphnode.h"
using namespace std;

class graph
{
    public:
        graph();
        graph(int);
        bool addE(int);
        graphnode* getLast();
        graphnode* getRoot();
        virtual ~graph();
    protected:

    private:
        graphnode* root;
        graphnode* last;
};

#endif // GRAPH_H
