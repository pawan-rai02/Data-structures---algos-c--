#include<iostream>
using namespace std;

   int main(){ 
    char a[]= "madam";
 
int i,j;
for(j=0;a[j]!='\0';j++)
{}
for(i=0,j=j-1;i<=j;i++,j--){
    if(a[i]!=a[j]){
    cout<<"not a palindrome"<<endl;
    return 0;
}
}
cout<<"palindrome stirng";
    return 0;
}