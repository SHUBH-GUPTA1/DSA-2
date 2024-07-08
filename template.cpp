#include <iostream>
using namespace std;

template<class T>

class array{
    private:
    T *A;
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
      T delete(int index);
};
template <class T>
void array<T>:: display()
{
    for(int i=0;i<length;i++)
    cout<<A[i]<<" "<<endl;
}
template <class T>
void array<T>::insert(int index,T x)
{
    if(index>=0 && index<=length)
    {
    for(int i=length-1;i>=index;i--)
    A[i+1]=A[i];
    A[index]=x;
    length++;
    }
}
template <class T>
int array<T>::delete(int index)
{
    T x=0;
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
    array <int> arr(10);
    
    arr.insert(0,2);
    arr.insert(1,6);
    arr.insert(2,8);
    arr.display();

    return 0;
}