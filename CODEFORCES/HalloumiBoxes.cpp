#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k, vector<int> &vec)
{
    if (k > 1 || is_sorted(vec.begin(), vec.end()))
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        solve(n, k, vec);
    }

    return 0;
}
