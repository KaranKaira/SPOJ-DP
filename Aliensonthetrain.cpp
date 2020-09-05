#include <bits/stdc++.h>
using namespace std;



void read(int a[], int n)
{
	for (int i = 0; i < n; i++) cin >> a[i];
}


void  solve()
{

	int n, b; cin >> n >> b;
	int a[n];
	read(a, n);


	int st = 0, end = 0;
	int cur = 0;
	int ansP = INT_MAX, stn = 0;
	while (end <= n && st <= n)
	{
		while (cur > b)
			cur -= a[st++];

		if (stn < end - st )
		{
			ansP = cur;
			stn = end - st ;
		}
		else if (stn == end - st  )
			ansP = min(ansP, cur);

		cur += a[end++];

	}

	cout << ansP << " " << stn << endl;


}


int main()
{

	int t; cin >> t; while (t--) solve();

}
