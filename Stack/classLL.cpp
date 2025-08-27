#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node *next;
};


class Stack{
    private:
        Node *top;
    public:
        Stack(){top=NULL;}
        void push(int x);
        int pop();
        void display();
};


void Stack::push(int x){
    Node *t=new Node;
    if(t==NULL) cout<<"OverFlow"<<endl;
    else{
        t->data=x;
        t->next=top;
        top=t;
        }
}


int Stack::pop(){
    cout<<" POPPED ";
    int x=-1;
    if(top==NULL)    cout<<"Stack Underflow"<<endl;
    else{
        Node *p=top;
        top=top->next;
        x=p->data;
        delete p;
    }
    return x; 
}


void Stack::display(){
    cout<<"Stack is :"<<endl;
    Node *p=top;
    while(p){
        cout<<p->data<<endl;
        p=p->next;
    }
    cout<<endl;
}


   int main(){ 
    Stack stk;
    stk.push(50);
    stk.push(40);
    stk.push(30);
    stk.push(20);
    stk.push(10);
    cout<<"Original (before popping) :"<<endl;
    stk.display();
    cout<<stk.pop();
    cout<<stk.pop();
    cout<<stk.pop();
    cout<<endl<<" After popping :"<<endl;
    stk.display();
    return 0;
}