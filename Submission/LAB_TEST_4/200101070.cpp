#include<iostream>
#define red 'r'
#define black 'b'
using namespace std;
// ARRAY
#ifndef ARRAY_H
#define ARRAY_H
#include<iostream>
using namespace std;

class Array
{
    public:
        Array();
        Array(int);
        Array(int,int);
        bool setElement(int,int);
        int getElement(int index);
        virtual ~Array();
        int getCapacity();
    protected:

    private:
        int *elements;
        int capacity;
};

#endif // ARRAY_H

Array::Array()
{
    elements=nullptr;
    capacity=0;
}
Array::Array(int arraySize)
{
    elements= new int[arraySize];
    capacity=arraySize;
}
Array::Array(int arraySize,int default_value)
{
    elements= new int[arraySize];
    capacity=arraySize;
    for(int i =0; i<capacity; i++)
    {
        elements[i]=default_value;
    }
}
int Array::getCapacity()
{
    return capacity;
}
int Array::getElement(int index)
{
    if((index>=capacity)||(index<0))
    {
        cout<<"Element out of Array.So can't get value at index : "<<index;
        cout<<endl;
        return -1;
    }
    return elements[index];
}
bool Array::setElement(int index,int value)
{
    if((index>=capacity)||(index<0))
    {
        cout<<"Element out of Array.So can't set "<<value<<" at index "<<index<<" ."<<endl;
        return false;
    }
    elements[index]=value;
    return true;
}
Array::~Array()
{
    delete[] elements;
}
/// QUEUE
#ifndef QUEUE_H
#define QUEUE_H
using namespace std;


class Queue
{
public:
    Queue();
    Queue(int);
    bool add(int);
    int deleteElement();
    bool isEmpty();
    bool isFull();
    virtual ~Queue();

protected:

private:
    Array A;
    int counter;

};

#endif // QUEUE_H


Queue::Queue()
{
    counter=0;
}
Queue::Queue(int capacity):A(capacity)
{
    counter=0;
    //CREATE A NEW QUEUE USING ARRAY of Capacity as same of queue
}
bool Queue::add(int value)
{
    if(isFull())
    {
        cout<<"QUEUE IS FULL. SO WE CAN'T ADD "<<value<<endl;
        return false;
    }
    A.setElement(counter,value);
    counter++;
    return true;
}
bool Queue::isFull()
{
    if(counter == A.getCapacity())
    {
        return true;
    }
    return false;
}
bool Queue::isEmpty()
{
    if(counter == 0)
    {
        return true;
    }
    return false;
}
int Queue::deleteElement()
{
    if(isEmpty())
    {
        cout<<"THERE IS NO ELEMENT IN THE QUEUE "<<endl;
        return -1;
    }
    int answer = A.getElement(0);
    for(int i =1; i<counter; i++)
    {
        A.setElement(i-1,A.getElement(i));
    }
    counter--;
    return answer;
}

Queue::~Queue()
{
    //dtor
}




// RB NODE
#ifndef RBNODE_H
#define RBNODE_H

class RBNode
{
public:
    RBNode();
    RBNode(int);
    int getData();
    char getColor();
    RBNode* getLeftC();
    RBNode* getRightC();
    RBNode* getParent();
    bool setData(int);
    bool setColor(char);
    bool setLeftC(RBNode*);
    bool setParent(RBNode*);
    bool setRightC(RBNode*);
    virtual ~RBNode();

protected:

private:
    int data;
    char color;
    RBNode* leftC;
    RBNode* rightC;
    RBNode* parent;
};

#endif // RBNODE_H

