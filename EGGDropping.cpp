#include <bits/stdc++.h>
using namespace std;


int dp[1001][51];
int find(int n, int k)
{
	if (dp[n][k] != -1) return dp[n][k];
	if (n == 1 || n == 0 || k == 1) return n;
	int ans = INT_MAX;
	for (int j = 1; j <= n; j++)
	{
		int cur = 1 + max(find(n - j , k), find(j - 1, k - 1));
		ans = min(cur, ans) ;
	}

	return dp[n][k] = ans;
}
void  solve()
{

	int no, n, k; cin >> no >>  k >> n;

	memset(dp, -1, sizeof(dp));

	cout << no << " " << find(n, k) << endl;
 }
int main()
{
	int t; cin >> t; while (t--)
		solve();


}
