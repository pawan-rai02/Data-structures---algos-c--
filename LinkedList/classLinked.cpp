#include<iostream>
using namespace std;



class Node{
    public:
        int data;
        Node *next;
};



class LinkedList{
    private:
        Node * first;
    public:
        LinkedList(){first=NULL;}
        LinkedList(int A[],int n);
        ~LinkedList();

        void display();
        void Insert(int index, int x);
        int Delete(int index);
        int length();
};



LinkedList::LinkedList(int A[],int n){
    int i;
     Node *t,*last;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;    ///////links the last node (pointed by last) to the new node (pointed by t).
        last =t;
    }
}



LinkedList::~LinkedList(){
    Node *p=first;
    while(first){
        first=first->next;
        delete p;
        p=first;
    }
}



void LinkedList:: display(){
Node *p=first;
while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;;

    }
    cout<<endl;
}



void LinkedList:: Insert(int index,int x){
     Node *t,*p=first;
    if(index<0||index>length()) return;

    t=new Node;
    t->data=x;
    if(index==0){
        t->next=first;
        first=t;}
    else {
        for(int i =0;i<index-1;i++) p=p->next;
        t->next=p->next;
        p->next=t;

    }
}



int LinkedList::Delete(int index){
     Node *q=NULL,*p=first;
    int x=-1,i;
    if(index<1 || index> length())
        return -1;
    if(index==1){
        q=first;
        first=first->next;
        x=q->data;
        delete q;
        return x;
    }
    else {
        for(i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
        return x;
    }
}



int LinkedList::length(){
  Node *p=first;
  int l=0;
  while(p){
    l++;
    p=p->next;
  } return l;
}



   int main(){ 
    int A[]={ 1, 2, 3, 4, 5, };
    LinkedList l(A,5);
    l.display();
    cout<<l.Delete(1)<<endl;
    cout<<l.length()<<endl;
    l.Insert(3,10);
    l.display();

    return 0;
}