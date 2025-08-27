#include<iostream>
using namespace std;
struct rectangle
{
    /* data */
    int length;
    double breadth;
}r2,r3,r4;



   int main(){ 
    struct rectangle r={10,10.1};
    r2={100,.1};
   struct rectangle arr[3]={{10,10.2}, {10,10.3},{10,10.4}};
    //r.length=10;
    //r.breadth=5.6;
    cout<<"area is :"<<r.length*r.breadth<<endl;
     cout<<"area is :"<<r2.length*r2.breadth<<endl;
    for (int i = 0; i < 3; i++)
    {
        /* code */
        cout<<"area is :"<<arr[i].length*arr[i].breadth<<endl;}
        cout<<sizeof(arr);
    
    
    return 0;
}