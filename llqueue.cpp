#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node{
    int data;
    struct node*next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
    struct node *t;
    t=new struct node;
    if(t==NULL)
    cout <<"queue is full"<<endl;
    else{
        t->data=x;
        t->next=NULL;
        if(front==NULL)
        front=rear=t;
        else{
            rear->next=t;
            rear=t;
        }
    }
}
int dequeue(){
    int x=-1;
    struct node *p;
    if(front==NULL)
    cout<<"queue is empty"<<endl;
    else{
    x=front->data;
    p=front;
    front=front->next;
   
    free(p);
}
return x;
}
void display(){
    struct node *p=front;
    while(p){
        cout<<p->data;
        p=p->next;
    }
    cout<<endl;
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();
    cout<<dequeue();
    
}
