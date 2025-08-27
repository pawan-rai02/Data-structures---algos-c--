#include<iostream>
using namespace std;
struct Node {
    int data;
    struct Node *next;
}*top=NULL;


void push(int x){
    struct Node *t=new Node;
    if(t==0) cout<<"Overflow"<<endl;
    else{
    t->data=x;
    t->next=top;
    top=t;}
}


int pop(){
    int x=-1;
    struct Node *t=top;
    if(top){
        top=top->next;
        x=t->data;
        delete t;
        cout<<"Popped :";
        } 
    
    return x;
}


void Display(){
    struct Node *p;
    p=top;
    cout<<"The Stack is :"<<endl;
    while(p){
        cout<<p->data<<endl;
        p=p->next;
    }
    cout<<endl;
}


   int main(){ 
    push(10);
     push(60);
      push(50);
       push(40);
        push(30);
         push(20);
    cout<<"Before popping  :"<<endl;
    Display();
    cout<<pop()<<" ";cout<<pop()<<" ";cout<<pop()<<endl;
    cout<<"After popping  :"<<endl;
    Display();
    return 0;
}