#include<iostream>
using namespace std;

   int main(){ 
    char c[]= "hey";
    char a[0];
    int i,j;
    for (i = 0;c[i]!='\0'; i++)
    {
        
    }i-=1;
//     for ( j = 0; i>=0; i--,j++)
//     {
//        c[i]=a[j]; 
//     }a[j]='\0';
//     for (int i = 0; i < 3; i++)
//     {
//         /* code */cout<<a[i];
//     }
    
//     cout<<a;
    
j=0;
for(i=i;i>=j;i--,j++){
    char b;
    b=c[i];
    c[i]=c[j];
    c[j]=b;
}cout<<c;
    return 0;
 }