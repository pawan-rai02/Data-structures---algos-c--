#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL;


void create(int A[],int n){
    int i;
    struct Node *t,*last;
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


void display(struct Node *p){   //displays the Linked List
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;;

    }
    cout<<endl;
}


int sum(struct Node *p){  // adds all the elements present in a Linked List
    if (p==0) return 0;
    else return (sum(p->next)+p->data);
}


int count(struct Node *p){  //countss the length
    int c=0;
    if(p) return (count(p->next)+1);
    else return 0;
}


struct Node* search(struct Node *p, int key){  //searching
    if(!p) return NULL;
    while(p){
    if(key==p->data) return p;
    p=(p->next);}

}


int max(struct Node *p){ //finding max element

    int x=0;
    if(!p) return INT32_MIN;
    x=max(p->next);
    return (x>p->data?x:p->data);
}


void insert(struct Node *p,int x, int index){   //insertion
    struct Node *t;
    if(index<0||index>count(p)) return;

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


void sortedInsert(struct Node *p, int x){   //insertion in a sorted Linked List
    struct Node *t= new Node, *q=NULL;
    t->data=x;
    t->next=NULL;

    if(!p)  first=t;
    else
    while(p && p->data<x){
        q=p;
        p=p->next;
    }
    if(p==first){
        t->next=first;
        first=t;
    }
    else{
    t->next=q->next;
    q->next=t;
    }
}


int Delete(struct Node *p, int index){   //deleting a node
    struct Node *q=NULL;
    int x=-1,i;
    if(index<1 || index> count(p))
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


int isSorted(struct Node *p){
    int x= INT32_MIN;
    while(p){
        if(p->data<x) return false;
    x=p->data;
    p=p->next;
    }  return true;
}


void removeDuplicates(struct Node *p){
    p=first;
    struct Node *q=p->next;
    while(q){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}


void Reverse(struct Node *q, struct Node *p){
    if(p){
        Reverse(p,p->next);
        p->next=q;
    }
    else first=q;
}


int main(){
    int A[]={3, 4, 6, 8, 8, 8, 9};
 
    create(A,5);
    cout<<"Linked list is :";
    display(first);
    cout<<endl<<"SUM is :"<<sum(first)<<endl;
    cout<<"LENGTH OF LINKED LIST IS :"<<count(first)<<endl;
    cout<<"MAXIMUM ELEMENT IS :"<<max(first)<<endl;

    struct Node *temp;
    
    temp=search(first,3);
    if (temp) cout<<" address is :"<<temp<<endl;


   insert(first,10,3);
   cout<<"New linked list is :"<<endl;
   display(first);


   cout<<"After sorted insertion :";
   sortedInsert(first,33);
   display(first);


   int index;
   cout<<"enter index to be deleted"<<endl;
   cin>>index;
   cout<<"After deleting the "<< index<< " element , the Linked List is :"<<endl;
   Delete(first, index);
   display(first);

   cout<<"Sorted or Not? "<<isSorted(first)<<endl;

   cout<<"after deleting duplicate elements, linked list is :"<<endl;
   removeDuplicates(first);
   display(first);

   cout<<"Reversed linked list :"<<endl;
   Reverse(0,first);
   display(first);
}