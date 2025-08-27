#include<iostream>

using namespace std;
/*
COMBINATION = n!/{r!(n-r)!} = C
C=[(n-1) C (r-1) + (n-1) C r]

*/

 int fact(int n){
    if (n==1||n==0)
    return 1;
    else if (n<0)
    {
        return -1;
    }
    
    else 
    return fact(n-1)*n;}
int comb(int n, int r){
    int t1= fact(n);
    int t2= fact(r);
    int t3= fact(n-r);
    return t1/(t2*t3);
    }

int comb_1(int n,int r){
    if (n==r||r==0)
    return 1;
    else 
    return comb_1(n-1,r-1)+comb_1(n-1,r);
}
   int main(){ 
    int n=10;int r =4;
    cout<<"combination (high time complx) :"<<comb(n,r)<<endl;
    cout<<"combination (low time complx) :"<<comb_1(n,r)<<endl;    
    return 0;
}