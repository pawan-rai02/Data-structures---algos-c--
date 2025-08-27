#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,*p;
    a=10;
    p=&a;
    cout<<*p<<"   "<<p<<"  "<<endl;cout<<++*p<<endl;

   int b[]={1, 2, 0, 4, 5};
   cout<<"address of b :"<<b<<endl<<"*b :"<<*b<<endl<<"*b+2 :"<<*(b+2);

}