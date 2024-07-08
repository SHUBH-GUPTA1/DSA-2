#include <iostream>
#include<stdio.h>
using namespace std;

struct array{
    int A[20];
    int length;
    int size;
};
void display(struct array arr){
    int i;
    for ( i = 0; i < arr.length; i++)
    {
        printf("%d",arr.A[i]);
    }
    
}

int delete(struct array *arr,int index){
    int x=0;
    int i;

    if(index>=0 && index<=arr->length){
    x=arr->A[index];
         for(i=index;i<arr->length-1;i++)
              arr->A[i]=arr->A[i+1];
                 arr->length--;
    return x;
    }
}

int main(){
    struct array arr={{1,2,3,4,5},5,10};
    printf("%d\n",delete(&arr,4);
    display(arr);
    return 0;
}