#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &vec, int n, unordered_map<int, int> &mp)
{
	// Implementation of the solution goes here
	if (mp.size() <= 2 && (n % 2 == 0 || n == 3))
	{
		cout << "Yes\n";
		return;
	}
	else
	{
		cout << "No\n";
		return;
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
		int n;
		cin >> n;
		vector<int> vec(n);
		unordered_map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			cin >> vec[i];
			mp[vec[i]]++;
		}

		solve(vec, n, mp);
	}
	return 0;
}
