#include "CircularDLL.h"

CircularDLL::CircularDLL()
{
    head=nullptr;
    tail=nullptr;
}
bool CircularDLL::addB(int value)
{
    if(head==nullptr)
    {
        DLLNode*temp = new DLLNode(value);
        head=temp;
        tail = temp;
        return true;
    }
    DLLNode*temp = new DLLNode(value);
    temp->setNextPtr(head);
    temp->setPrevPtr(tail);
    head=temp;
    temp->getNextPtr()->setPrevPtr(temp);
    temp->getPrevPtr()->setNextPtr(temp);
    return true;
}
bool CircularDLL::addE(int value)
{

    if(tail==nullptr)
    {
        DLLNode*temp = new DLLNode(value);
        head=temp;
        tail=temp;
        return true;
    }
    DLLNode*temp = new DLLNode(value);
    temp->setNextPtr(head);
    temp->setPrevPtr(tail);
    tail = temp;
    temp->getNextPtr()->setPrevPtr(temp);
    temp->getPrevPtr()->setNextPtr(temp);
    return true;
}
void CircularDLL::printDLL()
{
    if(tail==nullptr)
    {
        return ;
    }
    DLLNode*curr = head;
    while(curr!=tail)
    {
        cout<<curr->getData()<<" ";
        curr= curr->getNextPtr();
    }
    cout<<curr->getData()<<" ";
    cout<<endl;
    return;
}
void CircularDLL::findMirrorPts()
{
    DLLNode* curr = head;
    if(head==nullptr)
    {
        cout<<"Total mirror points: 0 Indices:"<<endl;
        return;
    }
    if(head==tail)
    {
        cout<<"Total mirror points: 1 Indices: 0"<<endl;
        return;
    }
    if(head->getNextPtr()==tail)
    {
        cout<<"Total mirror points: 2 Indices: 0 1"<<endl;
        return;
    }
    int noIndices=0;
     while(curr->getNextPtr()!=head)
    {
        DLLNode* start= curr;
        DLLNode* last= curr;
        while((start->getNextPtr()->getData())==(last->getPrevPtr()->getData()))
        {
            start=start->getNextPtr();
            last=last->getNextPtr();
            if(start->getNextPtr()==last)
            {
                 noIndices++;
                 break;
            }
            if(start==last)
            {
                   noIndices++;
                   break;
            }
        }
        curr=curr->getNextPtr();
    }
    DLLNode* start= curr;
    DLLNode* last= curr;
    while((start->getNextPtr()->getData())==(last->getPrevPtr()->getData()))
    {
        start=start->getNextPtr();
        last=last->getNextPtr();
        if(start->getNextPtr()==last)
        {
             noIndices++;
            break;
        }
        if(start==last)
        {
            noIndices++;
            break;
        }
    }

    curr=head;
    start=curr;
    last=curr;
    cout<<"Total mirror points: "<<noIndices<<" Indices:";
    int index = 0;
    while(curr->getNextPtr()!=head)
    {
         start= curr;
         last= curr;
        while((start->getNextPtr()->getData())==(last->getPrevPtr()->getData()))
        {
            start=start->getNextPtr();
            last=last->getNextPtr();
            if(start->getNextPtr()==last)
            {
                cout<<" "<<index;
                break;
            }
            if(start==last)
            {
                cout<<" "<<index;
                break;
            }
        }
        index++;
        curr=curr->getNextPtr();
    }
   start= curr;
   last= curr;
    while((start->getNextPtr()->getData())==(last->getPrevPtr()->getData()))
    {
        start=start->getNextPtr();
        last=last->getNextPtr();
        if(start->getNextPtr()==last)
        {
            cout<<" "<<index;
            break;
        }
        if(start==last)
        {
            cout<<" "<<index;
            break;
        }
    }
    cout<<endl;

    return;
}
CircularDLL::~CircularDLL()
{
    //dtor
}
