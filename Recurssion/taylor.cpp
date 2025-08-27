#include<iostream>
using namespace std;
double taylor(double x, double n){
    double static p = 1;
    double static f = 1;
    double result ;
    if (n==0)
    return 1;
    else
    {
        result=taylor(x,n-1);
        p=p*x;
        f=f*n;
        return result+(p/f);
    }
}
double taylor_2(double x, double n){
     double static res=1 ;
    if(n==0)
    return 1;
    else{
       
        res = 1+x/n*res;
        return taylor_2(x,n-1);
    }
}
   int main(){ 
    double x,n;
    cout<<"enter x :";
    cin>>x;
    cout<<endl<<"enter n :";
    cin>>n;
    cout<<"Taylor series till x="<<x<<" n="<< n<<" is :"<<taylor(x,n)<<endl;
    cout<<"Taylor through horners rule :"<<taylor_2(x,n);
    return 0;
}