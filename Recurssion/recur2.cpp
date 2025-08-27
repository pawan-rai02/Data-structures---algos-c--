#include<iostream>
using namespace std;
int func(int n){
    static int x=0;
    if(n>0){
        x++;
        return func(n-1)+x;
    }
    else
    return 0;

}
int func2(int n){
    if(n>0){
        return func2(n-1)+n;
    }
    else
    return 0;
}

int func3(int n){
    if(n>0){
         cout<<func2(n-1)+n;

    }
    else
    return 0;
}

   int main(){ 
    int n=5;
    cout<<"recurssion through static variable :"<<func(n)<<endl;
    cout<<"normal recursssion :"<<func2(n)<<endl;
    cout<<" "<<func3(n)<<endl;
    return 0;
}