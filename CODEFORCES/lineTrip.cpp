#include <bits/stdc++.h>
using namespace std;

void solve(int n, int x, vector<int>& vec) {
    int maxGap = INT_MIN;
    
    for(int i = 1; i <= n + 1; i++){   // go through all consecutive pairs
        int gap = vec[i] - vec[i - 1];
        if(i == n + 1) gap *= 2;       // last gap counts double
        maxGap = max(maxGap, gap);
    }
    
    cout << maxGap << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> vec(n + 2);
        vec[0] = 0;        // start
        vec[n + 1] = x;    // end
        
        for(int i = 1; i <= n; i++){   // store stations from index 1
            cin >> vec[i];
        }
        
        solve(n, x, vec);
    }
    return 0;
}
