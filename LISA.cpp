	#include <bits/stdc++.h>
	using namespace std;
	
	int a[2000];
	int dp[2001][2001];
	int n;




	void read(int a[], int n)
	{
		for (int i = 0; i < n; i++) cin >> a[i];
	}

	int EvalMin(int i, int j, vector<int> &no, vector<int> &op)
	{
		if (i == j) return no[i - 1];

		if (dp[i][j] != -1) return dp[i][j] ;

		int mi = INT_MAX;

		for (int k = i; k < j; k++)
		{
			int cur;
			if (op[k - 1])
				cur = EvalMin(i, k, no, op) * EvalMin(k + 1, j, no, op);
			else cur = EvalMin(i, k, no, op) + EvalMin(k + 1, j, no, op);

			mi = min(mi, cur);
		}

		return dp[i][j] = mi;
	}
	int EvalMax(int i, int j, vector<int> &no, vector<int> &op)
	{
		if (i == j) return no[i - 1];
		if (dp[i][j] != -1) return dp[i][j];

		int ma = 0;
		for (int k = i; k < j; k++)
		{
			int cur ;
			if (op[k - 1])
				cur = EvalMax(i, k, no, op) * EvalMax(k + 1, j, no, op);
			else cur = EvalMax(i, k, no, op) + EvalMax(k + 1, j, no, op);
			ma = max(ma, cur);
		}
		return dp[i][j] = ma;
	}
	void solve()
	{

		string s; cin >> s;

		int n = s.size();

		vector<int> no, op;
		for (int i = 0; i < n; i++)
			if (i % 2) op.push_back((s[i] == '+' ? 0 : 1));
			else no.push_back((s[i] - '0'));

		memset(dp, -1, sizeof(dp));

		cout << EvalMax(1, no.size(), no, op) << " ";

		memset(dp, -1, sizeof(dp));;

		cout << EvalMin(1, no.size(), no, op) << endl;
	}


	int main()
	{
		

		int t; cin >> t; while (t--)
			solve();
	}
