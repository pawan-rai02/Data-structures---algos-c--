#include<iostream>
using namespace std;


int gcd(int a, int b){
    if(b==0) return a;
     gcd(b,a%b);
}


   int main(){ 
    cout<<gcd(5,10);
    return 0;
}

// #include<iostream>
// using namespace std;

// int c;
// int add_two(int a, int b){
//     c= a+b;
// }
// // int main(){

//     int a=10, b=9;
//     add_two(a, b);
//     cout<<c;


// }