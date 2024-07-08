#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct stack{
    int size;
    int top;
    int *S;
};
void create(struct stack *st){
    printf("enter size of stack\n");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=new int(st->size);
}
void display(struct stack st){
    int i,top;
    for(i=st.top;i>=0;i--){
        printf("%d",st.S[i]);
        printf("\n");
    }
}
void push(struct stack *st,int x){
    if(st->top==st->size-1)
    printf("stack overflow\n");
    else{
        st->top++;
        st->S[st->top]=x;
    }
}
int pop(struct stack *st){
    int x=-1;
    if(st->top==-1)
    printf("stack underflow\n"); 
    else{
        x=st->S[st->top--];
    }
    return x;
}
int peek(struct stack st,int index){
    int x=-1;
    if(st.top-index+1<0)
        printf("invalid index");
        else{
            x=st.S[st.top-index+1];
            return x;
        }
}
int isempty(struct stack st){
    if(st.top==-1)
    return 1;
    else
    return 0;
}
int isfull(struct stack st){
    return st.top==st.size-1;
}
int stacktop(struct stack st){
    if(st.top==-1)
    return -1;
    else
    return st.S[st.top];
}
int main(){
    struct stack st;
    create(&st);

    //    PUSH
    // push(&st,10);
    // push(&st,20);
    // push(&st,30);
    // push(&st,40);
    // push(&st,50);
    // display(st);

    //     POP
    // printf("%d \n", pop(&st));
    // push(&st,10);
    // push(&st,20);
    // printf("%d \n", pop(&st));
    // printf("%d \n", pop(&st));
    // printf("%d \n", pop(&st));
    // display (st);

    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);
    printf("%d\n",peek(st,2));
    display(st);

    
    return 0;
}