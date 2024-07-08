#include <iostream>
#include<stdio.h>
using namespace std;

struct array{
    int A[20];
    int length;
    int size;
};
void swap(int *x,int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void display(struct array arr){
    int i;
    for ( i = 0; i < arr.length; i++)
    {
        printf("%d",arr.A[i]);
    }
    
}
int linearsearch(struct array *arr,int key){
    int i;
    for ( i = 0; i < arr->length; i++)
    {
        if(key==arr->A[i])
        {
        swap(&arr->A[i],&arr->A[i-1]);
        return i;
        }
    }
    return -1;
    
}

int main(){
    struct array arr={{1,2,3,4,5},5,10};
    printf("%d\n",linearsearch(&arr,3));
    display(arr);
    return 0;
}