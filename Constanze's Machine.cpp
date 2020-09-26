//codeforces
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define len(s) int(s.size())

int Cal(int i, int n, string &s, int dp[])
{
	if (i == n) return 1;
	if (dp[i] != -1) return dp[i];
	int &state = dp[i];
	if (i < n - 1 && (s[i] == 'n' || s[i] == 'u') && s[i] == s[i + 1])
		state = (Cal(i + 2, n, s, dp) + Cal(i + 1, n, s, dp)) % mod;
	else state = Cal(i + 1, n, s, dp) % mod;



	return state;
}



void solve()
{
	string s; cin >> s;
	int n = len(s);
	for (int i = 0; i < n; i++)
		if ((s[i] == 'w' || s[i] == 'm') ) {
			cout << 0;
			return;
		}
	int dp[n + 1];
	memset(dp, -1, sizeof(dp));
	cout << Cal(0, n, s, dp) ;



}

int main()
{
	IO();
	solve();

}

