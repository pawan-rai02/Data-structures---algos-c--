#include<iostream>
using namespace std;

void func(int n){
    if (n>0){
    cout<<n<<endl;
    func(n-1);
    func(n-1);
}}
   int main(){ 
    int i;
    cout<<"main func runs "<<i<<" th time"<<endl;
    i++;
    func(1);
    
    return 0;
}
