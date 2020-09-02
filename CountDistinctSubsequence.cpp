#include <bits/stdc++.h>
using namespace std;

int Count(string str)
{
	vector<int> pr(26, -1);
	int n = str.size();
	int dp[n + 1];
	dp[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		dp[i] = 2 * dp[i - 1] % mod;

		if (pr[str[i - 1] - 'A'] != -1)
			dp[i] = (dp[i] - dp[pr[str[i - 1] - 'A']] + mod ) % mod;
		pr[str[i - 1] - 'A'] = i - 1;

	}
	return dp[n];
}
void solve()
{

	string s; cin >> s;
	cout << Count(s) << endl;
	

}


int main()
{
	

	int t; cin >> t; while (t--)
		solve();
}
