// Rabin Karp Algo


#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define len(s) int(s.size())
#define pb push_back
typedef long long ll;



void solve()
{

	int p = 31;
	string s, t; cin >> s >> t;
	int n = len(s), m = len(t);
	vector<ll> powp(max(n, m));
	powp[0] = 1;
	for (int i = 1; i < len(powp); i++)
		powp[i] = powp[i - 1] * p % mod;
	vector<ll> h(n + 1, 0);
	for (int i = 0; i < n; i++)
		h[i + 1] = (h[i] + (s[i] - 'a' + 1 ) * powp[i]) % mod;

	ll hp = 0;
	for (int i = 0; i < m; i++)
		hp = (hp + (t[i] - 'a' + 1 ) * powp[i]) % mod;

	vector<int> occur;
	for (int i = 0; i + m <= n; i++)
	{
		ll curh = (h[i + m] - h[i] + mod ) % mod;
		if (curh == hp * powp[i] % mod)
			occur.pb(i + 1);
	}

	if (len(occur) == 0)
	{
		cout << "Not Found" << endl << endl;
		return ;
	}
	cout << len(occur) << endl;
	for (int i : occur)
		cout << i << " ";
	cout << endl << endl;


}


int  main()
{
	
	int t; cin >> t; while (t--)
		solve();


}

