#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &vec) {
    // Implementation of the solution goes here
    if(vec[0] == 1) {
        cout<< "Yes\n";
        return;
    }
    else {
        cout<< "No\n";
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<int> vec(n);
        for(int i = 0; i < n; i++){
            cin >> vec[i];
        }
        
        solve(vec);
    }
    return 0;
}
