#include <bits/stdc++.h>
using namespace std;


int dp[90][90];

int diri[8] = { -1, -1, 0, 1, 1, 1, 0, -1};
int dirj[8] = {0, -1, -1, -1, 0, 1, 1, 1};


int cal(string s[], int i, int j, int n, int m, char c)
{
	if ( i >= n || j >= m || i < 0 || j < 0 || s[i][j] != c) return 0;

	if (dp[i][j] != -1) return dp[i][j];
	int & state = dp[i][j];
	int ans = 0 ;
	for (int k = 0; k < 8; k++)
	{
		ans = max(ans,  cal(s, i + diri[k], j + dirj[k], n, m, char(c + 1)));
	}

	return state = ans + 1;

}

void  solve()
{
	int k = 1;
	while (true)
	{
		int n, m; cin >> n >> m;
		if (n == 0 && n == m) return;
		string s[n];
		for (int i = 0; i < n; i++)
			cin >> s[i];

		memset(dp, -1, sizeof(dp));
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (s[i][j] == 'A')
					ans = max(ans, cal(s, i, j, n, m, 'A'));

		cout << "Case " << k++ << ": " <<  ans << endl;

	}


}

int main()
{
	solve();
}
