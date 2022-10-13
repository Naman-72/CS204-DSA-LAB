#ifndef DLLNODE_H
#define DLLNODE_H
#include <iostream>
using namespace std;

class DLLNode
{
public:
    DLLNode();
    DLLNode(int);
    int getData();
    void setData(int);
    DLLNode* getNextPtr();
    void setNextPtr(DLLNode*);
    DLLNode* getPrevPtr();
    void setPrevPtr(DLLNode*);
    virtual ~DLLNode();

protected:

private:
    DLLNode* next;
    DLLNode* prev;
    int data;

};

#endif // DLLNODE_H
