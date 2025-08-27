#include<iostream>
using namespace std;

   int main(){ 
    int a=1;
    int &r=a;
    cout<<a<<endl<<r<<endl;
    cout<<"&r= :"<<&r<<endl;
    cout<<"&a= :"<<&a<<endl;
    int b=a;
    cout<<"&b= :"<<&b<<endl;
    return 0;
}