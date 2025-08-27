#include<iostream>
using namespace std;


class Queue{
    private:
        int size,rear,front;
        int *Q;
    public:
        Queue(int size){
            front=rear=-1;
            this->size=size;
            Q=new int[this->size];
        } 
        void enqueue(int x);
        int dequeue();
        void display();
};


void Queue:: enqueue(int x){
    if(rear==size-1)  cout<<"Queue full !"<<endl;
    else{
        rear++;
        Q[rear]=x;
    }
}


int Queue::dequeue(){
    int x=-1;
    if(front==rear) cout<<"Queue is empty "<<endl;
    else{
        front++;
        x=Q[front];
        cout<<" Deleted "<<x<<" ;";
    }
    return x;
}


void Queue:: display(){
    cout<<"The queue is :"<<endl;
    for(int i=front+1;i<=rear;i++){
        cout<<Q[i]<<endl;
    }cout<<endl;
}


   int main(){ 
   Queue q(5);
   q.enqueue(8);
   q.enqueue(10);
   q.enqueue(12);

   q.enqueue(14);
   q.enqueue(16);
   q.enqueue(18);
   q.display();
   q.dequeue();
   q.dequeue();
   q.dequeue();
   q.display();


    return 0;
}