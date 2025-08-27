#include<iostream>
using namespace std;


struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;


void create(int A[], int n){
    struct Node *t, *last;
    int i;
    first=new Node();
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=new Node();
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;  last=t;
    }
}


void display(struct Node *p){
    cout<<endl; 
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    } cout<<endl;
}


int length(struct Node *p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }return len;
}


void Insert(struct Node *p, int pos, int x){
    Node *t =new Node();
    t->data=x;int i;
    if(pos<0||pos>length(p)) return;
    if(pos==0){
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else{
        for(i=0;i<pos-1;i++)    p=p->next;
        t->prev=p; t->next=p->next;
        if(p->next)   p->next->prev=t;
        p->next=t;
    }
}


int Delete(struct Node *p, int pos){
    //struct Node *q=new Node();
     p=first;
    int i,x=-1;
    if(pos<1 || pos>length(p)) return -1;
    if(pos==1){
        first=first->next;
        if(first) first->prev=NULL;
        x=p->data;
        delete p;
        return x;
    }
    else{
        for(i=0;i<pos-1;i++) p=p->next;
        if(p->next) p->next->prev=p->prev;
        p->prev->next=p->next;
        x=p->data;
        delete p;
        return x;
    }
}



// void reverse(struct Node *p){
//    // p=first;
//     struct Node *temp = 0;
//     while(p){
//         temp=p->next;
//         p->next=p->prev;
//         p->prev=temp;
//         p=p->prev;
//         if(p->next==0 && p!=0) first=p;
//     }
    
// }

void reverse(struct Node *p) {
    struct Node *temp = NULL;
    while (p != NULL) {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        if (p->prev == NULL) {
            first = p;  // Update first pointer when last node is reached
        }
        p = p->prev;
    }
}
int main(){ 
    int A[]={2, 6, 8, 10, 20};
    create(A,5);
    display(first);
    cout<<"Length of the Linked List is :"<<length(first)<<endl;
    Insert(first,4,1000);
    display(first);

    Delete(first, 1);
    display(first);
    
    Delete(first, 3);
    display(first);
    
    reverse(first);
    display(first);
    return 0;
}
