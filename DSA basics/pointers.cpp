 // POINTERS//   
/*use of pointers 
1- accessing heaps
2- accessing resources
3- parameter passing
whenever we declare a variable it takes its place in stack ; 
to allocate memory in heap we have to dynamically allocate it;
malloc--->p=(int*)malloc(x*sizeof(int))  for C
for C++--->>p=new int[x]   x=number of items
*/
#include<iostream>
using namespace std;

   int main(){ 
    int a=10;
    int *p=&a;//stores address of a;
    //int *p;
    //p=&a; also valid
    cout<<a<<endl;//prints 10;
    cout<<p<<endl;//prints location of variable P;
    cout<<*p<<endl;//prints 10;

    int arr[5]={2, 4, 5, 64, 4};
    int *x=arr;
    //x=&arr; WRONG SYNTAX
    cout<<"array location :"<<x<<endl;
    cout<<"array first element:"<<*x<<endl;
    for(int i=0;i<5;i++){
        cout<<x[i]<<endl;
    }
    
    return 0;
}