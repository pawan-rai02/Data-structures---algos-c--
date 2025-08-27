#include <bits/stdc++.h>
using namespace std;

void solve(string &s, int n) {
    // Check if "..." exists
    for (int i = 0; i + 2 < n; i++) {
        if (s[i] == '.' && s[i+1] == '.' && s[i+2] == '.') {
            cout << 2 << "\n";
            return;
        }
    }

    // Otherwise, count total dots
    int count = 0;
    for (char c : s) {
        if (c == '.') count++;
    }
    cout << count << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        solve(s, n);
    }
    return 0;
}
