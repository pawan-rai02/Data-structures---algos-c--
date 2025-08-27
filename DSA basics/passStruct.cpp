#include<iostream>
using namespace std;
 struct Rectangle
    {
        /* data */
        int length,breadth;
    };
int area(struct Rectangle *r){
    cout<<"h";
    cout<< r->length*(r->breadth);
};


   int main(){ 
   
    Rectangle r = {10,3};
    return 0;
    cout<<area(&r);
}