#include <iostream>
#include <stdio.h>
using namespace std;
struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};
struct queue{
    int size;
    int front;
    int rear;
    Node **Q;
};
void create(struct queue *q,int size){
    q->size=size;
    q->front=q->rear=0;
    q->Q=(Node **)malloc(q->size*sizeof(Node *));
}
void enqueue(struct queue *q,Node *,int x){
    if((q->rear+1)%q->size==q->front)
    cout<<"queue is full";
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
Node * dequeue(struct queue *q){
    Node x=Null;
    if(q->front==q->rear)
    cout<<"queue is full";
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue q){
    return q.front==q.rear;
}





struct Node *root=NULL;
void create(){
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);
    printf("enter root value");
    scanf("%d",&x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    while(!isEmpty(q)){
        p=dequeue(&q);
        printf("enter left child");
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("enter right child");
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(structNode));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}
void preorder(struct Node *p){
    if(p){
        printf("%d",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void IPreorder(struct Node *p){
    struct stack stk;
    Stackcreate(&stk,100);

    while(p|| !isEmptystack(stk)){
        if(p){
          printf("%d",p->data);
          push(&stk,p);
          p=p->rchild; 
        }
        else{
            p=pop(&stk);
            p=p->rchild;
        }
    }
}
int main(){
    create();
    // preorder(root);
    printf("\nPre order");
    IPreorder(root);
}
