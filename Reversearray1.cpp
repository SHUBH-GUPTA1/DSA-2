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

void reverse(struct array *arr){
    int *B;
    int i,j;
    
    B=(int*)malloc (arr->length*sizeof(int));
    for(i=arr->length-1,j=0;i>=0;i--,j++){
        B[j]=arr->A[i];
        for(i=0;i<arr->length;i++)
        arr->A[i]=B[i];
    }
}
int main(){
    struct array arr={{1,2,3,4,5},5,10};
    reverse(&arr);
    display(arr);
    return 0;
}