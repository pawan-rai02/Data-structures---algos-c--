#include<iostream>
using namespace std;
int sumNatural(int n){

    if (n<=0){
        return 0;
    
    }
    else
    
    return sumNatural(n-1)+n;

} 
   int main(){ 
    int n;
    cout<<"enter the number :"<<endl;
    cin>>n;
    cout<<"sum of first "<<n<<" natural numbers is :"<<sumNatural(n)<<endl;
    return 0;
}