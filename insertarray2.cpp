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

void insertsort(struct array *arr,int x){
    int i=arr->length-1;
    if(arr->length==arr->size)
    return;
    while(arr->A[i]>x){
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}
int issorted(struct array arr){
    int i;
    for(i=0;i<arr.length-1;i++){
        if(arr.A[i]>arr.A[i+1])
        return 0;
    }
    return 1;
}
void rearrange(struct array *arr){
    int i,j;
     i=0;
     j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0)i++;
        while(arr->A[j]>0)j++;
        if(i<j)swap(&arr->A[i],&arr->A[j]);
    }
}
int main(){
    //struct array arr={{1,7,12,15,20},5,10};
    //insertsort((&arr),10);
    //printf("%d\n",issorted(arr));
    struct array arr={{2,-3,25,10,-15,-7},6,10};
    rearrange(&arr);
    display(arr);
    return 0;
}