#include <iostream>
#include<stdio.h>
using namespace std;

int fact(int n){
    if(n==0)
    return 1;
    else
    return fact(n-1)*n;
}
int nCr(int n,int r){
    int num,den;
    num=fact(n);
    den=fact(n-r)*fact(r);
    return num/den;
}
int P(int n,int r){
    if(r==0 || n==r)
    return 1;
    else
    return P(n-1,r-1)+P(n-1,r);
}
int main(){
    printf("%d \n",P(5,2));
    return 0;
}