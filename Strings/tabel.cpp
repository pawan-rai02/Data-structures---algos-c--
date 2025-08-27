#include<iostream>
using namespace std;

   int main(){ 
    char h[26],a[]="finding";
    int i;
    for ( i = 0;a[i]!='\0'; i++)
    {
        h[a[i]-97]+=1;
    }
    for ( int j = 0; j < 26; j++)
    {
        if (h[j]>1)
        cout<<char(h[j]+97);
    }
    

    return 0;
}