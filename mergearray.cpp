#include <iostream>
#include<stdio.h>
#include<cmath>
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
        printf("%d ",arr.A[i]);
    }
    
}

struct array* merge(struct array *arr1,struct array *arr2){

    int i,j,k;
    i=j=k=0;
    struct array *arr3=(struct array *)malloc(sizeof(struct array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j])
           arr3->A[k++]=arr1->A[i++];
        else
           arr3->A[k++]=arr2->A[j++];   
    }
    for(;i<arr1->length;i++)
      arr3->A[k++]=arr1->A[i];
      for(;j<arr2->length;j++)
      arr3->A[k++]=arr2->A[j];
      arr3->length=arr1->length+arr2->length;
      arr3->size=10;
      return arr3;
}
struct array* unin(struct array *arr1,struct array *arr2){

    int i,j,k;
    i=j=k=0;
    struct array *arr3=(struct array *)malloc(sizeof(struct array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j])
           arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
           arr3->A[k++]=arr2->A[j++];
           else
           {
           arr3->A[k++]=arr1->A[i++];
           j++;
           }   
    }
    for(;i<arr1->length;i++)
      arr3->A[k++]=arr1->A[i];
      for(;j<arr2->length;j++)
      arr3->A[k++]=arr2->A[j];

      arr3->length=k;
      arr3->size=10;

      return arr3;
}
struct array* intersection(struct array *arr1,struct array *arr2){

    int i,j,k;
    i=j=k=0;
    struct array *arr3=(struct array *)malloc(sizeof(struct array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j])
           i++;
        else if(arr2->A[j]<arr1->A[i])
           j++;
           else if(arr1->A[i]==arr2->A[j])
           {
           arr3->A[k++]=arr1->A[i++];
           j++;
           }   
    }
    

      arr3->length=k;
      arr3->size=10;
}
int main(){
    //struct array arr1={{4,5,7,9,12},5,10};
    //struct array arr2={{2,6,13,18,20},5,10};
    //struct array *arr3;
    //arr3=merge(&arr1,&arr2);
    // display(*arr3);

    struct array arr1={{2,5,6,9,20},5,10};
    struct array arr2={{2,6,13,18,20},5,10};
    struct array *arr3;
     arr3=unin(&arr1,&arr2);
    display(*arr3);

    //struct array arr1={{2,5,6,9,20},5,10};
    //struct array arr2={{2,6,13,18,20},5,10};
    //struct array *arr3;
    //arr3=intersection(&arr1,&arr2);
    //display(*arr3);
    return 0;
}