#include<iostream>
using namespace std;
int fact(int n){
    if (n==1||n==0)
    return 1;
    else if (n<0)
    {
        /* code */return -1;
    }
    
    else 
    return fact(n-1)*n;
}
   int main(){ 
    int n;
    cout<<"enter the number :";
    cin>>n;
    int r = fact(n);
    if (r>0)
    cout<<"factorial of "<<n<<" is :"<<r<<endl;
    else
    printf("factorial cannot be calculated for negative number....haha");
    return 0;
}