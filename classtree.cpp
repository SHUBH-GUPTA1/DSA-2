#include <iostream>
#include <stdio.h>

using namespace std;

class Node{
    public:
    Node *lchild;
    int data;
    Node *rchild;
};
class queue{
    private:
    int front;
    int rear;
    int size;
    Node**q;
    public:
    queue(){
        front=rear=-1;
        size=10;
        q=new Node*[size];
    }
    queue(int size){
        front=rear=-1;
        this->size=size;
        q=new Node*[this->size];
    }
    void enqueue(Node* x);
    Node* dequeue();
    int isEmpty(){
    return front==rear;  
    }
    void display();
};
void queue::enqueue(Node *x){
    if(rear==size-1)
    printf("queue full\n");
    else{
        rear++;
        q[rear]=x;
    }
}
Node* queue::dequeue(){
    Node* x=NULL;
    if(front==rear)
    printf("queue is empty\n");
    else{
        x=q[front+1];
        front++;
    }
    return x;
}
void queue::display(){
    for(int i=front+1;i<=rear;i++)
    printf("%d",q[i]);
    printf("\n");
}
// class Tree{
//     public:
//     Node*root;
//     Tree(){
//         rooot=NULL;
//     }
//     void CreateTree();
//     void Preorder(Node*p);
//     void Postorder(Node*p);
//     void Inorder(Node*p);
//     void Levelorder(Node*p);
//     int Height(Node*root);
// };
// void Tree::CreateTree(){
//     Node*p,*t;
//     int x;
//     queue q(100);
    
//     printf("enter root value");
//     scanf("%d",&x);
//     root=new Node;
//     root->data=x;
//     root->lchild=root->rchild=NULL;
//     q.enqueue(root);
//     while(!q.isEmpty(q)){
//         p=q.dequeue();
//         printf("enter left child of %d",p->data);
//         scanf("%d",&x);
//         if(x!=-1){
//             t=new Node;
//             t->data=x;
//             t->lchild=t->rchild=NULL;
//             p->lchild=t;
//             q.enqueue(t);
//         }
//         printf("enter right child of %d",p->data);
//         scanf("%d",&x);
//         if(x!=-1){
//             t=new Node;
//             t->data=x;
//             t->lchild=t->rchild=NULL;
//             p->rchild=t;
//             q.enqueue(t);
//         }
//     }
// }
// void Tree::Preorder(struct Node*p){
//     if(p){
//         printf("%d",p->data);
//         Preorder(p->lchild);
//         Preorder(p->rchild);
//     }
// }
// void Tree::Inorder(struct Node*p){
//     if(p){
//         Inorder(p->lchild);
//         printf("%d",p->data);
//         Inorder(p->rchild);
//     }
// }
// void Tree::Postorder(struct Node *p){
//     if(p){
//         Postorder(p->lchild);
//         Postorder(p->rchild);
//         printf("%d",p->data);
//     }
// }
// void Tree:: Levelorder(struct Node*root){
//     queue q(100);
    

//     printf("%d",root->data);
//     q.enqueue(root);

//     while(!q.isEmpty()){
//         root=q.dequeue();
//         if(root->lchild){
//             printf("%d",root->lchild->data);
//             q.enqueue(root->lchild);
//         }
//         if(root->rchild){
//             printf("%d",root->rchild->data);
//             q.enqueue(root->rchild);
//         }
//     }
// }
// int Tree::Height(struct Node *root){
//     int x=0,y=0;
//     if(root==0)
//     return 0;
//     x=Height(root->lchild);
//     y=Height(root->rchild);
//     if(x>y)
//     return x+1;
//     else
//     return y+1;
// }

// int main(){
//     Tree t;
//     t.CreateTree();
//     t.Preorder();
//     return 0;
// }

class Tree
{
 Node *root;      //it is private as we can call dumy function internally like void Preorder(){Preorder(root);}

public:
 Tree(){root=NULL;}
 void CreateTree();
 void Preorder(){Preorder(root);}
 void Preorder(Node *p);
 void Postorder(){Postorder(root);}
 void Postorder(Node *p);
 void Inorder(){Inorder(root);}
 void Inorder(Node *p);
 void Levelorder(){Levelorder(root);}
 void Levelorder(Node *p);
 int Height(){return Height(root);}
 int Height(Node *root);
};
void Tree::CreateTree()
{
 Node *p,*t;
 int x;
 queue q(100);

 printf("Eneter root value ");
 scanf("%d",&x);
 root=new Node;
 root->data=x;
 root->lchild=root->rchild=NULL;
 q.enqueue(root);

 while(!q.isEmpty())
 {
 p=q.dequeue();
 printf("enter left child of %d ",p->data);
 scanf("%d",&x);
 if(x!=-1)
 {
 t=new Node;
 t->data=x;
 t->lchild=t->rchild=NULL;
 p->lchild=t;
 q.enqueue(t);
 }
 printf("enter right child of %d ",p->data);
 scanf("%d",&x);
 if(x!=-1)
 {
 t=new Node;
 t->data=x;
 t->lchild=t->rchild=NULL;
 p->rchild=t;
 q.enqueue(t);
 }
 }
}
void Tree::Preorder(struct Node *p)
{
 if(p)
 {
 printf("%d ",p->data);
 Preorder(p->lchild);
 Preorder(p->rchild);
 }
}
void Tree::Inorder(struct Node *p)
{
 if(p)
 {
 Inorder(p->lchild);
 printf("%d ",p->data);
 Inorder(p->rchild);
 }
}
void Tree::Postorder(struct Node *p)
{
 if(p)
 {
 Postorder(p->lchild);
 Postorder(p->rchild);
 printf("%d ",p->data);
 }
}
void Tree::Levelorder(struct Node *root)
{
 queue q(100);

 printf("%d ",root->data);
 q.enqueue(root);

 while(!q.isEmpty())
 {
 root=q.dequeue();
 if(root->lchild)
 {
 printf("%d ",root->lchild->data);
 q.enqueue(root->lchild);
 }
 if(root->rchild)
 {
 printf("%d ",root->rchild->data);
 q.enqueue(root->rchild);
 }
 }
}
int Tree::Height(struct Node *root)
{
 int x=0,y=0;
 if(root==0)
 return 0;
 x=Height(root->lchild);
 y=Height(root->rchild);
 if(x>y)
 return x+1;
 else
 return y+1;

}
int main()
{
 Tree t;
 t.CreateTree();
 cout<<"Preorder ";
 t.Preorder();
 cout<<endl;
 cout<<"Inorder ";
 t.Inorder();
 cout<<endl<<endl;

 return 0;
}