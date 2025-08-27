#include<iostream>
using namespace std;


struct Node{
    int data;
    struct Node * next;
}*Head;


void create(int A[], int n){
    int i;
    struct Node *t, *last;
    Head = new Node();
    Head->data=A[0];
    Head->next=Head;
    last=Head;
for(i=1;i<n;i++){
    t=new Node();
    t->data=A[i];
    t->next=last->next;
    last->next=t;
    last=t;
}
}


int length(struct Node *p){
    int length=0;
    do{
        length++
        ;p=p->next;
    }while(p!=Head);
    return length;
}


void insert(struct Node *p,int index, int x){
    struct Node *t;
    t=new Node();
    t->data=x;
    //t->next=0;
    int i;
    if(index==0){
        if(Head==0){
            Head=t;
            Head->next=Head;
        }
        else { while(p->next!=Head) p=p->next;
        p->next=t;
        t->next=Head;
        t->next=Head;
        Head=t;
        }
    }
    else {
        for(i=0;i<index-1;i++) p=p->next;
        t->next=p->next;
        p->next=t;
    }

}


void display( Node *Head){
 Node* p = Head; // Start from the head
    do {
        cout << p->data << " "; // Print the current node's data
        p = p->next; // Move to the next node
    } while (p != Head);
}


int Delete(struct Node *p, int index){
    struct Node *q;
    int i,x;

    if(index<0 || index>length(Head))  return -1;
    if(index==1){
        while(p->next!=Head) p=p->next;
        x=Head->data;
        if(Head==p){
            free(Head);
            Head=0;
        }
        else{
            p->next=Head->next;
            free(Head);
            Head=p->next;
        }
    }
    else{
        for(i=0;i<index-2;i++) p=p->next;
        q=p->next;
        p->next=q->next;
        x=q->data;
        free (q);
    }
    return x;
}


 int main(){ 
    int A[]= {1, 2, 3, 4, 5, };
    create(A,5);
    display(Head);
    cout<<endl;
    insert(Head,4,100);
    display(Head);
    cout<<endl<<"Length of the Linked List is :"<<length(Head)<<endl;
    Delete(Head,4);
      display(Head);cout<<endl;
    return 0;
}