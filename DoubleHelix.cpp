#include <bits/stdc++.h>
using namespace std;

void read(int a[], int n)
{
	for (int i = 0; i < n; i++) cin >> a[i];
}

void  solve()

{
	while (true) {
		int n, m; cin >> n;
		if (n == 0) return;
		int a[n];
		read(a, n);
		cin >> m;
		int b[m];
		read(b, m);

		ll ans = 0;
		ll sumA = 0, sumB = 0, i = 0, j = 0;
		while (i < n || j < m)
		{
			while (j >= m && i < n ||  i < n && a[i] < b[j]  )
				sumA += a[i++];
			while ( i >= n && j < m || j < m && a[i] > b[j]   )
				sumB += b[j++];
			if (i < n && j < m && a[i] == b[j]) {
				sumA += a[i++];
				sumB += b[j++];
				ans += max(sumA, sumB);
				sumB = sumA = 0;
			}
		}


		cout << ans + max(sumA, sumB) << endl;
	}
}


int main()
{
	
	solve();

}
