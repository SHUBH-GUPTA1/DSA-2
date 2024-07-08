#include <iostream>
#include<stdio.h>
using namespace std;

struct array{
    int A[20];
    int length;
    int size;
};

void insert(struct array *arr,int index,int x){
    int i;
    if(index>=0 && index<=arr->length){
        for(i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
            arr->A[index]=x;
            arr->length++;
    }
}
void display(struct array arr){
    int i;
    for ( i = 0; i < arr.length; i++)
    {
        printf("%d",arr.A[i]);
    }
    
}

int main(){
    struct array arr={{1,2,3,4,5},5,10};

    insert(&arr,4,10);
    display(arr);
    return 0;
}