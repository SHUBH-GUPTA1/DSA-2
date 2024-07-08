#include <iostream>
using namespace std;

class array{
    private:
    int *A;
    int size ;
    int length;

    public:
    array()
    {
    size=10;
    A=new int[10];
    length=0;
    }
    array(int sz)
    {
        size=sz;
        A=new int[size];
        length=0;
    }
    ~array()
        {
            delete []A;
        }
      void display();
      void insert(int index,int x);
      int delete(int index);
};

void array:: display()
{
    for(int i=0;i<length;i++)
    cout<<A[i]<<" "<<endl;
}
void array::insert(int index,int x)
{
    if(index>=0 && index<=length)
    {
    for(int i=length-1;i>=index;i--)
    A[i+1]=A[i];
    A[index]=x;
    length++;
    }
}
int array::delete(int index)
{
    int x=0;
     if(index>=0 && index<length)
     {
         x=A[index];
         for(int i=index;i<length-1;i++)
         A[i]=A[i+1];
         length--;
     }
     return x;
}

int main(){
    array arr(10);
    
    arr.insert(0,2);
    arr.insert(1,6);
    arr.insert(2,8);
    arr.display();

    return 0;
}