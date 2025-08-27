#include<iostream>
using namespace std;

class Rectangle
{
    /* data */
    int length,breadth;

public:
Rectangle( int l, int b){
      length=l;
   breadth=b;
}
int area(){
    // return r.length*r.breadth;
   return length*breadth;
   }
void changeLength(int new_length){
    length= new_length;
}};
   int main(){ 
    
    int l,b;
    cout<<"enter length and breadth :";
    cin>>l>>b;
    Rectangle r(l,b);
    //r.initialize(l,b);
    cout<<"area is :"<<r.area()<<endl;
    int new_length;
    cout<<"enter new length :";
    cin>>new_length;
    r.changeLength(new_length);
    cout<<"new area is :"<<r.area();
    return 0;
}