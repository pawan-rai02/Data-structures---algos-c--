#include<bits/stdc++.h>
using namespace std;
/*
given array A of N integers. given quries Q and in each query given L and R , 
print sum of array elements from index L to R.
constraints
1<=N<=10^5
1<=a[i]<=10^9
1<=Q<=10^5
1<=L, R<=N
*/

const int N =1e5+10;
long long a[N];
long long pf[N];
   int main(){ 
    int n;
    cin>>n;
    for (int i=1;i<n;i++) { 
        cin>>a[i];
        pf[i]=pf[i-1]+a[i];
        }

    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<pf[r]-pf[l-1]<<endl;
    
       }
          return 0;
}