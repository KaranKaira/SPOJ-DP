#include <bits/stdc++.h>
using namespace std;
#typedef long long ll;

void  solve()
{

	int no, n; cin >> no >> n;
	ll dp[n + 1][10];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 0 ; j < 10; j++)
			for (int k = 0; k <= j; k++)
				dp[i][j] += dp[i - 1][k];
	ll ans = 0 ;
	for (int i = 0; i < 10; i++)
		ans += dp[n][i];
	cout << no << " " << ans << endl;
}

int main()
{
	int t; cin >> t; while (t--)
		solve();
}
