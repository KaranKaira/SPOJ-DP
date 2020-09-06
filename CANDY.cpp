#include <bits/stdc++.h>
using namespace std;


int cal(vector<int> &a, int n)
{
	int dp[n];
	if (n == 1) return a[0];
	if (n == 2)  return max(a[0], a[1]);
	dp[0] = a[0];
	dp[1] = max(a[0], a[1]);

	for (int i = 2; i < n; i++)
		dp[i] = max(dp[i - 1], a[i] + dp[i - 2]);
	return dp[n - 1];

}
void  solve()
{

	while (1)
	{
		int n; int m; cin >> n >> m;
		if (n == 0 && n == m) return;
		vector<vector<int>> mat(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> mat[i][j];



		vector<int> dp(n, 0);
		for (int i = 0; i < n; i++)
			dp[i] = cal(mat[i], m);


		cout << cal(dp, n) << endl;

	}


}


int main()
{
	
	solve();

}
