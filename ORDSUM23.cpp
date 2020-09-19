#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main()
{

	int dp[1000001];
	dp[2] = dp[3] = dp[4] = 1;
	for (int i = 5; i <= 1000000; i++)
		dp[i] = (dp[i - 2] + dp[i - 3]) % mod;
	int t; cin >> t; while (t--)
	{
		int n; cin >> n;
		cout << dp[n] << endl;
	}

}


