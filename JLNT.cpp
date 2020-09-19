#include <bits/stdc++.h>
using namespace std;


inline void read(int a[], int n)
{
	for (int i = 0; i < n; i++) cin >> a[i];
}
inline void write(int a[], int n)
{
	for (int i = 0; i < n; i++) cout << a[i] << " ";
}


int Case = 1;
int a[1001];
int dp[1001][5001];
int find(int i, int l, int n)
{
	if ( i >= n || l <= 0) return 0;
	if (dp[i][l] != -1) return dp[i][l];
	int &state = dp[i][l];
	state = 0;
	if (i - 1 >= 0 && a[i] - a[i - 1] <= l)
		state = 2 + find(i + 2, l - (a[i] - a[i - 1]), n);

	if (i + 1 < n && a[i + 1] - a[i] <= l)
		state = max(state , 2 + find(i + 3, l - (a[i + 1] - a[i]), n));

	state = max(state, find(i + 1, l, n));
	return state ;

}
void  solve()
{
	int n, l; cin >> n >> l;
	read(a, n);
	memset(dp, -1, sizeof(dp));
	find(0, l, n);
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= l; j++)
			ans = max(ans, dp[i][j]);
	cout << "Case " << Case++ << ": " << ans << endl;
	
}

int main()
{


	int t; cin >> t; while (t--)
		solve();

}


