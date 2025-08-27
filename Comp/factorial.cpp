#include<bits/stdc++.h>

using namespace std;

const int N =1e1+10;
unsigned long long fact[N];
int main(){
    fact[0]=fact[1]=1;
    for(int i=2;i<N;i++) {fact[i]=fact[i-1]*i; cout<<fact[i]<<"  ";
    }
    int n;
    cout<<"ENTER THE NUMBER :";
    cin>>n;
    cout<<"Factorial of "<<n<<" is :"<<fact[n]<<endl;

}