#include <bits/stdc++.h>
using namespace std;


int main()
{
	
	int dp[101][100][2];
	dp[1][0][1] = 1;
	dp[1][0][0] = 1;
	for (int i = 2; i <= 100; i++)
		for (int j = 0; j < i; j++)
		{

			dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];

			if (j == 0)
				dp[i][j][1] = dp[i - 1][j][0];
			else dp[i][j][1] = dp[i - 1][j - 1][1] + dp[i - 1][j][0];


		}

	int t; cin >> t; while (t--)
	{
		int no, n, k; cin >> no >> n >> k;
		cout << no << " " << dp[n][k][0] + dp[n][k][1] << endl;
	}

}
