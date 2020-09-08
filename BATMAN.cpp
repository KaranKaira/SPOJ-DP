#include <bits/stdc++.h>
using namespace std;


void  solve()
{

	int n, m; cin >> n >> m;
	int  a[n];
	read(a, n);

	int lis[n];
	for (int i = 0; i < n; i++) lis[i] = 1;

	for (int i = 1; i < n; i++)
		for (int j = 0 ; j < i; j++)
			if ( (a[i] < a[j] || j == m) && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;

	cout << *max_element(lis, lis + n) << endl;


}

int main()
{
	
	int t; cin >> t; while (t--)
		solve();
}
