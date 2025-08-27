#include<iostream>
#include<math.h>
using namespace std;


struct Node {
    int coeff,exp;
    struct Node *next;
}*poly=nullptr;


void create(){
    struct Node *p, *last;
    int num,i;
    cout<<"Enter number of terms";
    cin>>num;
    cout<<"Enter each term (coefficent and exponent)"<<endl;
    for(i=0;i<num;i++){
        p=new Node;
        cin>>p->coeff>>p->exp;
        p->next=0;
        if(!poly) poly=last=p;
        else {
            last->next=p;
            last=p;

        }
    }
}



void display(struct Node *p){
    if (p == nullptr) {
        cout << "Polynomial is empty." << endl;
        return;
    }
    
    while (p) {
        cout << p->coeff << "x^" << p->exp; // Changed to x^exp for clarity
        p = p->next;
        if (p) cout << " + "; // Add plus if not at the end
    }
    cout << endl;
}


long Eval(struct Node *p, int x){
    long value=0;
    while(p){
        value += p->coeff*pow(x,p->exp);
        p=p->next;
    } return value;
}


   int main(){ 
    create();
    display(poly);
    cout<<"Result of polynomial is :"<<Eval(poly, 10)<<endl;
    return 0;
}