RBNode::RBNode()
{
    parent = nullptr;
    leftC = nullptr;
    rightC = nullptr;
    data = 0;
    color = red;
}
RBNode::RBNode(int a)
{
    data = a;
    color = red;
    parent = nullptr;
    leftC = nullptr;
    rightC = nullptr;
}
int RBNode::getData()
{
    return data;
}
char RBNode::getColor()
{
    return color;
}
RBNode* RBNode::getLeftC()
{
    return leftC;
}
RBNode* RBNode::getRightC()
{
    return rightC;
}
RBNode* RBNode::getParent()
{
    return parent;
}
bool RBNode::setData(int a)
{
    data = a;
    return true;
}
bool RBNode::setColor(char a)
{
    color = a;
    return true;
}
bool RBNode::setLeftC(RBNode*ptr)
{
    leftC = ptr;
    return true;
}
bool RBNode::setRightC(RBNode*ptr)
{
    rightC = ptr;
    return true;
}
bool RBNode::setParent(RBNode*ptr)
{
    parent= ptr;
    return true;
}
RBNode::~RBNode()
{
    //dtor
}
#ifndef RBTREE_H
#define RBTREE_H
class RBTree
{
public:
    RBTree();
    RBTree(int);
    RBNode*getRoot();
    RBNode*getLeaf();
    bool leftRotate(RBNode*,RBNode*);
    bool rightRotate(RBNode*,RBNode*);
    bool insertE(int);
    void print();
    void printRBT();
    void printPreOrder();
    void printInOrder();
    int succ(int);
    int pred(int);
    void printPostOrder();
    int maximum(RBNode*);
    int maximumRBT();
    int minimum(RBNode*);
    int minimumRBT();
    void printRBT(RBNode*);
    void printLevelOrder(int);
    RBNode* searchE(int);
    virtual ~RBTree();
protected:

private:
    RBNode* root;
    RBNode* leaf;
    void printPreOrder(RBNode*);
    void printInOrder(RBNode*);
    void printPostOrder(RBNode*);
    RBNode* searchElement(int,RBNode*);
    void print(RBNode*);
};

#endif // RBTREE_H

RBTree::RBTree()
{
    root = nullptr;
    leaf = new RBNode;
    leaf->setData(0);
    leaf->setLeftC(nullptr);
    leaf->setRightC(nullptr);
    leaf->setParent(nullptr);
    leaf->setColor(black);
}
void RBTree::print()
{
    if(root==nullptr)
    {
        return;
    }
    print(root);
    return ;
}
void RBTree::print(RBNode*ptr)
{
   RBNode* start = ptr;
   if(start==leaf)
   {
       return;
   }
   print(start->getLeftC());
   cout<<start->getData()<<" ";
   print(start->getRightC());
   return;
}
void RBTree::printPreOrder()
{
    if(root==nullptr)
    {
        return;
    }
    printPreOrder(root);
    return;
}
void RBTree::printPostOrder()
{
    if(root==nullptr)
    {
        return;
    }
    printPostOrder(root);
    return;
}
void RBTree::printInOrder()
{
    if(root==nullptr)
    {
        return;
    }
    printInOrder(root);
    return;
}
void RBTree::printPreOrder(RBNode*ptr)
{
    RBNode* start = ptr;
    if(start==leaf)
    {
        return;
    }
    cout<<start->getData();
    if(start->getData()!=maximumRBT())
    {
        cout<<" ";
    }
    printPreOrder(start->getLeftC());
    printPreOrder(start->getRightC());
    return ;
}

void RBTree::printPostOrder(RBNode*ptr)
{
    RBNode* start = ptr;
    if(start==leaf)
    {
        return;
    }
    printPostOrder(start->getLeftC());
    printPostOrder(start->getRightC());
    cout<<start->getData()<<" ";
    return ;
}
void RBTree::printInOrder(RBNode*ptr)
{
    RBNode* start = ptr;
    if(start==leaf)
    {
        return;
    }
    printInOrder(start->getLeftC());
    cout<<start->getData()<<" ";
    printInOrder(start->getRightC());
    return ;
}
int RBTree::maximum(RBNode*a)
{
    if(a==nullptr)
    {
        return -1;
    }
    RBNode* start = a;
    while(start!=leaf)
    {
        if(start->getRightC()==leaf)
        {
            return start->getData();
        }
        else
        {
            start = start->getRightC();
        }
    }
    return -1;
}
int RBTree::maximumRBT()
{
    return maximum(root);
}
int RBTree::minimum(RBNode*a)
{
     if(a==nullptr)
    {
        return -1;
    }
    RBNode* start = a;
    while(start!=leaf)
    {
        if(start->getLeftC()==leaf)
        {
            return start->getData();
        }
        else
        {
            start = start->getLeftC();
        }
    }
    return -1;
}
int RBTree::minimumRBT()
{
    return minimum(root);
}
void RBTree::printLevelOrder(int n)
{
    Queue A(n);
    if(root==nullptr)
    {
        return ;
    }
    A.add(root->getData());
    int y;
    while(!A.isEmpty())
    {
         y = A.deleteElement();
        RBNode* ptr = searchE(y);
        if(ptr->getLeftC()!=leaf)
        {
            A.add(ptr->getLeftC()->getData());
        }
        if(ptr->getRightC()!=leaf)
        {
            A.add(ptr->getRightC()->getData());
        }
        if(!A.isEmpty())
        {
          cout<<y<<" ";
        }
    }
            cout<<y;
    return;
}


