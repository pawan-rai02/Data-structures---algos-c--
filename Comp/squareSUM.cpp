#include<bits/stdc++.h>
using namespace std;
const long long N = 1e3+10;
long long A[N][N];
 int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cin>>A[i][j];
            }

        int a,b,c,d;
        int q;
        cin>>q;
        while(q--){
        cin>>a>>b>>c>>d;
        long long sum=0;
        for(int i=a;i<=c;i++){
            for(int j=b;j<=d;j++){
                sum += A[i][j];
            }
        }cout<<sum<<endl;
        }
 }