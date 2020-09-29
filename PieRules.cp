 
// CF - https://codeforces.com/problemset/problem/859/C

#include <bits/stdc++.h>
using namespace std;


int dp[100][2];
int Cal(int idx, int turn, int a[], int n)
{
	if (idx == n  ) return 0;
	if (dp[idx][turn] != -1) return dp[idx][turn];
	int &state = dp[idx][turn];
	state = 0;
	if (turn)
		state = max(Cal(idx + 1, turn ^ 1, a, n) + a[idx] , Cal(idx + 1, turn, a, n));
	else state = min(Cal(idx + 1, turn ^ 1, a, n) , Cal(idx + 1, turn, a, n) + a[idx]);

	return state;


}
void solve()
{


	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int sum = 0;
	memset(dp, -1, sizeof(dp));

	
	for (int i : a) sum += i;
	int ans = Cal(0, 1, a, n);
	cout <<  sum - ans << " " << ans ;

}

int main()
{
	
	solve();
}

