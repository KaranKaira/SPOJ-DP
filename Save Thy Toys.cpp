#include <bits/stdc++.h>
using namespace std;

int n;
ll ans(int i)
{
	if (i >= n)return 0;
	if (dp[i] != -1) return dp[i] ;
	ll &state = dp[i];

	state = a[i] + ans(i + 2);
	if (i + 1 < n)
		state = max(state, a[i] + a[i + 1] + ans(i + 4));
	if (i + 2 < n )
		state = max(state , a[i] + a[i + 1] + a[i + 2] + ans(i + 6));

	return state;

}
void  solve()
{
	cin >> n;
	read(a, n);
	memset(dp, -1, sizeof(dp));
	cout << ans(0) << endl;

}

int main()
{
	int t; cin >> t; while (t--)
		solve();

}


