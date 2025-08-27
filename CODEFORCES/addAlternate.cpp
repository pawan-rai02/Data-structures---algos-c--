#include <bits/stdc++.h>
using namespace std;
int main()
{
int test_cases,n;

cin>>test_cases;


while(test_cases--){
        int sum=0,sum_o=0,sum_e=0;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }for(int i=0;i<n;i+=2) sum_e+=arr[i];
        for (int i=1;i<n;i+=2) sum_o+=arr[i];
        sum=sum_e-sum_o;
        cout<<sum<<endl;
}  }