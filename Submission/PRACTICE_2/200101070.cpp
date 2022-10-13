#include <iostream>
using namespace std;

class BinaryNode
{
public:
    BinaryNode();
    bool setParent(BinaryNode*);
    bool setLeftC(BinaryNode*);
    bool setRightC(BinaryNode*);
    bool setData(int);
    BinaryNode* getParent();
    BinaryNode* getLeftC();
    BinaryNode* getRightC();
    int getData();
    virtual ~BinaryNode();

protected:

private:
    int data;
    BinaryNode*parent;
    BinaryNode*leftC;
    BinaryNode*rightC;
};
BinaryNode::BinaryNode()
{
    parent = nullptr;
    leftC = nullptr;
    rightC = nullptr;
}
bool BinaryNode::setParent(BinaryNode*ptr)
{
    parent = ptr ;
    return true;
}
bool BinaryNode::setLeftC(BinaryNode*ptr)
{
    leftC = ptr ;
    return true;
}
bool BinaryNode::setRightC(BinaryNode*ptr)
{
    rightC = ptr ;
    return true;
}
bool BinaryNode::setData(int a)
{
    data = a;;
    return true;
}
int BinaryNode::getData()
{
    return data;
}
BinaryNode* BinaryNode::getLeftC()
{
    return leftC;
}
BinaryNode* BinaryNode::getRightC()
{
    return rightC;
}
BinaryNode* BinaryNode::getParent()
{
    return parent;
}
BinaryNode::~BinaryNode()
{
    //dtor
}
class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(int);
    BinaryNode* getRoot();

    bool insertElement(BinaryNode*,int);

    bool searchElement(int);  //not done yet
    BinaryNode* searchElement(BinaryNode*,int);

    int maximumFullTree();
    int maximum(BinaryNode*);
    int minimumFullTree();
    int minimum(BinaryNode*);

    int succ(int);
    int pre(int);

    void print();                   // Just a Simplification of print(BinaryNode*)
    void print(BinaryNode*);        //Recursive approach
    void printReverseUsingPre();
    void printUsingSuccessor();
    void printPreOrder(BinaryNode*);
    void printInOrder(BinaryNode*);
    void printPostOrder(BinaryNode*);
    virtual ~BinaryTree();

protected:

private:
    BinaryNode* root;

};

