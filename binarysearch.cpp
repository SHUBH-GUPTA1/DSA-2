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
int binsearch(struct array arr,int key){
    int l,h,mid;
    l=0;
    h=arr.length-1;

    while(l<=h){
        mid=(l+h)/2;
        if(key==arr.A[mid])
        return mid;
        else if(key<arr.A[mid])
        h=mid-1;
        else 
        l=mid+1;
    }
    return -1;
}

int Rbinsearch(int A[],int l,int h,int key){
    int mid;
    if(l<=h){
        mid=(l+h)/2;
        if(key==A[mid])
        return mid;
        else if(key<A[mid])
        return Rbinsearch(A,l,mid-1,key);
        else
        return Rbinsearch(A,mid+1,h,key);
    }
    return -1;
}
int main(){
    struct array arr={{1,2,3,4,5},5,10};
    printf("%d\n",Rbinsearch(arr.A,0,arr.length,4));
    //printf("%d\n",binsearch(arr,4));
    display(arr);
    return 0;
}