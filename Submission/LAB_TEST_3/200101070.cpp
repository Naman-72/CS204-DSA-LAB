#include <iostream>
using namespace std;

class BinaryNode
{
public:
    BinaryNode();
    bool setParent(BinaryNode *);
    bool setLeftC(BinaryNode *);
    bool setRightC(BinaryNode *);
    bool setData(int);
    BinaryNode *getParent();
    BinaryNode *getLeftC();
    BinaryNode *getRightC();
    int getData();
    virtual ~BinaryNode();

protected:
private:
    int data;
    BinaryNode *parent;
    BinaryNode *leftC;
    BinaryNode *rightC;
};
BinaryNode::BinaryNode()
{
    parent = nullptr;
    leftC = nullptr;
    rightC = nullptr;
}
bool BinaryNode::setParent(BinaryNode *ptr)
{
    parent = ptr;
    return true;
}
bool BinaryNode::setLeftC(BinaryNode *ptr)
{
    leftC = ptr;
    return true;
}
bool BinaryNode::setRightC(BinaryNode *ptr)
{
    rightC = ptr;
    return true;
}
bool BinaryNode::setData(int a)
{
    data = a;
    ;
    return true;
}
int BinaryNode::getData()
{
    return data;
}
BinaryNode *BinaryNode::getLeftC()
{
    return leftC;
}
BinaryNode *BinaryNode::getRightC()
{
    return rightC;
}
BinaryNode *BinaryNode::getParent()
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
    BinaryNode *getRoot();

    bool insertElement(int);

    int totalNodes();

    BinaryNode *searchElement(int);

    int maximumFullTree();
    int maximum(BinaryNode *);
    int minimumFullTree();
    int minimum(BinaryNode *);

    int succ(int);
    int pre(int);

    bool deleteE(int);

    void printReverseUsingPre();
    void printUsingSuccessor();

    void print(); //same as Inorder transversal       // Just a Simplification of print(BinaryNode*)
    void printPreOrder();
    void printInOrder();
    void printPostOrder();
    void printPath(int a);
    void printPathReverse(int a);

    int height();
    
    int getHeight(); // FAILING IN CASE OF REPETITION
    int getHeight(BinaryNode *);
    //int height();
    int lowestA(int, int);
    int totalNoOfNodes(int);

    virtual ~BinaryTree();

