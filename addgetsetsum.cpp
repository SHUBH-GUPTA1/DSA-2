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
int get(struct array arr,int index){
    if(index>=0 && index<arr.length)
    return arr.A[index];
    return -1;
}
void set(struct array *arr,int index,int x){
    if(index>=0 && index<arr->length)
    arr->A[index]=x;
}
int max(struct array arr){
    int max=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++){
        if(arr.A[i]>max)
        max=arr.A[i];
    }
    return max;
}
int min(struct array arr){
    int min=arr.A[0];
    int i;
    for(i=1;i<arr.length;i++){
        if(arr.A[i]<min)
        min=arr.A[i];
    }
    return min;
}
int sum(struct array arr){
    int s=0;
    int i;
    for(i=0;i<arr.length;i++){
        s+=arr.A[i];
        return s;
    }
}
float avg(struct array arr){
    return (float)sum(arr)/arr.length;
}

int main(){
    struct array arr={{1,2,3,4,5},5,10};
    //printf("%d\n",get(arr,4));
    //set(&arr,0,12);
    //printf("%d\n",max(arr));
    //printf("%d\n",min(arr));
    //printf("%d\n",sum(arr));
    printf("%f\n",avg(arr));

    display(arr);
    return 0;
}