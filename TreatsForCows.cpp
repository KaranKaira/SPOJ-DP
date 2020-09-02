#include <bits/stdc++.h>
using namespace std;
int a[2000];
int dp[2001][2001];
int n;

int cal(int st, int end, int day)
{
	if (st > end) return 0;
	if (dp[st][end] != -1) return dp[st][end];

	dp[st][end] = day * a[st] + cal(st + 1, end, day + 1);
	dp[st][end] = max(dp[st][end], day * a[end] + cal(st, end - 1, day + 1));

	return dp[st][end];

}
void readarr(int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void solve()
{
	cin >> n;

	readarr( n);
	map<pair<int, int>, int> m;
	memset(dp, -1, sizeof(dp));
	cal(0, n - 1, 1);
	cout << dp[0][n - 1];
}


int main()
{
	solve();
}
