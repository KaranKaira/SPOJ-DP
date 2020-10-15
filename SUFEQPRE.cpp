
#include <bits/stdc++.h>
using namespace std;

#define len(s) int(s.size())


int n;
string s;
int c = 1;
void solve()
{

	cin >> s;
	n = len(s);
	int lps[n];
	lps[0] = 0;
	for (int i = 1; i < n; i++)
	{
		int j = lps[i - 1];
		while (j && s[i] != s[j]) j = lps[j - 1];
		lps[i] = j + (s[i] == s[j]);
	}

	int ans = 0;
	int l = lps[n - 1];
	while (l)
	{
		ans ++;
		l = lps[l - 1];
	}
	cout << "Case " << c++ << ": " << ans << endl;

}
int  main()
{

	int t; cin >> t; while (t--)
		solve();



}

