#include <bits/stdc++.h>
using namespace std;

int dp[605][605];
int wi[201], he[201];
int n;
int cal(int w, int h)
{
	if (dp[w][h] != -1) return dp[w][h];

	int res = w * h;
	int i;
	for (i = 0; i < n; i++)
	{
		if (w < wi[i] || h < he[i]) continue;

		res  = min(res, cal(w, h - he[i]) + cal(w - wi[i], he[i]));
		res  = min(res, cal(wi[i], h - he[i]) + cal(w - wi[i], h));
	}
	return dp[w][h] = res;
}
void solve()
{
	int w, h;
	cin >> w >> h;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> wi[i] >> he[i];
	}
	memset(dp, -1, sizeof(dp));

	cal(w, h);
	cout << dp[w ][h] << endl;

}


int main()
{

	int t; cin >> t; while (t--)
		solve();
}
