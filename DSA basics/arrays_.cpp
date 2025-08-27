#include<iostream>
using namespace std;

   int main(){ 
    int a[6] = {3,5,4,99,343,5};
    
    for(int i:a){
        cout<<i<<endl;
    }
    return 0;
}