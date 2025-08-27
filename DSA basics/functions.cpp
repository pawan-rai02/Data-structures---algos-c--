#include<iostream>
using namespace std;
// int add(int a, int b){
//     return a+b;
// }
//    int main(){ 
//     int a,b;
//     cout<<"enter value of a :";
//     cin>>a;
   
//     cout<<"enter bn:";
//     cin>>b;
//     cout<<"sum is :"<<add(a,b);

//     return 0;
// }

void swap(int *a, int *b){
    int temp= *a;
    *a= *b;
    *b= temp;
}
int main(){
    int a,b;
     cout<<"enter value of a :";
     cin>>a;
   
     cout<<"enter value of b:";
     cin>>b;
     cout<<"before swapping a= :"<<a<<" and b= :"<<b<<endl;
     swap(&a,&b);
     cout<<"after swapping a=:"<<a<<"  b= :"<<b<<endl;
     return 99;

}