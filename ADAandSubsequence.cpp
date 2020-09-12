#include <bits/stdc++.h>
using namespace std;


inline void read(int a[], int n)
{
	for (int i = 0; i < n; i++) cin >> a[i];
}



void  solve()
{
	int n, m; cin >> n >> m;
	int a[26];
	read(a, 26);
	int dp[n + 1][m + 1];
	string s, t;
	cin >> s >> t;
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (s[i - 1] == t[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + a[s[i - 1] - 'a'];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans = max(ans, dp[i][j]);
	cout << ans << endl;



}
int main()
{
	
	solve();


}


