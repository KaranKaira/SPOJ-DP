// SPOJ - ADAPET


#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define len(s) int(s.size())
#define pb push_back
typedef long long ll;

void solve()
{
	
	string s; cin >> s;
	int n = len(s);
	ll k; cin >> k;
	ll lps[n];
	lps[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		int j = lps[i - 1];
		while (j && s[i] != s[j]) j = lps[j - 1];
		lps[i] = j + (s[i] == s[j]);
	}

	cout << k * ll(n) - (lps[n - 1]) * (k - 1) << endl;
}

int  main()
{
	int t; cin >> t; while (t--)
		solve();




}

