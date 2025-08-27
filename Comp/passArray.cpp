#include<bits/stdc++.h>
using namespace std;
void oned(int a[]){
    a[0]=5

;}

void twod(int b[][20]){
 b[0][0]=1000;
}

int main(){
int a[10]={};
int b[10][20]={};
cout<<"a[0]= "<<a[0]<<"\n";
a[0]=4;
cout<<"a[0]= "<<a[0]<<"\n";
oned(a);
cout<<"after function call a[0]= "<<a[0]<<"\n";
twod(b);
cout<<"two d array b[0][0]= "<<b[0][00];
}