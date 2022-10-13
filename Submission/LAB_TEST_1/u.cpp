#include <iostream>

#ifndef ARRAYCLASS_H
#define ARRAYCLASS_H
using namespace std;

class arrayclass
{
    public:
        arrayclass();
        arrayclass(int);
       bool storeElement(int,int);
       int takeElement(int);
       int getmaxsize();
       bool flipflop(int);
       int reqval;
        virtual ~arrayclass();
    protected:
    private:
        int maxsize;
        int* elements;
        int index;
        int i;

};

#endif // ARRAYCLASS_H


arrayclass::arrayclass()
{
    maxsize=0;
    elements=NULL;
}
arrayclass::arrayclass(int Size)
{
    maxsize=Size;
    elements=new int[Size];

}
bool arrayclass::storeElement(int index,int val)
{
    elements[index]=val;
    return (true);
}
int arrayclass::takeElement(int index)
{
    return (elements[index]);
}
int arrayclass::getmaxsize()
{
    return(maxsize);
}
bool arrayclass::flipflop(int reqval)
{
    for(i=0; i<(reqval/2); i++)
    {
        elements[i]=elements[reqval-i];
    }
    return(true);
}
arrayclass::~arrayclass()
{
    delete[] elements;
}
#ifndef INVERTSTACKCLASS_H
#define INVERTSTACKCLASS_H

using namespace std;



class invertstackclass
{
    public:
        invertstackclass()=delete;
        invertstackclass(int);
        bool push(int);
        int pop();
        bool isempty();
        bool isfull();
        void print();
        virtual ~invertstackclass();
    protected:
    private:
        int valcount;
        arrayclass members;
        int j;
};

#endif // INVERTSTACKCLASS_H


invertstackclass::invertstackclass(int stackmaxsize): members(stackmaxsize)
{
    valcount=0;
}
bool invertstackclass::push(int val)
{
   if(isfull())
   {
       return(false);
   }
   members.flipflop(valcount);
   members.storeElement(valcount,val);
   valcount++;
   return(true);
}
int invertstackclass::pop()
{
    if(isempty())
    {
        return(-1);
    }
    valcount--;
    members.flipflop(valcount);
    return(members.takeElement(valcount));

}
bool invertstackclass::isempty()
{
    if(valcount==0)
    {
        return(true);
    }
    return(false);
}
bool invertstackclass::isfull()
{
    if(valcount==members.getmaxsize())
    {
        return(true);
    }
    return(false);
}
void invertstackclass::print()
{
    for(j=0; j<valcount; j++)
    {
        members.takeElement(j);
    }
}

invertstackclass::~invertstackclass()
{
    //dtor
}

using namespace std;

int main()
{


 int a,b;
 cin>>a;
 cin>>a;
 invertstackclass stk1(a);




 while(cin>>a){
    if(a==2)
    {
      cin>>b;
      stk1.push(b);
    }
    if(a==3)
    {
      stk1.pop();
    }
    if(a==7)
    {
         stk1.print();
    }
 }



return 0;
}