BinaryTree::BinaryTree()
{
    root = nullptr;
}
BinaryTree::BinaryTree(int a)
{
    root = new BinaryNode;
    root->setData(a);
    root->setLeftC(nullptr);
    root->setRightC(nullptr);
    root->setParent(nullptr);
}
BinaryNode* BinaryTree::getRoot()
{
    return root;
}
bool BinaryTree::insertElement(BinaryNode*ptr,int a)
{
    if(ptr == nullptr)
    {
        ptr = new BinaryNode;
        ptr ->setData(a);
        return true;
    }
    else if(ptr->getData()>a)
    {
        if(ptr->getLeftC()==nullptr)
        {
            BinaryNode*t = new BinaryNode;
            t->setData(a);
            t->setParent(ptr);
            ptr->setLeftC(t);
            return true;
        }
        else
        {
            insertElement(ptr->getLeftC(),a);
        }
    }
    else
    {
        if(ptr->getRightC()==nullptr)
        {
            BinaryNode*t = new BinaryNode;
            t->setData(a);
            t->setParent(ptr);
            ptr->setRightC(t);
            return true;
        }
        else
        {
            insertElement(ptr->getRightC(),a);
        }
    }
    return false;
}
BinaryNode* BinaryTree::searchElement(BinaryNode*ptr,int a)
{
    BinaryNode* answer = nullptr;
    if(ptr->getData()==a)
    {
        answer = ptr;
    }
    else if(ptr->getData()>a)
    {
        if(ptr->getLeftC()== nullptr)
        {
            return nullptr;
        }
        else
        {
            answer =searchElement(ptr->getLeftC(),a);
        }
    }
    else
    {
        if(ptr->getRightC()== nullptr)
        {
            return nullptr;
        }
        else
        {
            answer =searchElement(ptr->getRightC(),a);
        }
    }
    return answer;
}
int BinaryTree::succ(int x)
{
    int answer = -1;
    if(x==maximumFullTree())
    {
        cout<<"ITS MAXIMUM -> ";
        return x;
    }
    if(searchElement(getRoot(),x)==nullptr)
    {
        cout<<"ITS NOT PRESENT SO PRINTING OUT MINIMUM OF WHOLE TREE -> ";
        return minimumFullTree();
    }
    else
    {
        if(searchElement(root,x)->getRightC()!=nullptr)
        {
            answer= minimum(searchElement(root,x)->getRightC());
            return minimum(searchElement(root,x)->getRightC());
        }
        else
        {
            BinaryNode* ptr = searchElement(root,x);
            BinaryNode* p1=searchElement(root,x)->getParent();// HAVING NO PARENT CASE IS HANDLED BY x==maximum // Root At maximum
            //  cout<<p1->getData()<<endl;
            while(p1!=nullptr)
            {
                int t = p1->getData();
                if(p1->getData()>ptr->getData())
                {
                    answer= p1->getData();
                    return p1->getData();
                }
                p1=p1->getParent();
            }
        }
    }
    return answer;
}
int BinaryTree::pre(int x)
{
    int answer = -1;
    if(x==minimumFullTree())
    {
        cout<<"ITS MINIMUM -> ";
        answer =x;
        return x;
    }
    if(searchElement(getRoot(),x)==nullptr)
    {
        cout<<"ITS NOT PRESENT SO PRINTING OUT MINIMUM OF WHOLE TREE -> ";
        return minimumFullTree();
    }
    else
    {
        if(searchElement(root,x)->getLeftC()!=nullptr)
        {
            answer= maximum(searchElement(root,x)->getLeftC());
            return maximum(searchElement(root,x)->getLeftC());
        }
        else
        {
            BinaryNode* ptr = searchElement(root,x);
            BinaryNode* p1=searchElement(root,x)->getParent();// HAVING NO PARENT CASE IS HANDLED BY x==maximum // Root At maximum
            //  cout<<p1->getData()<<endl;
            while(p1!=nullptr)
            {
                int t = p1->getData();
                if(p1->getData()<ptr->getData())
                {
                    answer= p1->getData();
                    return p1->getData();
                }
                p1=p1->getParent();
            }
        }
    }
    return answer;
}
void BinaryTree::print()
{
    print(root);
}
int BinaryTree::maximumFullTree()
{
    BinaryNode* start = root;
    while(start!= nullptr)
    {
        if(start->getRightC()==nullptr)
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
int BinaryTree::maximum(BinaryNode*ptr)
{
    BinaryNode* start = ptr;
    while(start!= nullptr)
    {
        if(start->getRightC()==nullptr)
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
int BinaryTree::minimumFullTree()
{
    BinaryNode* start = root;
    while(start!= nullptr)
    {
        if(start->getLeftC()==nullptr)
        {
            return start->getData();
        }
        else
        {
            start = start ->getLeftC();
        }
    }
    return -1;
}
int BinaryTree::minimum(BinaryNode*ptr)
{
    BinaryNode* start = ptr;
    while(start!= nullptr)
    {
        if(start->getLeftC()==nullptr)
        {
            return start->getData();
        }
        else
        {
            start = start ->getLeftC();
        }
    }
    return -1;
}
void BinaryTree::print(BinaryNode*ptr)
{
    if(ptr ==nullptr)
    {
        return;
    }
    print(ptr->getLeftC());
    cout<<ptr->getData()<<" ";
    print(ptr->getRightC());
    return;
}
void BinaryTree::printInOrder(BinaryNode*ptr)
{
    if(ptr ==nullptr)
    {
        return;
    }
    print(ptr->getLeftC());
    cout<<ptr->getData()<<" ";
    print(ptr->getRightC());
    cout<<endl;
    return;
}
void BinaryTree::printPreOrder(BinaryNode*ptr)
{
    if(ptr ==nullptr)
    {
        return;
    }
    cout<<ptr->getData()<<" ";
    print(ptr->getLeftC());
    print(ptr->getRightC());
    cout<<endl;
    return;
}
void BinaryTree::printPostOrder(BinaryNode*ptr)
{
    if(ptr ==nullptr)
    {
        return;
    }
    print(ptr->getLeftC());
    print(ptr->getRightC());
    cout<<ptr->getData()<<" ";
    cout<<endl;
    return;
}
void BinaryTree::printUsingSuccessor()
{
    BinaryNode*start= searchElement(root,minimumFullTree());
    while(start!=searchElement(root,maximumFullTree()))
    {
        cout<<start->getData()<<" ";
        start = searchElement(root,succ(start->getData()));
    }
    cout<<maximumFullTree();
    cout<<endl;
    return;
}
void BinaryTree::printReverseUsingPre()
{
    BinaryNode*start= searchElement(root,maximumFullTree());
    while(start!=searchElement(root,minimumFullTree()))
    {
        cout<<start->getData()<<" ";
        start = searchElement(root,pre(start->getData()));
    }
    cout<<minimumFullTree();
    cout<<endl;
    return;
}
BinaryTree::~BinaryTree()
{
    //dtor
}
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    /*BinaryTree* A = new BinaryTree(25);
    A->print(A->getRoot());
    cout<<endl;
    A->insertElement(A->getRoot(),1);
    A->insertElement(A->getRoot(),10);
    A->insertElement(A->getRoot(),100);
    A->insertElement(A->getRoot(),1000);
    A->insertElement(A->getRoot(),3000);
    A->insertElement(A->getRoot(),250);
    A->insertElement(A->getRoot(),2);
    cout<<A->minimumFullTree()<<" "<<A->maximumFullTree()<<endl;
    // A->print(A->getRoot());
    A->print();
    cout<<endl;
     cout<<"DO U WANT TO SEARCH ANY ELEMENT "<<endl;
     cout<<"PRESS Y TO SEARCH AND N FOR NOT SEARCHING "<<endl;
     char c; cin>>c;
     switch (c)
     {
     case 'Y': cout<<"ENTER THE ELEMENT U WANT TO SEARCH"<<endl;
               int i ;
               cin>>i;
               if(A->searchElement(A->getRoot(),i))
               {
                   cout<<"FOUNDED"<<endl;
               }
               else
               {
                   cout<<"NOT FOUNDED"<<endl;
               }
               break;
     case 'N':
               break;
     default:
             break;
     }
    cout<< A->succ(9)<<endl;
    cout<< A->succ(3000)<<endl;
    cout<< A->succ(2)<<endl;
    cout<< A->succ(25)<<endl;
    cout<< A->succ(100)<<endl;
    cout<< A->succ(1000)<<endl;
    cout<< A->succ(250)<<endl;
    cout<< A->succ(1)<<endl;
    cout<< A->succ(10)<<endl;
    cout<< A->succ(5)<<endl;
    cout<< A->pre(9)<<endl;
    cout<< A->pre(3000)<<endl;
    cout<< A->pre(2)<<endl;
    cout<< A->pre(25)<<endl;
    cout<< A->pre(100)<<endl;
    cout<< A->pre(1000)<<endl;
    cout<< A->pre(250)<<endl;
    cout<< A->pre(1)<<endl;
    cout<< A->pre(10)<<endl;
    cout<< A->pre(5)<<endl;
    A->printUsingSuccessor();
    A->printReverseUsingPre();
    A->printPreOrder(A->getRoot());
    A->printInOrder(A->getRoot());
    A->printPostOrder(A->getRoot());
    */
    cout<<"ENTER THE ROOT OF BINARY TREE"<<endl;
    int a;
    cin>>a;
    BinaryTree A(a);
    int i = 1;
    while(i!=0)
    {
        cout<<"U CAN DO THE FOLLOWING OPERATIONS"<<endl;
        cout<<"1) INSERT NEW ELEMENT"<<endl;
        cout<<"2) SEARCH ANY ELEMENT"<<endl;
        cout<<"3) PRINT"<<endl;
        cout<<"4) PRINT IN ORDER"<<endl;
        cout<<"5) PRINT POST ORDER"<<endl;
        cout<<"6) PRINT PRE ORDER"<<endl;
        cout<<"7) PRINT USING SUCCESSOR"<<endl;
        cout<<"8) PRINT REVERSE USING PREDECESSOR"<<endl;
        cout<<"9) FIND PREDECESSOR"<<endl;
        cout<<"10) FIND SUCCESSOR"<<endl;
        cout<<"11) EXIT"<<endl;
        cin>>i;
        switch (i)
        {
        case 1 : cout<<"ENTER THE ELEMENT"<<endl;
                  int b;
                  cin>>b;
                  A.insertElement(A.getRoot(),b);
               break;
        case 2 :  cout<<"ENTER THE ELEMENT"<<endl;
                  cin>>b;
                  A.searchElement(A.getRoot(),b);
               break;
        case 3 :  A.print();
               break;
        case 4 :  A.printInOrder(A.getRoot());
               break;
        case 5 :  A.printPostOrder(A.getRoot());
               break;
        case 6 :  A.printPreOrder(A.getRoot());
               break;
        case 7 : A.printUsingSuccessor();
               break;
        case 8 : A.printReverseUsingPre();
               break;
        case 9 :  cout<<"ENTER THE ELEMENT"<<endl;
                  cin>>b;
                  cout<<A.pre(b);
                  cout<<endl;
               break;
        case 10 :  cout<<"ENTER THE ELEMENT"<<endl;
            
                  cin>>b;
                  cout<<A.succ(b);
                  cout<<endl;
               break;
        case 11 : return 0;
               break;

        default:
                break;
        }
   cout<<endl;

    }
    return 0;
}

