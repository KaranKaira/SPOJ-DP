#include <bits/stdc++.h>
using namespace std;


int dp[10001][10001][4];
int cal(int h, int a, int place)
{
	if (h <= 0 || a <= 0 ) return 0;
	if (dp[h][a][place] != -1) return dp[h][a][place];
	int &ans  = dp[h][a][place];
	if (place == 1)
		ans = 1 + max(cal(h - 5, a - 10, 2), cal(h - 20, a + 5, 3));
	if (place == 2)
		ans = 1 + cal(h + 3, a + 2, 1) ;
	if (place == 3)
		ans = 1 + cal(h + 3, a + 2, 1) ;
	
	return ans;
}



void  solve()
{

	int h, a; cin >> h >> a;
	memset(dp, -1, sizeof(dp));
	cout <<  cal(h + 3, a + 2, 1) << endl;

}

int main()
{	int t; cin >> t; while (t--)
		solve();
}
