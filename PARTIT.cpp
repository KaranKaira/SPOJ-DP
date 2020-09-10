#include <bits/stdc++.h>
using namespace std;

ll dp[300][300][12];

void  solve()
{
	for (int i = 1; i < 221; i++)
		dp[i][i][1] = 1;

	for (int part = 2; part < 11; part++)
		for (int sum = 1; sum <= 220; sum++)

			for (int num = 1; num < 221; num++)

				if (sum - num >= 0)
					for (int pnum = num; pnum < sum - num + 1; pnum++)
						dp[num][sum][part] += dp[pnum][sum - num][part - 1];

	int t; cin >> t; while (t--)
	{

		ll m, n, k; cin >> m >> n >> k;
		ll thisnum = 1;
		for (ll part = 1; part <= n; part++)
		{

			ll r = 0;

			for (ll num = thisnum ; num < 221; num++)
			{
				r += dp[num][m][n - part + 1];

				if (r >= k)
				{
					cout << num << " ";
					thisnum = num;

					r -= dp[num][m][n - part + 1];
					k -= r;
					m = m - num;
					break;
				}
			}



		}

		cout << endl;
	}

}


int main()
{
	
	solve();
}
