#include<iostream>
using namespace std;
// int fibbo(int n){
//   if (n<2){
//     return n;
//   }else 
//     return fibbo(n-2)+fibbo(n-1);}
int F[10];
int fibbo(int n){
    if (n<=1){
        F[n]=n;
        return n;
    }
    else{
     if(F[n-2]==-1)
    {F[n-2]=fibbo(n-2);}
    if (F[n-1]==-1){
    F[n-1]=fibbo(n-1);}
    return F[n-2]+F[n-1];
    }
}

   int main(){ 
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        /* code */
        F[i]=-1;
    }
    
   cout<<fibbo(n); 
return 0;
}