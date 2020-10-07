#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long ll;

inline void read(ll a[], int n, int which = 0)
{
	if (which)
		for (int i = 1; i <= n; i++) cin >> a[i];
	else for (int i = 0; i < n; i++) cin >> a[i];
}

void solve()
{


	int n; cin >> n;
	ll a[n];
	read(a, n);
	string s; cin >> s;
	if (len(s) >= n)
	{
		cout << na << endl;
		return ;
	}
	string t;
	t = "";
	for (int i = 0; i < n - 1; i++)
		if (a[i] == a[i + 1])
			t += 'E';
		else if (a[i] > a[i + 1])
			t += 'L';
		else t += 'G';

	string f = s + '%' + t;
	int pi[len(f)];
	pi[0] = 0;
	for (int i = 1; i < len(f); i++)
	{
		int j = pi[i - 1];
		while (j && f[i] != f[j]) j = pi[j - 1];
		pi[i] = j + (f[i] == f[j]);

		if (pi[i] == len(s)) {
			cout << ha << endl;
			return;
		}
	}

	cout << na << endl;


}

int  main()
{
	int t; cin >> t; while (t--)
		solve();

}

