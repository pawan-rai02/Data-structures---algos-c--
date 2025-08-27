#include<iostream>
using namespace std;

   int main(){ 
    char A[]= "WELCOME";
    for (int i = 0; A[i]!='\0'; i++)
    {
        A[i]=A[i]+32;
    }
    printf("%s\n",A);
    cout<<A<<endl;

    char B[]="WeLComE";
    for (int i = 0; B[i]!='\0'; i++)
    {
        if (B[i]>=65 && B[i]<=90)
            B[i]=B[i]+32;
        else
            B[i]=B[i]-32;
            }
    cout<<B;
    
    return 0;
}