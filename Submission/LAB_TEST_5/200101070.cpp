#include <iostream>
using namespace std;
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

void namanSort(int* A, int *B,int n)
{
    for (int i = 0; i < n; i++)
    {
      int minimum = B[i];
      int min2 = A[i];
      for (int j = i+1; j < n; j++)
      {
          if(B[j]<minimum)
          {
              minimum = B[j];
              min2= A[j];
              swap(B[i],B[j]);
              swap(A[i],A[j]);
          }
          if(B[j]==minimum)
          {
              if(A[j]<min2)
              {
                  min2 = A[j];
                  swap(B[i],B[j]);
                  swap(A[i],A[j]);
              }
          }
      } 
    }
    return ;
}
int main()
{
    int n;
    cin>>n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    int B[n];
    for (int i = 0; i < n; i++)
    {
        int o = A[i];
        int r = 0;
        while (o!=0)
        {
            r = r+o%10;
            o = o/10;
        }
        B[i]= r;
    }
    namanSort(A,B,n);
    for (int i = 0; i < n; i++)
    {
        if(i==n-1)
        {
        cout<<A[i]<<endl;
        }
        else
        {
        cout<<A[i]<<" ";
        }
    }
    return 0;
}
