#include<iostream>
using namespace std;


struct Stack{
    int size, top, *S;
};


void create(struct Stack *st){
    cout<<"Enter the size"<<endl;
    cin>>st->size;
    st->top=-1;
    st->S=new int[st->size];
}


void display(struct Stack *st){
    int i;
    cout<<"Stack is :"<<endl;
    for(i=st->top;i>=0;i--){
        cout<<st->S[i];
        cout<<endl;
    }
}


void push(struct Stack *st, int x){
    if(st->top==st->size-1) cout<<"Stack OverFlow"<<endl;
    else {
        st->top++;
        st->S[st->top]=x;
    }}


int pop(struct Stack *st){
    int x=-1;
    if(st->top==-1) cout<<"Stack UndeFlow"<<endl;
    else{
        x=st->S[st->top--];
    }
    return x;
}


int peek(struct Stack *st, int index){
    int x=-1;
    if(st->top-index+1<0) cout<<"Invalid Index"<<endl;
    else   x=st->S[st->top-index+1];
    return x;
}


int isEmpty(struct Stack *st){
    if(st->top==-1) return 1;
    return 0;
}


int isFull(struct Stack *st){
    if(st->top==st->size-1) return 1;
    return 0;
}


int stackTop(struct Stack *st){
    if(!isEmpty(st)) return st->S[st->top];
    return -1;
}


int main(){ 
    struct Stack st;
    create(&st);
    push(&st, 10);
     push(&st, 60);
      push(&st, 50);
       push(&st, 40);
        push(&st, 30);
         push(&st, 20);
    display(&st);
   // cout<<pop(&st)<<" "<<pop(&st)<<" "<<pop(&st)<<" "<<pop(&st)<<" "<<pop(&st)<<endl;
    cout<<"is Full? :"<<isFull(&st)<<endl;
    cout<<"is Empty? :"<<isEmpty(&st)<<endl;
    cout<<"Topmost element :"<<stackTop(&st)<<endl;
    int peekI;
    cout<<"enter peek index ";  cin>>peekI;
    cout<<"Element is :"<<peek(&st, peekI)<<endl;
   // cout<<"Stack is :"<<endl;
    display(&st);
    return 0;
}