#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------ CODE HERE -----------------------------------------------------------------
int a[2000];
int dp[2001][2001];
int n;




void read(int a[], int n)
{
	for (int i = 0; i < n; i++) cin >> a[i];
}
int Ends(int a[], int st, int end)
{
	if (st == end) return a[st];
	if (st > end) return 0;
	if (dp[st][end] != -1) return dp[st][end];

	int l, r;

	if (a[st + 1] >= a[end])                          // this if else is : If our P1(the one follows optimal ) chooses 'st'  . Then, his choice affects the second Player options/
                                                    // choices
		l = a[st] + Ends(a, st + 2, end);
	else
		l = a[st] + Ends(a, st + 1, end - 1);

	                                                    // this if else is : If our P1(the one follows optimal ) chooses 'end'  . Then, his choice affects the second Player options/
  if (a[st] >= a[end - 1])                               // choices                       
		r = a[end] + Ends(a, st + 1, end - 1);                  
	else
		r = a[end] + Ends(a, st, end - 2);

	dp[st][end] = max(l, r);

	return dp[st][end];
}
void solve()
{

	int n;
	int k = 1;
	while (cin >> n)
	{
		if (n == 0) break;
		int a[n];
		read(a, n);
		memset(dp, -1, sizeof(dp));

		int sum = 0;
		for (int i : a ) sum += i;


		cout << "In game " << k++ << ", the greedy strategy might lose by as many as "
		     <<  2 * Ends(a, 0, n - 1) - sum << " points." << endl; // ans is (optimal sum ) - (total sum - optimal sum);
         
         
         



	}



}


int main()
{
	IO();

	// int t; cin >> t; while (t--)
	solve();
}
