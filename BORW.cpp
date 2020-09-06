#include <bits/stdc++.h>
using namespace std;

int dp[210][210][210];
int a[210], n;

void read(int a[], int n)
{
	for (int i = 1; i <= n; i++) cin >> a[i];
}
int find(int i, int inc, int dec)
{
	if (i > n) return 0;
	int & state = dp[i][inc][dec];
	if (state != -1 ) return state;
	state = INT_MAX;

	if ((!inc || a[i] > a[inc]) && (!dec || a[i] < a[dec]) )
		state = min({find(i + 1, i, dec), find(i + 1, inc, i), 1 + find(i + 1, inc, dec)});
	else if (!inc || a[i] > a[inc])
		state = min(find(i + 1, i, dec), 1 + find(i + 1, inc, dec));
	else if (!dec || a[i] < a[dec])
		state = min(find(i + 1, inc, i) , 1 + find(i + 1, inc, dec));
	else state = 1 + find(i + 1, inc, dec);

	return state;



}
void  solve()

{
	while (cin >> n)
	{
		if (n == -1) return ;
		read(a, n);
		memset(dp, -1, sizeof(dp));
		cout << find(1, 0, 0) << endl;
	}

}


int main()
{
	solve();

}
