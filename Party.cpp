#include <bits/stdc++.h>
using namespace std;

void solve()
{

	int budget, n;
	while (cin >> budget >> n)
	{
		if (budget == 0 &&  n == budget) break;

		int fees[n], fun[n];
		for (int i = 0; i < n; i++)
			cin >> fees[i] >> fun[i];
		int dp[n + 1][budget + 1];
		memset(dp, 0, sizeof(dp));

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= budget; j++)
				if (fees[i - 1] <= j)
					dp[i][j] = max(fun[i - 1] + dp[i - 1][j - fees[i - 1]], dp[i - 1][j]);
				else dp[i][j] = dp[i - 1][j];




		int max_fun = 0, tot_fes = 0;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= budget; j++)
				if (dp[i][j] > max_fun)
				{
					max_fun = dp[i][j];
					tot_fes = j;
				}
				else if (dp[i][j] == max_fun )
					tot_fes = min(tot_fes, j);



		cout << tot_fes << " " << max_fun << endl;

	}

}


int main()
{
	
	solve();
}
