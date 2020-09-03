#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------ CODE HERE -----------------------------------------------------------------
int a[2000];
int dp[2001][2001];
int n;




void read(int a[], int n)
{
	for (int i = 0; i < n; i++) cin >> a[i];
}

int HarryMix(int a[], int i, int j, int pre[])
{
	if (i == j) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	int ans = INT_MAX;
	for (int k = i; k < j; k++)
	{
		int t = HarryMix(a, i, k, pre) + HarryMix(a, k + 1, j, pre) + ((pre[k] - (i == 0 ? 0 : pre[i - 1])) % 100 ) * ((pre[j] - pre[k]) % 100);
		ans = min(ans, t);
	}
	return dp[i][j] = ans;
}
void solve()
{

	int n;
	while (cin >> n)
	{
		int a[n];
		read(a, n);
		int pre[n];
		pre[0] = a[0];
		for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + a[i];
		memset(dp, -1, sizeof(dp));

		cout << HarryMix(a, 0, n - 1, pre) << endl;

	}



}


int main()
{


	
	solve();
}
