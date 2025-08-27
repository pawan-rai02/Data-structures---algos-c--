#include<iostream>
using namespace std;


struct Node{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;


void enqueue(int x){
    struct Node *t = new Node;
    if(t==NULL)    cout<<"Queue is full"<<endl;
    else{
        t->data=x;
        t->next=NULL;
        if(front==NULL)     front=rear=t;
        else{
            rear->next=t;
            rear=t;}
        }
    }


int dequeue(){
    int x=-1;
    if(front==NULL)     cout<<"Queue is empty"<<endl;
    else{
        struct Node *p=new Node;
        p=front;
        x=p->data;
        front=front->next;
        delete p;
        cout<<"deleted : "<<x;
    }cout<<endl;
    return x;
}


void display(){
    struct Node *p=front;
    cout<<"Queue is :"<<endl;
    while(p){
        cout<<p->data<<endl;
        p=p->next;
    }
}


   int main(){ 
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}