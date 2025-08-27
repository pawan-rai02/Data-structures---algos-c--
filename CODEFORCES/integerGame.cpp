#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    // Implementation of the solution goes here
    if(n % 3 == 0){
        cout<< "Second\n";
        return;
    }
    else{
        cout<< "First\n";
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
        solve(n);
    }
    return 0;
}
