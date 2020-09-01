//AMR11A - Magic Grid 

#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n, m; cin >> n >> m;
	int dp[n][m], mat[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mat[i][j];

	dp[n - 1][m - 1] = mat[n - 1][m - 1] > 0 ? 1 : abs(mat[n - 1][m - 1]) + 1;
	for (int i = m - 2; i >= 0; i--)
	{
		dp[n - 1][i] = max(dp[n - 1][i + 1] - mat[n - 1][i], 1);
	}
	for (int i = n - 2; i >= 0; i--)
		dp[i][m - 1] = max(dp[i + 1
		                     ][m - 1] - mat[i][m - 1], 1);

	for (int i = n - 2; i >= 0; i--)
		for (int j = m - 2; j >= 0; j--)
		{
			int t = min(dp[i + 1][j], dp[i][j + 1]);
			dp[i][j] = max(t - mat[i][j]  , 1);
		}
	cout << dp[0][0] << endl;

}


int main()
{
	

	int t; cin >> t; while (t--)
		solve();
}
