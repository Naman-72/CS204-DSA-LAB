#ifndef CIRCULARDLL_H
#define CIRCULARDLL_H
#include "DLLNode.h"

class CircularDLL
{
    public:
        CircularDLL();
        bool addB(int);
        bool addE(int);
        void printDLL();
        void findMirrorPts();
        virtual ~CircularDLL();

    protected:

    private:
        DLLNode* head;
        DLLNode* tail;

};

#endif // CIRCULARDLL_H
