/*
Given array of N integers. Given Q queries and in each query a number X,
 find the count of number X in the array
1<=N<=10^5
1<=A[I]<=10^7
1<=Q<=10^5
*/

#include<iostream>
using namespace std;

const int N = 1e7 + 10;
int hsh[N] = {}; // Hash array to count occurrences

int main() {
    int n;
    cin >> n;

    int a[n];  // Now declaring array `a` after reading `n`
    
    // Reading the array and updating the count in hash
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        hsh[a[i]]++;
    }

    int q;
    cin >> q;

    // Handling queries
    while (q--) {
        int x;
        cin >> x;
        cout << hsh[x] << endl;  // Output the count of `x`
    }

    return 0;
}