int RBTree::succ(int a)
{
    int answer = -1;
    if(searchE(a)==nullptr)
    {
        return -1;
    }
    if(a==maximumRBT())
    {
        return -1;
    }
    RBNode* ptr = searchE(a);
    if(ptr->getRightC()!=leaf)
    {
        return minimum(ptr->getRightC());
    }
    else
    {
       RBNode* ptr2 = ptr->getParent();
       while(ptr2!=nullptr)
       {
           if(ptr2->getData()>ptr->getData())
           {
               return ptr2->getData();
           }
           else
           {
               ptr2 = ptr2->getParent();
           }
       }
    }
   return answer;
}
int RBTree::pred(int a)
{
   int answer = -1;
    if(searchE(a)==nullptr)
    {
        return -1;
    }
    if(a==minimumRBT())
    {
        return -1;
    }
    RBNode* ptr = searchE(a);
    if(ptr->getLeftC()!=leaf)
    {
        return maximum(ptr->getLeftC());
    }
    else
    {
       RBNode* ptr2 = ptr->getParent();
       while(ptr2!=nullptr)
       {
           if(ptr2->getData()<ptr->getData())
           {
               return ptr2->getData();
           }
           else
           {
               ptr2 = ptr2->getParent();
           }
       }
    }
   return answer;
}
bool RBTree::insertE(int a)
{
    if(searchE(a)!=nullptr)
    {
        return false;
    }
    RBNode*C=new RBNode(a);
    C->setLeftC(leaf);
    C->setRightC(leaf);
    C->setData(a);
    C->setParent(nullptr);
    if(root==nullptr)
    {
        root=C;
        C->setColor(black);
        return true;
    }
    RBNode* start = root;
    while(start!=nullptr)
    {
        if(start->getData()>a)
        {
            if(start->getLeftC()==leaf)
            {
                start->setLeftC(C);
                C->setParent(start);
                break;
            }
            else
            {
                start = start->getLeftC();
            }
        }
        else
        {
            if(start->getRightC()==leaf)
            {
                start->setRightC(C);
                C->setParent(start);
                break;
            }
            else
            {
                start=start->getRightC();
            }
        }
    }
    C=searchE(a);
    RBNode* P = C->getParent();
    RBNode* G = P->getParent();
    if(P->getColor()==black)
    {
        return true;
    }
    while(P->getColor()!=black)
    {
        //if P == Red then always GrandParent Will Exists ->Reason Root Always Black
        if(P->getColor()==black)
        {
            return true;
        }
        RBNode* U ;
        if(G!=nullptr)
        {
            if(G->getLeftC()==P)
            {
                U = G->getRightC();
            }
            else
            {
                U = G->getLeftC();
            }
        }
        if((P==G->getLeftC())&&(U->getColor()==red))
        {
          P->setColor(black);
          U->setColor(black);
          if(G==root)
          {
              root->setColor(black);
              return true;
          }
          else
          {
              G->setColor(red);
          }
          C=G;
          P=C->getParent();
          G=P->getParent();
          root->setColor(black);
          continue;
        }

        if((C==P->getLeftC())&&(P==G->getLeftC())&&(U->getColor()==black))
        {
            P->setColor(black);
            G->setColor(red);
            rightRotate(G,P);
            root->setColor(black);
            return true;
        }
        if((C==P->getRightC())&&(P==G->getLeftC())&&(U->getColor()==black))
        {
             if((C==P->getRightC())&&(P==G->getLeftC())&&(U->getColor()==black))
        {
            leftRotate(P,C);
           root->setColor(black);
           RBNode* t = C;
           C = P;
           P = t;
            continue;
        }
        }
       // if((C==P->getRightC())&&(P==G->getLeftC()))
       // {
       // }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if((P==G->getRightC())&&(U->getColor()==red))
        {
          P->setColor(black);
          U->setColor(black);
          if(G==root)
          {
              root->setColor(black);
              return true;
          }
          else
          {
              G->setColor(red);
          }
          C=G;
          P=C->getParent();
          G=P->getParent();
          root->setColor(black);
          continue;
        }
        if((C==P->getRightC())&&(P==G->getRightC())&&(U->getColor()==black))
        {
           G->setColor(red);
           P->setColor(black);
           leftRotate(G,P);
           root->setColor(black);
           return true;
        }
        if((C==P->getLeftC())&&(P==G->getRightC())&&(U->getColor()==black))
        {
           rightRotate(P,C);
           root->setColor(black);
           RBNode* t = C;
           C = P;
           P = t;
            continue;
        }
    }
    return true;
}
bool RBTree::rightRotate(RBNode*Parent,RBNode*Child)
{
    if(Parent==nullptr)
    {
        return false;
    }
    if(Child==nullptr)
    {
        return false;
    }
    RBNode*ptr1;
    RBNode*ptr2;
    if(Parent==root)
    {
        root=Child;
        Child->setParent(nullptr);
        ptr1 = Child->getRightC();
        Parent->setLeftC(ptr1);
        ptr1->setParent(Parent);
        Child->setRightC(Parent);
        Parent->setParent(Child);
        return true;
    }
    else
    {
        ptr2=Parent->getParent();
        Child->setParent(ptr2);
        ptr1=Child->getRightC();
        Parent->setLeftC(ptr1);
        ptr1->setParent(Parent);
        Child->setRightC(Parent);
        Parent->setParent(Child);
        if(ptr2->getData()>=Child->getData())
        {
            ptr2->setLeftC(Child);
        }
        else
        {
            ptr2->setRightC(Child);
        }
        return true;
    }
}
bool RBTree::leftRotate(RBNode*Parent,RBNode*Child)
{
    if(Parent==nullptr)
    {
        return false;
    }
    if(Child==nullptr)
    {
        return false;
    }
    RBNode* ptr1;
    RBNode* ptr2;
    if(Parent==root)
    {  //cout<<"ok"<<endl;
   // printRBT();
   // cout<<Child->getData()<<" "<<Parent->getData()<<" "<<endl;
        Parent->setParent(Child);
        ptr1=Child->getLeftC();
        Child->setLeftC(Parent);
        Parent->setRightC(ptr1);
        ptr1->setParent(Parent);
        Child->setParent(nullptr);
        root=Child;
        return true;
    }
    else
    {
        ptr2=Parent->getParent();
       // cout<<ptr2->getData();
        Parent->setParent(Child);
        ptr1=Child->getLeftC();
        Child->setLeftC(Parent);
        Parent->setRightC(ptr1);
        ptr1->setParent(Parent);
        Child->setParent(ptr2);
        if(ptr2->getData()>=Child->getData())
        {
            ptr2->setLeftC(Child);
        }
        else
        {
            ptr2->setRightC(Child);
        }
       // cout<<endl<<"left rotate"<<endl;
        return true;
    }
}
RBTree::RBTree(int a)
{
    root = new RBNode(a);
    root->setLeftC(leaf);
    root->setRightC(leaf);
}
RBNode* RBTree::getRoot()
{
    return root;
}
RBNode* RBTree::getLeaf()
{
    return leaf;
}
RBNode* RBTree::searchE(int a)
{
    RBNode* start = root;
    while(start!=nullptr)
    {
        if(start->getData()==a)
        {
            return start;
        }
        if(start->getData()>a)
        {
            if(start->getLeftC()!=leaf)
            {
                start= start->getLeftC();
                continue;
            }
            else
            {
                return nullptr;
            }
        }
        else
        {
            if(start->getRightC()!=leaf)
            {
                start = start->getRightC();
                continue;
            }
            else
            {
                return nullptr;
            }
        }
    }
    return nullptr;
}
void RBTree::printRBT()
{
    if(root==nullptr)
    {
        cout<<"fail";
        return ;
    }
    printRBT(root);
}
void RBTree::printRBT(RBNode* ptr)
{
    if(ptr==leaf)
    {
        return;
    }
    printRBT(ptr->getLeftC());
    cout<<ptr->getData()<<" "<<ptr->getColor()<<" "<<ptr->getLeftC()->getData()<<ptr->getLeftC()->getColor()<<" "<<ptr->getRightC()->getData()<<ptr->getRightC()->getColor()<<"  ";
    if(ptr->getParent()!=nullptr)
    {
        cout<<ptr->getParent()->getData()<<ptr->getParent()->getColor()<<endl;
    }
    else
    {
        cout<<endl;
    }
    printRBT(ptr->getRightC());
    return;
}
RBTree::~RBTree()
{
    //dtor
}
int main()
{
    int numberOfNodes;
    cin>>numberOfNodes;
    RBTree Answer;
    for (int i = 0; i < numberOfNodes ; i++)
    {
         int value;
        cin>>value;
        Answer.insertE(value);
    }
    Answer.printLevelOrder(numberOfNodes);
    cout<<endl;
    return 0;
}
