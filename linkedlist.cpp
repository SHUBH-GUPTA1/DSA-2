#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
}*first=NULL,*second=NULL,*third=NULL;
void create(int A[],int n)
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
void create2(int A[],int n)
{
    int i;
    struct node*t,*last;
    second=new struct node;
    second->data=A[0];
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++)
    {
        t=new struct node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct node*p)
{
    while(p!=NULL)
    {
        printf("%d",p->data);
        p=p->next;
    }
}
void Rdisplay(struct node*p){
    if(p!=NULL){
        Rdisplay(p->next);
        printf("%d",p->data);
    }
}
int count(struct node*p){
    int c=0;
    while(p){
        c++;
        p=p->next;
    }
    return c;
}
int Rcount(struct node*p){
    if(p!=NULL)
    return Rcount(p->next)+1;
    else
    return 0;
}
int sum(struct node*p){
    int s=0;
    while(p!=NULL){
        s+=p->data;
        p=p->next;
    }
    return s;
}
int Rsum(struct node*p){
    if(p==0)
    return 0;
    else
    return Rsum(p->next)+p->data;
}
int max(struct node*p){
    int max=-32768;
    while (p){
        if(p->data>max)
        max=p->data;
        p=p->next;
    }
    return max;
}
int Rmax(struct node*p){
    int x=0;
    if(p==0)
    return -32768;                               //minimum integere value for 2 byte integer
    else{
        x=max(p->next);
        if(x>p->data)
        return x;
        else
        return p->data;
    }
}
struct node* Lsearch(struct node*p,int key){
    while(p!=NULL){
        if(key==p->data)
        return p;
        p=p->next;
    }
    return NULL;
}
struct node*Rsearch(struct node*p,int key){
    if(p==NULL)
      return NULL;
    if(key==p->data)
      return p;
    return Rsearch(p->next,key);
}
struct node* LHsearch(struct node*p,int key){
    struct node*q;
    while(p!=NULL){
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
         q=p;
         p=p->next;
    }
    return NULL;
}
void insert(struct node*p,int index,int x){
    struct node *t;
    int i;
    if(index<0 || index>count(p))
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
void sortedinsert(struct node*p,int x){
    struct node*t,*q=NULL;
    t=new struct node;
    t->data=x;
    t->next=NULL;
    if(first==NULL){
        first=t;
    }
    else{
        while(p && p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
}
int  adelete(struct node*p,int index){           //as delete is a keyword so we write adelete
    struct node*q=NULL;
    int x=-1,i;
    if (index<1 || index>count(p))
    return -1;
    if(index==1){
        q=first;
        x=first->data;
        first=first->next;
        delete q;                                   //in c instead of delete we write (free);
        return x;
    }
    else{
        for(i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
        return x;
    }
}
int issorted(struct node*p){
    int x=-32768;
    while(p!=NULL){
        if(p->data<x)
        return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}
void Reverse1(struct node *p)
{
  int *A,i=0;
  struct node *q=p;

  A=(int *)malloc(sizeof(int)*count(p));

  while(q!=NULL)
  {
    A[i]=q->data;
    q=q->next;
    i++;
  }
  q=p;
  i--;
  while(q!=NULL)
  {
    q->data=A[i];
    q=q->next;
    i--;
  }
}
void reverse2(struct node*p){
    struct node*q=NULL,*r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void reverse3(struct node*q,struct node*p){
    if(p){
        reverse3(p,p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}
void merge(struct node*p,struct node*q){
    struct node*last;
    if(p->data<q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while (p&&q){
        if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)
    last->next=p;
    if(q)
    last->next=q;
}
int main()
    {
        struct node*temp;
        int A[]={15,25,35,45,55};
        int B[]={10,20,30,40,50};
        create(A,5);
        create2(B,5);
        merge(first,second);
        display(third);
        printf("\n");

    
 
        
       
        //Rdisplay(first);
        //printf("length is %d\n",count(first));
        //printf("length is %d\n",Rcount(first));
        //printf("sum is %d\n",sum(first));
        //printf("sum is %d\n",Rsum(first));
        //printf("max is %d\n",max(first));
        //printf("max is %d\n",Rmax(first));
        // temp=Lsearch(first,10);
        // if(temp)
        // printf("key is found %d\n",temp->data);
        // else
        // printf("key  not found \n");
        // temp=Rsearch(first,10);
        // if(temp)
        // printf("key is found %d\n",temp->data);
        // else
        // printf("key  not found \n");
        // temp=LHsearch(first,10);
        // temp=LHsearch(first,5);
        // if(temp)
        // printf("key is found %d\n",temp->data);
        // else
        // printf("key  not found \n");
        // display(first);
        // insert(first,2,18);
        // insert(first,4,20);
        // display(first);

        // sortedinsert(first,8);
        // display(first);
        
        // adelete(first,4);
        // display(first);

        // printf("%d\n",issorted(first));
        // display(first);

        // Reverse1(first);
        // display(first);

        // reverse2(first);
        // display(first);

        // reverse3(NULL,first);
        // display(first);
        return 0;
    }
