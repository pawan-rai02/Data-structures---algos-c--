#include<iostream>
using namespace std;
    struct rectangle
    {
        /* data */
        int length=20;int breadth=15;

    }r;
   int main(){ 

    cout<<r.length<<"cm"<<endl;   //accessing directly
    cout<<r.breadth<<"cm"<<endl;  //accessing directly
    rectangle *p=&r;
    p->length=39;
    p->breadth=20;
    cout<<"through pointer :"<<endl;
    cout<<p->breadth<<"cm"<<endl<<p->length<<"cm"; //accessing through pointers
   
    
    return 0;
}