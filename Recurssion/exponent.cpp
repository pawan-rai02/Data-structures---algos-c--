#include<iostream>
using namespace std;
// int exponent(int m,int n){
//     if (n==0)
//     return 1;
//     else if (n==1)
//     {
//         return m;
//     }
//     else
//     return exponent(m,n-1)*m;
    
// }
int pow(int m, int n){
    if (n==0)
    return 1;
     if (n%2==0)
    {
        return pow(m*m,n/2);
    }
    else
    {
        return m*pow(m*m,n-1/2);
    }
    
    
}
   int main(){ 
  //  cout<<"time complexcity high "<<exponent(5,2)<<endl;
    cout<<"low time compelxity ";
    cout<<pow(5,2)<<endl;

    return 0;
}