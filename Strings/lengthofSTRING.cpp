#include<iostream>
using namespace std;

   int main(){ 
    char A[]={'a','b','c','d','e','\0'};
    int i;
    for ( i = 0; A[i]!='\0'; i++)
    {
        /* code */
    }
    cout<<"length of string is"<<i<<endl;
    int l = sizeof(A)/sizeof(A[0]);
    printf("length of array is :%d",l);
    for ( i = 0; i <l ; i++)
    {
        if (A[i]=='\0'){
            cout<<endl<<"length of string m2 :"<<i;
            break;
    }}
    
    return 0;
}