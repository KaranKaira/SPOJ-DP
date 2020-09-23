//Digit DP Basic 

#include <bits/stdc++.h>
using namespace std;

ll dp[20][2][180];


ll cal(int pos, int pr, ll sum, vector<ll> &num) // if pr = 1 -> place any digit else-> there is limit
{
	if (pos >= len(num)) return sum;
	ll &state = dp[pos][pr][sum];
	if (state != -1) return state;
	ll limit = 9 ;
	if (pr == 0) limit = num[pos];
	state = 0;
	for (ll digit = 0 ; digit <= limit; digit++)
		state +=  cal(pos + 1, (pr ? 1 : (num[pos] > digit)), sum + digit, num);

	return state;

}
ll solve(ll a)
{

	if (a <= 0) return 0;
	// if (a < 10 ) return a * (a - 1) / 2;

	memset(dp, -1, sizeof(dp));
	vector<ll> num;
	// this is to change the number into vector
	while (a > 0)
	{
		num.push_back(a % 10);
		a = a / 10;
	}
	// end

	reverse(all(num));
	return cal(0, 0, 0, num);


}

int main()
{
	IO();

	int t;cin>>t;
	while (t--)
	{
		ll a, b; cin >> a >> b;
		cout << solve(b) - solve(a - 1) << endl;
	}
}

