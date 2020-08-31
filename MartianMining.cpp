#include <bits/stdc++.h>
using namespace std;
# define fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define all(v) v.begin(),v.end()
#define mod 1000000007
#define Mod 998244353
#define ha "YES"
#define na "NO"
#define sp " "
typedef long long ll;

void IO()
{
#ifndef ONLINE_JUDGE
	freopen("pracin.txt", "r", stdin);
	freopen("pracout.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	fast;
}
vector<bool> used;
vector<vector<int>> adj;
vector<int> dir[200005];
vector<int> a, b;
//bipartite graph or not using bfs

void bfs(int i)
{
	queue<int> q;
	q.push(i);
	used[i] = 1;
	a.push_back(i);
	while (!q.empty())
	{	i = q.front();
		q.pop();
		for (auto vertex : adj[i])
		{
			if (used[vertex] == -1)
			{
				used[vertex] = used[i] ^ 1;
				if (used[vertex] == 1) a.push_back(vertex);
				else b.push_back(vertex);
				q.push(vertex);
			}
			if (used[vertex] == used[i]) {
				cout << -1;
				exit(0);
			}

		}


	}
}
// binnary exponention (logn)
ll binary_exponention(ll a, ll b) {
	if (b == 0)
		return 1;
	ll res = binary_exponention(a, b / 2);
	if (b % 2)
		return res * res * a % Mod;

	return res * res % Mod;

}

// remember the question's fine details
// BE CAREFUL OF EDGE CASES....
// always check for edges cases
//  n == 1, n = size - 1, n is prime ,we



void solve()
{

	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0 && n == m) break;
		int sum[2][n][m];
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
				int s; cin >> s;
				sum[0][i][j] = s;
				if (j) sum[0][i][j] += sum[0][i][j - 1];
			}
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
				int s; cin >> s;
				sum[1][i][j] = s;
				if (i) sum[1][i][j] += sum[1][i - 1][j];
			}
		int dp[n][m];  
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				int t1 = sum[1][i][j];
				int t2 = sum[0][i][j];
				if (j) t1 += dp[i][j - 1];
				if (i) t2 += dp[i - 1][j];
				dp[i][j]  = max(t1, t2);
			}
		cout << dp[n - 1][m - 1] << endl;
	}

}



int main()
{
	IO();

	// int t; cin >> t; while (t--)
	solve();
}
