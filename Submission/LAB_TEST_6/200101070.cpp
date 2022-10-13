#include<iostream>
using namespace std;
int* RadixCountSort(int* A,int a, int n)
{
    int D[n];
    int k = 1;
    for(int i = 1; i<=a;i++)
    {
        k =k*10;
    }
    for(int i = 0; i<n ;i++)
    {
        D[i] = A[i]%k;
        int p = k/10;
        D[i] = D[i]/p;
    }
    int B[10];
    int*ans = new int[n];
    for(int i = 0; i<10; i++)
    {
        B[i] = 0;
    }
    for(int i = 0; i<n ; i++)
    {
        B[D[i]] = B[D[i]] +1;
    }
    for(int i = 1; i<10; i++)
    {
        B[i] = B[i] +B[i-1];
    }
    for(int i = n-1; i>=0; i--)
    {
        B[D[i]]--;
        ans[B[D[i]]] = A[i];
    }
    return ans;
}
int* RadixSort(int*A , int n)
{
    /*
    */
    if(n<1)
    {
        return nullptr;
    }
    if(A==nullptr)
    {
        return nullptr;
    }
    int m =A[0];
    for(int i = 0; i<n;i++)
    {
        if(A[i]>m)
        {
            m = A[i];
        }
    }
   // cout<<endl<<m;
    int ntime = 0;
    while(m>0)
    {
        m = m/10;
        ntime++;
    }
    //cout<<" "<<ntime<<endl;
    for(int i =1; i<=ntime;i++)
    {
      A = RadixCountSort(A,i,n);
    // For showing Procedure
    //  cout<<endl<<i<<endl;
    //  for(int j = 0; j<n;j++)
    //  {
    //     cout<<A[j]<<" ";
    //  }
    }
    return A;
}

int* countSort(int *A, int n)
{
    if(A==nullptr)
    {
        return nullptr;
    }
    if(n<1)
    {
        return nullptr;
    }
    int k = A[0];
  for(int i = 0; i<n;i++)
  {
   if(A[i]>k)
   {
       k = A[i];
   }
  }
  //cout<<k<<endl;
  int *B = new int[k+1];
  for(int i = 0; i<=k;i++)
  {
      B[i]=0;
  }
  for(int i = 0; i<n ; i++)
  {
      B[A[i]] = B[A[i]]+1;
  }
  for(int i = 1; i<=k ;i++ )
  {
    B[i] = B[i]+B[i-1];
  }
  int *C = new int[n];
  for(int i = n-1; i>=0;i--)
  {
    B[A[i]] = B[A[i]] -1;
    C[B[A[i]]] = A[i];
  }
  delete B;
  return C;
}

int DPartition(int*A,int i , int r)
{
    int k = i-1;
    for(int z = i; z<= r-1;z++)
    {
        if(A[z]<=A[r])
        {
            swap(A[k+1],A[z]);
            k++;
        }
    }
    swap(A[r],A[k+1]);
    return k+1;
}
void DQuickSort(int *A,int p,int n)
{
    if(p>=n)
    {
        return;
    }
    else
    {   int q;
        q = DPartition(A,p,n);
        DQuickSort(A,p,q-1);
        DQuickSort(A,q+1,n);
    }
   return;
}

