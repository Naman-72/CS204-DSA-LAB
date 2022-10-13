#include <iostream>
using namespace std;

class Array
{
public:
    Array();
    Array(int);
    Array(int,int);
    void mergeSortIterative(int n);
    void mergeSort(int left,int right);
    void mergeBoth(int left,int right,int middle);
    void selectionSort();
    void insertionSort();
    void selectionSortUnstable();
    void printArray();
    bool binarySearch2(int);
    bool binarySearch(int left, int right,int data);
    bool setElement(int,int);
    int getElement(int index);
    virtual ~Array();
protected:

private:
    int *elements;
    int capacity;
};
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
void Array::printArray()
{
    for(int i = 0; i<capacity; i++)
    {
        cout<<getElement(i)<<"  ";
    }
    cout<<endl;
    return;
}
void Array::selectionSort()
{
    for(int i = 0; i<capacity; i++)
    {
        int k =i;
        int minimum = getElement(i);
        for(int j =i; j<capacity; j++)
        {
            if(minimum>getElement(j))
            {
                minimum = getElement(j);
                k = j;
            }
        }
        for(int j = 0; j<k-i; j++)
        {
            setElement(k-j,getElement(k-j-1));
        }
        setElement(i,minimum);
    }
    return;
}
void Array::selectionSortUnstable()
{
    for(int i = 0; i<capacity; i++)
    {
        int k =i;
        int minimum = getElement(i);
        for(int j =i; j<capacity; j++)
        {
            if(minimum>getElement(j))
            {
                minimum = getElement(j);
                k = j;
            }
        }
        setElement(k,getElement(i));
        setElement(i,minimum);
    }
    return;
}
bool Array::binarySearch2(int data)  // USING LOOP
{
    int left = 0;
    int right = capacity-1;
    int middle =(left+right)/2;
    while(1)
    {
        if(getElement(middle)==data)
        {
            cout<<data<<" Present"<<endl;
            return true;
            break;
        }
        else if(middle >data)
        {
            right= middle -1;
            middle = (left+right)/2;
            binarySearch2(data);
        }
        else if(middle <data)
        {
            left= middle+1;
            middle = (left+right)/2;
            binarySearch2(data);
        }

    }
}
void Array::insertionSort()
{
    for(int i = 1; i<capacity; i++)
    {
        int k = getElement(i);
        for(int j =1; j<=i; j++)
        {
            if(k<getElement(i-j))
            {
                setElement(i-j+1,getElement(i-j));
                setElement(i-j,k);
            }
        }
    }
    return;
}
void Array::mergeSort(int left,int right)
{
    if(left>=right)
    {
        return;
    }
    int  middle = (left +right)/2;
    mergeSort(left,middle);
    mergeSort(middle+1,right);
    mergeBoth(left,right,middle);
}
void Array::mergeBoth(int left,int right, int middle)
{
    int X[right-left+1];
    int leftC= left;
    int rightC = middle +1;
    for(int i = 0 ; i<right - left +1; i++)
    {
        if(leftC==middle+1)
        {
            X[i]= getElement(rightC);
            rightC++;
        }
        else if(rightC==right+1)
        {
            X[i] = getElement(leftC);
            leftC++;
        }
        else if(getElement(leftC)<getElement(rightC))
        {
            X[i] = getElement(leftC);
            leftC++;
        }
        else
        {
            X[i]= getElement(rightC);
            rightC++;
        }
    }
    for(int i = left; i<=right; i++)
    {
        setElement(i,X[i-left]);
    }
    return;
}
bool Array::binarySearch(int left, int right,int data)
{
    int middle = (left+right)/2;
    if(left >right)
    {
        cout<<data<<" Not Present "<<endl;
        return false;
    }
    else if(getElement(middle)==data)
    {
        cout<<data<<" Present"<<endl;;
        return true;
    }
    else if(getElement(middle)>data)
    {
        right = middle -1;
        binarySearch(left,right,data);
    }
    else if(getElement(middle)<data)
    {
        left = middle +1;
        binarySearch(left,right,data);
    }
    return false;
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
int Array::getElement(int index)
{
    if((index>=capacity)||(index<0))
    {
        //cout<<"Element out of Array.So can't get value at index : "<<index;
        //cout<<endl;
        return -1;
    }
    return elements[index];
}
void Array::mergeSortIterative(int n )
{
    int s = 1;
    while(s< n)
    {
        for(int i = 0; i<n-1; i+=2*s)
        {
            int middle = i+s-1;
            int right = i+2*s-1;
            if(right>n-1)     // USED BECAUSE IN I+2*S it ca reach out of that like its not necessary that always both have same size
            {
                right = n-1;
            }
            mergeBoth(i,right,middle);
        }
        s = s*2;
    }
    return;
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
int main()
{
    /*  cout << "Hello world!" << endl;
      Array A(5);
      A.setElement(0,10);
      A.setElement(1,20);
      A.setElement(2,30);
      A.setElement(3,40);
      A.setElement(4,50);
      A.setElement(5,60);
      A.binarySearch(0,5,40);
      A.binarySearch(0,5,0);
      A.binarySearch(0,5,10);
      A.binarySearch(0,5,20);
      A.binarySearch(0,5,30);
      A.binarySearch(0,5,40);
      A.binarySearch(0,5,50);
      A.binarySearch(0,5,60);
      A.binarySearch(0,5,70);
      cout<<endl;
      for (int i =0; i<5; i++ )
      {
          cout<<A.getElement(i)<<"    ";
      }
      cout<<endl;
      A.getElement(90);
      A.getElement(-1);
      A.setElement(-1,20);
      for (int i =1; i<=5; i++ )
      {
          A.setElement(i-1,i*i);
      }
      for (int i =0; i<5; i++ )
      {
          cout<<A.getElement(i)<<"    ";
      }
      cout<<endl;
    */
    cout<<"I WILL SORT YOUR ARRAY USING SORT\n";
    cout<<"Enter The Size Of Array\n";
    int n ;
    cin>>n;
    cout<<"Enter The Elements Of Array\n";
    Array B(n);
    for(int i = 0; i<n ; i++)
    {
        int a ;
        cin>>a;
        B.setElement(i,a);
    }
    // B.printArray();
    cout<<"ENTER THE WAY OF SORTING "<<endl;
    cout<<"1) SELECTION SORT STABLE"<<endl;
    cout<<"2) SELECTION SORT UNSTABLE"<<endl;
    cout<<"3) INSERTION SORT"<<endl;
    cout<<"4) MERGE SORT"<<endl;
    cout<<"5) MERGE SORT USING ITERATION"<<endl;
    int a ;
    cout<<"ENTER THE SERIAL NO "<<endl;
    cin>>a;
    switch (a)
    {
    case 1:
        B.selectionSort();
        cout<<"THE SORTED ARRAY USING STABLE SELECTION SORT IS : \n";
        break;
    case 2:
        B.selectionSortUnstable();
        cout<<"THE SORTED ARRAY USING UNSTABLE SELECTION SORT IS: \n";
        break;
    case 3:
        B.insertionSort();
        cout<<"THE SORTED ARRAY USING INSERION SORT IS: \n";
        break;
    case 4:
        B.mergeSort(0,n-1);
        cout<<"THE SORTED ARRAY USING RECURSIVE MERGE SORT IS : \n";
        break;
    case 5:
        B.mergeSortIterative(n);
        cout<<"THE SORTED ARRAY USING ITERATIVE MERGE SORT IS : \n";
        break;
    default:
        break;
    }
    B.printArray();
    cout<<"DONE SUCESSFULLY";
    return 0;
}
