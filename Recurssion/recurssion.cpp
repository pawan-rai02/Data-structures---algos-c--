#include<iostream>
using namespace std;
void rec(int x){
    if (x>0){
        rec(x-1);//step 2 to 11 ->x=(10,1)
        printf("%d",x);//step 12 to 21-> x=(1,10)....at step 12 value of x=1;
        cout<<endl;
    }
}
int factorial(int x){
    if (x<1)
    return 1;
    else 
    return x*factorial(x-1);

}
   int main(){ 
    int x=3;
    rec(x);//step 1
    cout<<"factorial of "<<x<<" is "<<factorial(x)<<endl;
    return 0;
}