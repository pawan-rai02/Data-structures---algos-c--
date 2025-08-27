#include<iostream>
using namespace std;

   int main(){ 
    string s="";
    s+='a';
    s+='b';
    //cout<<s;
    int a[]={1,2,3,4,5,6};
    for(int i:a) cout<<i<<" ";
    for(int &i:a) cout<<" "<<i;
    return 0;
}