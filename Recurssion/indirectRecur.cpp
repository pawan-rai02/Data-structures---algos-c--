#include<iostream>
using namespace std;
void func1(int n);
void func2(int n);
void func1(int n){
    if (n>0){
        cout<<"the value of n {in FUNCTION 1} is :"<<n<<endl;
        func2(n-1);

    }

}
void func2(int n){
    cout<<"value of n {in FUNCTION 2} is :"<<n<<endl;
    func1(n/2);
}
   int main(){ 
    func1(100);
    return 0;
}