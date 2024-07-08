#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct array{
    int *A;
    int size;
    int length;
};

void display(struct array arr){
    int i;
    printf("elements are\n");
    for ( i = 0; i < arr.length; i++)
    {
        printf("%d",arr.A[i]);
    }
    
}

int main(){

struct array arr;
int i,n;
    printf("enter size of  array");
    scanf("%d",&arr.size);
    arr.A=new int[10];
    arr.length=0;
    
    printf("enter no.of elements");
    scanf("%d",&n);

    printf("enter all the elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&arr.A[i]);
    arr.length=n;

    display(arr);
    return 0;
}