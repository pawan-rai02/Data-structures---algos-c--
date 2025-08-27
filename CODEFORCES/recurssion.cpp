#include<iostream>
using namespace std;


void print(int num, int N){
    if(num==N) {
        cout<<N<<endl;
        return;
    }
    else{
        cout<<num<<endl;
        print(num+1,N);
    }
}


void PRINT(int n){
    if(n==1){ cout<<1<<endl; return;}
    else{
        PRINT(n-1);
        cout<<n<<"\n";
    }
}


   int main(){ 
    print(1,5);
    cout<<"hey"<<"\n";
    PRINT(7);
    return 0;
}