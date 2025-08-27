#include<iostream>
using namespace std;
int main()
{
int a[8]={5};
int e[]={1,2,3,4,5,6};
for(int i=0;i<10;i++){
cout<<"hi"<<e[i]<<endl;
cout<<&e[i];}
for(int i=0;i<8;i++){
cout<<a[i]<<endl;
cout<<&a[i]<<endl;}
for(int i:a)
cout<<"diff method"<<i<<endl;
cout<<*(a+0)<<endl;
cout<<2[a];

int n;
cin>>n;
int arr[n];

}