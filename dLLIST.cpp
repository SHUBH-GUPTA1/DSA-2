#include <iostream>
using namespace std;

struct node{
    struct node*prev;
    int data;
    struct node*next;
}*first=NULL;

void create(int A[],int n){
    struct node*t,*last;
    int i;
    first=new struct node;
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=new struct node;
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t; 
        last=t;
    }
}
void display(struct node*p){
    while(p)
{
    printf("%d",p->data);
    p=p->next;
}
printf("\n");
}
int length(struct node*p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
void insert(struct node*p,int index,int x){
    struct node*t;
    int i;
    if(index<0 || index>length(first))
    return;
    if(index==0){
        t=new struct node;
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else{
        for(i=0;i<index-1;i++){
            p=p->next;
        }
            t=new struct node;
            t->data=x;
            t->prev=p;
            t->next=p->next;
            if(p->next)
            p->next->prev=t;
            p->next=t;
    }
}
int adelete(struct node*p,int index){
    struct node*q;
    int x=-1,i;
    if(index<1 || index>length(first))
    return -1;
    if(index==1){
        first=first->next;
        if(first)
        first->prev=NULL;
        x=p->data;
        delete p;
    }
    else{
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next)
        p->next->prev=p->prev;
        x=p->data;
        delete p;
    }

}
int main(){
    int A[]={1,2,3,4,5};
    create(A,5);

    // printf("length is: %d\n",length(first));
    // insert(first,0,25);
    adelete(first,3);
    display(first);
    return 0;
}