protected:
private:
    BinaryNode *root;
    bool insertElement(BinaryNode *, int);
    BinaryNode *searchElement(BinaryNode *, int);
    void print(BinaryNode *); //Recursive approach
    int totalNodes(BinaryNode *);
    void printPreOrder(BinaryNode *);
    int totalNoOfNodes(BinaryNode*);
    void printInOrder(BinaryNode *);
    void printPostOrder(BinaryNode *);
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
BinaryNode *BinaryTree::getRoot()
{
    return root;
}
void BinaryTree::printPath(int a)
{
    if (searchElement(a) == nullptr)
    {
        cout << "ELEMENT DOES NOT EXIST" << endl;
        return;
    }
    BinaryNode *ptr = searchElement(a);
    int k = 1;
    while (ptr->getParent() != nullptr)
    {
        ptr = ptr->getParent();
        k++;
    }
    int A[k];
    ptr = searchElement(a);
    A[0] = ptr->getData();
    int j = 1;
    while (ptr->getParent() != nullptr)
    {
        ptr = ptr->getParent();
        A[j] = ptr->getData();
        j++;
    }
    for (int i = 0; i < k; i++)
    {
        cout << A[k - 1 - i] << " ";
    }
    cout << endl;
    return;
}
void BinaryTree::printPathReverse(int a)
{
    if (searchElement(a) == nullptr)
    {
        cout << "ELEMENT DOES NOT EXIST" << endl;
        return;
    }
    BinaryNode *ptr = searchElement(a);
    int k = 1;
    while (ptr->getParent() != nullptr)
    {
        ptr = ptr->getParent();
        k++;
    }
    int A[k];
    ptr = searchElement(a);
    A[0] = ptr->getData();
    int j = 1;
    while (ptr->getParent() != nullptr)
    {
        ptr = ptr->getParent();
        A[j] = ptr->getData();
        j++;
    }
    for (int i = 0; i < k; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return;
}
int BinaryTree::getHeight()
{
    BinaryNode *ptr = searchElement(minimumFullTree());
    int noOfNodes = 1;
    while (ptr != searchElement(maximumFullTree()))
    {
        ptr = searchElement(succ(ptr->getData()));
        noOfNodes++;
    }
    int H[noOfNodes];
    for (int i = 0; i < noOfNodes; i++)
    {
        int k = 1;
        while (ptr->getParent() != nullptr)
        {
            ptr = ptr->getParent();
            k++;
        };
        H[i] = k;
    }
    int maxA = H[0];
    for (int i = 1; i < noOfNodes; i++)
    {
        if (H[i] > maxA)
        {
            maxA = H[i];
        }
    }
    return maxA;
}
bool BinaryTree::insertElement(int a)
{
    return insertElement(root, a);
}
bool BinaryTree::insertElement(BinaryNode *ptr, int a)
{
    if (ptr == nullptr)
    {
        ptr = new BinaryNode;
        ptr->setData(a);
        root = ptr;
        return true;
    }
    else if (ptr->getData() > a)
    {
        if (ptr->getLeftC() == nullptr)
        {
            BinaryNode *t = new BinaryNode;
            t->setData(a);
            t->setParent(ptr);
            ptr->setLeftC(t);
            return true;
        }
        else
        {
            insertElement(ptr->getLeftC(), a);
        }
    }
    else
    {
        if (ptr->getRightC() == nullptr)
        {
            BinaryNode *t = new BinaryNode;
            t->setData(a);
            t->setParent(ptr);
            ptr->setRightC(t);
            return true;
        }
        else
        {
            insertElement(ptr->getRightC(), a);
        }
    }
    return false;
}
BinaryNode *BinaryTree::searchElement(BinaryNode *ptr, int a)
{
    BinaryNode *answer = nullptr;
    if (ptr->getData() == a)
    {
        answer = ptr;
    }
    else if (ptr->getData() > a)
    {
        if (ptr->getLeftC() == nullptr)
        {
            return nullptr;
        }
        else
        {
            answer = searchElement(ptr->getLeftC(), a);
        }
    }
    else
    {
        if (ptr->getRightC() == nullptr)
        {
            return nullptr;
        }
        else
        {
            answer = searchElement(ptr->getRightC(), a);
        }
    }
    return answer;
}
BinaryNode *BinaryTree::searchElement(int a)
{
    return searchElement(root, a);
}
int BinaryTree::succ(int x)
{
    int answer = -1;
    if (x == maximumFullTree())
    {
        //cout<<"ITS MAXIMUM -> ";
        return x;
    }
    if (searchElement(getRoot(), x) == nullptr)
    {
        return minimumFullTree(); // WE CAN IDENTIFY EASILY AS SUCC CAN'T BE MINIMUM
    }
    else
    {
        if (searchElement(root, x)->getRightC() != nullptr)
        {
            answer = minimum(searchElement(root, x)->getRightC());
            return minimum(searchElement(root, x)->getRightC());
        }
        else
        {
            BinaryNode *ptr = searchElement(root, x);
            BinaryNode *p1 = searchElement(root, x)->getParent(); // HAVING NO PARENT CASE IS HANDLED BY x==maximum // Root At maximum
            //  cout<<p1->getData()<<endl;
            while (p1 != nullptr)
            {
                if (p1->getData() > ptr->getData())
                {
                    answer = p1->getData();
                    return p1->getData();
                }
                p1 = p1->getParent();
            }
        }
    }
    return answer;
}
bool BinaryTree::deleteE(int a)
{
    if (searchElement(root, a) == nullptr)
    {
        return false;
    }
    //METHOD 1 : BOOK METHOD
    if ((searchElement(root, a)->getLeftC() == nullptr) && (searchElement(root, a)->getRightC() == nullptr))
    {
        BinaryNode *temp = searchElement(root, a);
        if (temp->getParent() != nullptr)
        {
            if (temp->getParent()->getData() > a)
            {
                temp->getParent()->setLeftC(nullptr);
                temp->setParent(nullptr);
                return true;
            }
            else
            {
                temp->getParent()->setRightC(nullptr);
                temp->setParent(nullptr);
                return true;
            }
        }
        else
        {
            root = nullptr;
        }
    }
    else if ((searchElement(root, a)->getLeftC() == nullptr) && (searchElement(root, a)->getRightC() != nullptr))
    {
        BinaryNode *p = searchElement(root, a)->getParent();
        {
            BinaryNode *q = searchElement(root, a);
            if (p != nullptr)
            {
                if (p->getData() <= q->getRightC()->getData())
                {
                    p->setRightC(searchElement(root, a)->getRightC());
                    q->setParent(nullptr);
                    p->getRightC()->setParent(p);
                    q->setRightC(nullptr);
                }
                else
                {
                    p->setLeftC(searchElement(root, a)->getRightC());
                    q->setParent(nullptr);
                    p->getLeftC()->setParent(p);
                    q->setRightC(nullptr);
                }
            }
            else
            {
                root = searchElement(root, a)->getRightC();
                root->setParent(nullptr);
                q->setRightC(nullptr);
            }
            return true;
        }
    }
    else if ((searchElement(root, a)->getLeftC() != nullptr) && (searchElement(root, a)->getRightC() == nullptr))
    {
        BinaryNode *p = searchElement(root, a)->getParent();
        {
            BinaryNode *q = searchElement(root, a);
            if (p != nullptr)
            {
                if (p->getData() >= q->getLeftC()->getData())
                {
                    p->setLeftC(searchElement(root, a)->getLeftC());
                    q->setParent(nullptr);
                    p->getLeftC()->setParent(p);
                    q->setLeftC(nullptr);
                }
                else
                {
                    p->setRightC(searchElement(root, a)->getLeftC());
                    q->setParent(nullptr);
                    p->getRightC()->setParent(p);
                    q->setLeftC(nullptr);
                }
            }
            else
            {
                root = searchElement(root, a)->getLeftC();
                root->setParent(nullptr);
                q->setLeftC(nullptr);
            }
            return true;
        }
        return true;
    }
    else if ((searchElement(root, a)->getLeftC() != nullptr) && (searchElement(root, a)->getRightC() != nullptr))
    {

        int y = succ(a);
        deleteE(succ(a));
        searchElement(root, a)->setData(y);
        return true;
    }
    return false;
}
int BinaryTree::totalNodes(BinaryNode *ptr)
{
    int total = 0;
    if (ptr == nullptr)
    {
        return total;
    }
    total = total + totalNodes(ptr->getLeftC());
    total = total + 1;
    total = total + totalNodes(ptr->getRightC());
    return total;
}
int BinaryTree::totalNodes()
{
    return totalNodes(root);
}
int BinaryTree::pre(int x)
{
    int answer = -1;
    if (x == minimumFullTree())
    {
        cout << "ITS MINIMUM -> ";
        answer = x;
        return x;
    }
    if (searchElement(getRoot(), x) == nullptr)
    {
        cout << "ITS NOT PRESENT SO PRINTING OUT MINIMUM OF WHOLE TREE -> ";
        return minimumFullTree();
    }
    else
    {
        if (searchElement(root, x)->getLeftC() != nullptr)
        {
            answer = maximum(searchElement(root, x)->getLeftC());
            return maximum(searchElement(root, x)->getLeftC());
        }
        else
        {
            BinaryNode *ptr = searchElement(root, x);
            BinaryNode *p1 = searchElement(root, x)->getParent(); // HAVING NO PARENT CASE IS HANDLED BY x==maximum // Root At maximum
            //  cout<<p1->getData()<<endl;
            while (p1 != nullptr)
            {
                if (p1->getData() < ptr->getData())
                {
                    answer = p1->getData();
                    return p1->getData();
                }
                p1 = p1->getParent();
            }
        }
    }
    return answer;
}
int BinaryTree::getHeight(BinaryNode *ptr)
{
    if (ptr == nullptr)
    {
        return 0;
    }
    int r = getHeight(ptr->getRightC()) ;
    int l = getHeight(ptr->getLeftC()) ;
    if((ptr->getLeftC()==nullptr)&&(ptr->getRightC())==nullptr)
    {
      return 1;
    }
    if(r>l)
    {
        return r+1;
    }
    else
    {
        return l+1;
    }
}
void BinaryTree::print()
{
    print(root);
    return;
}
int BinaryTree::maximumFullTree()
{
    BinaryNode *start = root;
    while (start != nullptr)
    {
        if (start->getRightC() == nullptr)
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
int BinaryTree::maximum(BinaryNode *ptr)
{
    BinaryNode *start = ptr;
    while (start != nullptr)
    {
        if (start->getRightC() == nullptr)
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
    BinaryNode *start = root;
    while (start != nullptr)
    {
        if (start->getLeftC() == nullptr)
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
int BinaryTree::minimum(BinaryNode *ptr)
{
    BinaryNode *start = ptr;
    while (start != nullptr)
    {
        if (start->getLeftC() == nullptr)
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
void BinaryTree::print(BinaryNode *ptr)
{
    if (ptr == nullptr)
    {
        return;
    }
    print(ptr->getLeftC());
    cout << ptr->getData() << " ";
    print(ptr->getRightC());
    return;
}
void BinaryTree::printInOrder(BinaryNode *ptr)
{
    if (ptr == nullptr)
    {
        return;
    }
    print(ptr->getLeftC());
    cout << ptr->getData() << " ";
    print(ptr->getRightC());
    cout << endl;
    return;
}
void BinaryTree::printPreOrder(BinaryNode *ptr)
{
    if (ptr == nullptr)
    {
        return;
    }
    cout << ptr->getData() << " ";
    print(ptr->getLeftC());
    print(ptr->getRightC());
    cout << endl;
    return;
}
void BinaryTree::printPostOrder(BinaryNode *ptr)
{
    if (ptr == nullptr)
    {
        return;
    }
    print(ptr->getLeftC());
    print(ptr->getRightC());
    cout << ptr->getData() << " ";
    cout << endl;
    return;
}
void BinaryTree::printInOrder()
{
    printInOrder(root);
    return;
}
void BinaryTree::printPreOrder()
{
    printPreOrder(root);
    return;
}
void BinaryTree::printPostOrder()
{
    printPostOrder(root);
    return;
}
void BinaryTree::printUsingSuccessor()
{
    BinaryNode *start = searchElement(root, minimumFullTree());
    while (start != searchElement(root, maximumFullTree()))
    {
        cout << start->getData() << " ";
        start = searchElement(root, succ(start->getData()));
    }
    cout << maximumFullTree();
    cout << endl;
    return;
}
void BinaryTree::printReverseUsingPre()
{
    BinaryNode *start = searchElement(root, maximumFullTree());
    while (start != searchElement(root, minimumFullTree()))
    {
        cout << start->getData() << " ";
        start = searchElement(root, pre(start->getData()));
    }
    cout << minimumFullTree();
    cout << endl;
    return;
}
int BinaryTree::lowestA(int a, int b)
{
    BinaryNode *p = searchElement(a);
    BinaryNode *q = searchElement(b);
    int m = 1;
    while (p->getParent() != nullptr)
    {
        m++;
        p = p->getParent();
    }
    int A[m];
    A[0] = a;
    int i = 1;
    p = searchElement(a);
    while (p->getParent() != nullptr)
    {
        p = p->getParent();
        A[i] = p->getData();
        i++;
    }
    int n = 1;
    while (q->getParent() != nullptr)
    {
        n++;
        q = q->getParent();
    }
    int B[n];
    B[0] = b;
    int j = 1;
    q = searchElement(b);
    while (q->getParent() != nullptr)
    {
        q = q->getParent();
        B[j] = q->getData();
        j++;
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i] == B[j])
            {
                return A[i];
            }
        }
    }
    return root->getData();
}
int BinaryTree::totalNoOfNodes(int a)
{
    return totalNoOfNodes(searchElement(a));
}
int BinaryTree::totalNoOfNodes(BinaryNode *ptr)
{
    int total = 0;
    if (ptr == nullptr)
    {
        return 0;
    }
    total = totalNoOfNodes(ptr->getLeftC()) + total;
    total = total + 1;
    total = totalNoOfNodes(ptr->getRightC()) + total;
    return total;
}
BinaryTree::~BinaryTree()
{
    //dtor
}

int main()
{
    BinaryTree A;
    int n,a,b,c;
    cin>>n;
    int o;
    for (int i = 0; i < n; i++)
    {
        cin>>o;
        A.insertElement(o);
    }
    cin>>a>>b;
    cin>>c;
    cout<<A.getHeight(A.getRoot())<<" "<<A.lowestA(a,b)<<" "<<A.totalNoOfNodes(c)<<endl;
}