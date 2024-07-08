#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
};
class linkedlist{
    private:
    node*first;
    public:
    linkedlist(){ first=NULL;}
    linkedlist(int A[],int n);
    ~linkedlist();
    void display();
    void insert(int index,int x);
    int delete(int index);
    int length();
};
linkedlist::linkedlist(int A[],int n)
{
    int i;
    struct node*t,*last;
    first=new struct node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=new struct node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
linkedlist::~linkedlist(){
    node*p=first;
    while(first){
        first=first->next;
        delete p;
        p=first;
    }
}
void linkedlist::display()
{
    node*p=first;
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
}
int linkedlist::length(){
    node*p=first;
     int c=0;
    while(p){
        c++;
        p=p->next;
    }
    return c;
}
void linkedlist::insert(int index,int x){
    node*p=first;
     struct node *t;
    int i;
    if(index<0 || index>length())
    return;
    t=new struct node;
    t->data=x;
    if(index==0){
        t->next=first;
        first=t;
    }
    else{
        for(i=0;i<index-1;i++)
        p=p->next;
        t->next=p->next;
        p->next=t;
    }
}
int linkedlist::adelete(int index){
    struct node*p,*q=NULL;
    int x=-1,i;
    if (index<1 || index>length())
    return -1;
    if(index==1){
        p=first;
        x=first->data;
        first=first->next;
        delete p;                                   //in c instead of delete we write (free);
        return x;
    }
    else{
        p=first;
        for(i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
    }
     return x;
}
int main(){
    int A[]={1,2,3,4,5};
    linkedlist(A,5);
    display();
    return 0;
}