//Problem - https://www.codechef.com/MAY21B/problems/VPATH

#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define sz(a) (int)(a.size())

using namespace std;

ll ans;

vector<vector<int>> v;
vector<ll> dp, tot;

void dfs(int cur, int par)
{
	dp[cur] = 1, tot[cur] = 1;
	ll sum = 0, cnt = 0;
	for (int i = 0; i < sz(v[cur]); i++)
	{
		ll node = v[cur][i];
		if (node != par)
		{
			dfs(node, cur);
            // dp[cur] += ((2 * dp[node]) % mod), dp[cur] %= mod, cnt++, tot[cur] += tot[node], tot[cur] %= mod, tot[cur] += dp[node], tot[cur] %= mod;
			dp[cur] += ((2 * dp[node]) % mod);
			dp[cur] %= mod;
			cnt++;
			tot[cur] += tot[node];
			tot[cur] %= mod;
			tot[cur] += dp[node];
			tot[cur] %= mod;
			sum += dp[node];
		}
	}
	for (int i = 0; i < sz(v[cur]); i++)
	{
		int node = v[cur][i];
		if (node != par)
		{
			tot[cur] += (dp[node] * ((sum - dp[node] + mod) % mod)) % mod;
			tot[cur] %= mod;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		ans = 0;
		int n;
		cin >> n;
		v.resize(n + 1), dp.resize(n + 1), tot.resize(n + 1);
		for (int i = 0; i < n - 1; i++)
		{
			int l, r;
			cin >> l >> r;
			v[l].push_back(r), v[r].push_back(l);
		}
		dfs(1, 1);
		ll ans = tot[1] % mod;
		cout << ans << endl;
		dp.clear(), v.clear(), tot.clear();
	}
}