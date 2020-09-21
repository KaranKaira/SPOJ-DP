#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, ll> dp;
map<pair<int, int>, ll> cost;
inline void read(ll a[], int n)
{
	for (int i = 0; i < n; i++) cin >> a[i];
}
inline void write(int a[], int n)
{
	for (int i = 0; i < n; i++) cout << a[i] << " ";
}

ll a[100001];
ll find(int i, int j, int n)
{
	if (i == n) return 0;
	if (i >= j) {return 1e18;}
	if (dp.find({i, j}) != dp.end()) return dp[ {i, j}];
	ll ans = 1e18 ;
	for (int k = i + 1; k <= i + 2; k++)
	{
		ll mid = a[i + (k - i) / 2];
		ll costNow = 0;
		if (cost.find({i, k}) != cost.end()) costNow = cost[ {i, k}];
		else
		{	for (int l = i; l <= k; l++)
				costNow += abs(a[l] - mid);
			cost[ {i, k}] = costNow;
		}
		ans = min(ans, costNow + find(k + 1, j, n));
	}

	return dp[ {i, j}] = ans;
}
void  solve()
{
	
	int n; cin >> n;
	read(a, n);
	sort(a, a + n);

	cout << find(0, n - 1, n) << endl;


}

int main()
{
		solve();

}


