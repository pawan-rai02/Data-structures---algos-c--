/*whenever we declare a variable it takes its place in stack ; 
to allocate memory in heap we have to dynamically allocate it;
malloc--->p=(int*)malloc(x*sizeof(int))  for C
for C++--->>p=new int[x]   x=number of items
*/
#include<iostream>
using namespace std;

   int main(){ 
    int *p;
    p=new int[5];
    p[0]=23;p[1]=32;p[2]=54;p[3]=544;p[4]=7;
    for(int i=0;i<5;i++){
    cout<<p[i]<<endl;
    }
    delete[] p;
    return 0;
}