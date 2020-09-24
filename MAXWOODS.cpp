#include <bits/stdc++.h>
using namespace std;
# define fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int  dp[300][300][2];
char grid[300][300];
int n, m;
// face = 1 right else left
int CalMaxTrees(int i, int j, int face)
{
	if (i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == '#' ) return 0;
	int &state = dp[i][j][face];
	if (state != -1) return state;

	if (face)
		state = (grid[i][j] == 'T') + max(CalMaxTrees(i, j + 1, 1) , CalMaxTrees(i + 1, j, 0));
	else
		state = (grid[i][j] == 'T') + max(CalMaxTrees(i, j - 1, 0), CalMaxTrees(i + 1, j, 1));
	return state;
}
void solve()
{

	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];


	cout << CalMaxTrees(0, 0, 1) << endl;
}

int main()
{

	int t; cin >> t; while (t--)
		solve();
}

