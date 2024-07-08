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
    q->front=q->rear=0;
    q->Q=new int[q->size];
}
void enqueue(struct queue *q,int x){
    if((q->rear+1)%q->size==q->front)
    cout<<"queue is full";
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct queue *q){
    int x=-1;
    if(q->front==q->rear)
    cout<<"queue is full";
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
void display(struct queue q)
{
    int i=q.front+1;
    do{
        cout<<q.Q[i];
        i=(i+1)%q.size;
    }while(i!=(q.rear+1)%q.size);
    cout<<endl;
}
int main(){
    struct queue q;
    create(&q,5);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    enqueue(&q,60);
    display(q);
    cout<<dequeue(&q);
}