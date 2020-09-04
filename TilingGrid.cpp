#include <bits/stdc++.h>
using namespace std;

int main()
{

	int F[1001], G[1001], H[1001];
	F[0] = F[1] = H[0] = H[1] = G[0] = 1;
	G[1] = 2;
	for (int i = 2; i <= 1000; i++)
	{
		F[i] = F[i - 1] + F[i - 2] + G[i - 2] * 2 + H[i - 2];
		G[i] = F[i] + G[i - 1];
		H[i] = F[i] + H[i - 2];

	}
	int i = 1;

	int t; cin >> t; while (t--)
	{
		int n; cin >> n;
		cout << i++ << " " << F[n] << endl;
	}
}
