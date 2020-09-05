#include <bits/stdc++.h>
using namespace std;

void read(ll a[], int n)
{
	for (int i = 0; i < n; i++) cin >> a[i];
}

ll cal(ll a[], ll n, ll dp[])
{
	if (n == 0) return a[0];
	if (n == 1) return max(a[1], a[0]);
	if (dp[n] != -1 ) return dp[n];
	return dp[n] = max(cal(a, n - 2, dp) + a[n], cal(a, n - 1, dp));
}
int k = 1;
void  solve()
{

	int n; cin >> n;
	ll a[n];
	read(a, n);
	ll dp[n + 1];
	memset(dp, -1, sizeof(dp));
	if (n == 0) cout << "Case " << k++ << ": " << 0 << endl;
	else
		cout << "Case " << k++ << ": " << cal(a, n - 1, dp) << endl;



}


int main()
{

	int t; cin >> t; while (t--) solve();

}