void ShellSort(int *A,int n,int y)
{
    for(int k = 0 ; k< y ; k++)
    {
        for(int i = k+y ;i<n;i++)
        {
            int o = A[i];
            for(int j = i-y;j>=0;j=j-y)
            {
                if(A[j]>A[i])
                {
                    A[i]=A[j];
                    A[j]=o;
                    i = j;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return;
}

void SelectionSort(int*A,int n)
{
    for(int i = 0 ; i<n ; i++)
    {
        int minimum = INT_MAX;
        int minIndex = INT_MAX;
        for(int j = i ; j< n ; j++)
        {
            if(A[j]<minimum)
            {
                minimum=A[j];
                minIndex=j;
            }
        }
        A[minIndex] = A[i];
        A[i] = minimum;
    }
    return ;
}

void InsertionSort(int*A,int n)
{
 /*   for(int i = 0 ; i<n; i++)
    {
        cout<<A[i]<<endl;
    }
   */
    for(int i = 1; i<n ; i++)
    {
        int o = A[i];
        for(int j = i-1; j>=0; j--)
        {
            if(A[j]>A[i])
            {
                A[i]= A[j];
                A[j] = o;
                cout<<o<<"->";
                for(int k = 0 ; k<n; k++)
                {
                    cout<<A[k]<<" ";
                }
                i = j;
                cout<<endl;
            }
            else
            {
                break;
            }
        }
    }
    return;
}


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

#ifndef GRAPH_H
#define GRAPH_H

class graph
{
    public:
        graph();
        graph(int);
        bool addE(int);
        int numberNodes();
        bool graphRepetition(int n);
        graphnode* getLast();
        graphnode* getRoot();
        virtual ~graph();
    protected:

    private:
        int noOfNodes;
        graphnode* root;
        graphnode* last;
};

#endif // GRAPH_H
bool graph::graphRepetition(int n)
{
    int arr[noOfNodes];
    graphnode* ptr = root;
    int j = 0;
    while (ptr!=nullptr)
    {
        arr[j] = ptr->getData();
        ptr = ptr->getChild();
    }
    int count[n];
    for (int i = 0; i < n; i++)
    {
        count[i]=0;
    }
    for (int i = 0; i <noOfNodes; i++)
    {
        count[arr[i]]= count[arr[i]]+1;
    }
    for (int i = 0; i < n; i++)
    {
      if(count[i]>1)
      {
          return false;
      }
    }
    return true;
}
graph::graph()
{   noOfNodes=0;
    root = nullptr;
    last = nullptr;
}
graph::graph(int a)
{
   noOfNodes=0;
   graphnode* ptr = new graphnode;
   ptr->setData(a);
   ptr->setChild(nullptr);
   root = ptr;
   last = ptr;
}
int graph::numberNodes()
{
    return noOfNodes;
}
bool graph::addE(int a)
{
    noOfNodes++;
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


int main()
{  int n;
    int e;
    cin>>n>>e;
    graph* G[n+1];
    for(int i = 1; i<=n;i++)
    {
        G[i] = new graph();
        G[i]->addE(i);
    }
   for(int i = 1; i<=e;i++)
    {
        int a, b;
        cin>>a>>b;
        for (int j = 1; j <=n; j++)
        {      
        if(G[j]->getLast()->getData()==a)
        {
            G[j]->addE(b);
        }
        else if(G[j]->getLast()->getData()==b)
        {
            G[j]->addE(a);
        }
        }   
    }
    int o = 1;
    //  IF PARENT SAME OF TWO
    for (int i = 1; i <=n; i++)
    {
        int B[n+1];
        for (int w = 0; w <=n; w++)
        {
            B[w]=0;
        }
        graphnode* ptr = G[i]->getRoot();
  
      while (ptr!=nullptr)
      {
          B[ptr->getData()]= B[ptr->getData()]+1;
          ptr= ptr->getChild();
      }
      for (int j = 0; j <=n; j++)
      {
          if(B[j]>1)
          {
              cout<<"N"<<endl<<0<<endl;
              return 0;
          }
      }
      
    }
    
    int maximum = 1;
    for (int i = 1; i <=n; i++)
    {
        if(G[i]->numberNodes()>maximum)
        {
            maximum = G[i]->numberNodes();
        }
    }
    int r = maximum;
    graph* ptr2=nullptr;
    for (int i = 1; i <=n; i++)
    {
        if(G[i]->numberNodes()==1)
        {
              cout<<"N"<<endl<<0<<endl;
              return 0;
        }
    }
    for (int i = 1; i <=n; i++)
    {
        if(G[i]->numberNodes()==r)
        {
              ptr2 = G[i];
        }
    }

    for (int i = 1; i <= n; i++)
    {
       int na = 0;
       int AB[maximum];
       graphnode* ptr3 = ptr2->getRoot();
       while(ptr3!=nullptr)
       {
           AB[na] = ptr3->getData();
           ptr3 = ptr3->getChild();
           na++;
       }
       int hg = G[i]->numberNodes();
       int D[hg];
       int op = 0;
       graphnode* ptr4 = G[i]->getRoot();
       while (ptr4!=nullptr)
       {
           D[op] = ptr4->getData();
           op++;
       }
       for (int i = 0; i < hg; i++)
       {
           
       }
       
    }
    
    cout<<"Y"<<endl<<maximum-1<<endl;
    return 0;

}
    // for (int i = 1; i <=n; i++)
    // {
    //     graphnode* ptr = G[i]->getRoot();
    //     while (ptr!=nullptr)
    //     {
    //         cout<<ptr->getData()<<" ";
    //         ptr = ptr->getChild();
    //     }
    //     cout<<endl<<G[i]->numberNodes()<<endl;
    // }