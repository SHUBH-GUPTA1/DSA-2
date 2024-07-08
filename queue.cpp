#include <iostream>
using namespace std;
struct queue{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct queue *q,int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q=new int[q->size];
}
void enqueue(struct queue *q,int x){
    if(q->rear==q->size-1)
    printf("queue overflow");
    else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct queue *q){
    int x=-1;
    if(q->front==q->rear)
    printf("queue is empty");
    else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
void display(struct queue q){
    int i;
    for(i=q.front+1;i<=q.rear;i++)
        printf("%d",q.Q[i]);
        printf("\n");
}
int main(){
    struct queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    display(q);
    return 0;
}