#include<iostream>
using namespace std;


struct Queue{
    int size,front , rear;
    int * Q;
}*q=NULL;


void create(int size){
    q = new Queue; // Allocate memory for q
    q->size = size + 1; // Reserve an extra space to differentiate between full and empty
    q->Q = new int[q->size];
    q->front = q->rear = 0;
}


void enqueue(int x){
    if((q->rear+1)%q->size==q->front) cout<<"Queue is full "<<endl;
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}


int dequeue(){
    int x=-1;
    if(q->front==q->rear)   cout<<"Queue is empty"<<endl;
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}


void display(){
    cout<<"Queue is :"<<endl;
    int i=q->front+1;
    do{
        cout<<q->Q[i]<<endl;
        i=(i+1)%q->size;
        }while(i!=(q->rear+1)%q->size);
}


   int main(){ 
    int size;
    cout<<"Enter size"<<endl;
    cin>>size;
    create(size);
    enqueue(5);
    enqueue(7);
    enqueue(9);
    enqueue(100);cout<<endl;
    display();
    cout<<" removed :"<<dequeue();
    cout<<" removed :"<<dequeue();
    display();
    return 0;
}