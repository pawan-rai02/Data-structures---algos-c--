#include<iostream>
using namespace std;

struct Rectangle
{
    /* data */
    int length,breadth;
};

void initialize(struct Rectangle *r, int l, int b){
    r->length=l;
    r->breadth=b;
}
int area(struct Rectangle r){
    return r.length*r.breadth;
}
void changeLength(struct Rectangle *r,int new_length){
    r->length= new_length;
}
   int main(){ 
    struct Rectangle r;
    int l,b;
    cout<<"enter length and breadth :";
    cin>>l>>b;
    initialize(&r,l,b);
    cout<<"area is :"<<area(r);
    int new_length;
    cout<<"enter new length :";
    cin>>new_length;
    changeLength(&r,new_length);
    cout<<"new area is :"<<area(r);
    return 0;
}