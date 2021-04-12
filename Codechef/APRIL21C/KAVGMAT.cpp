//Problem - https://www.codechef.com/APRIL21C/problems/KAVGMAT

#include <bits/stdc++.h>
#define ll long long int
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,x,y) for(long long i = x; i < y; i++)
#define endl "\n"

using namespace std;


int main() {
	fastIO;
	ll t; 
	cin >> t;
	while(t--) {
		ll n, m, k, ans = 0;
		cin >> n >> m >> k;
		vector<vector<ll>> mat(n , vector<ll> (m, 0));
		fo(i, 0, n) fo(j, 0, m) {
			cin >> mat[i][j];
			if(mat[i][j] >= k) ans++;
		}
		if(!ans) {
			cout << 0 << endl;
			continue;
		}

		vector<vector<ll>> pref(n , vector<ll> (m, 0));
		
		pref[0][0] = mat[0][0];
		for (int i = 1; i < m; i++) 
			pref[0][i] = pref[0][i - 1] + mat[0][i];
		for (int i = 1; i < n; i++) 
			pref[i][0] = pref[i - 1][0] + mat[i][0];
		
		for (int i = 1; i < n; i++) 
			for (int j = 1; j < m; j++) 
				pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + mat[i][j];

			fo(ord, 2, min(n,m)+1) {
				fo(i, ord-1, n) {
					fo(j, ord-1, m) {
						ll tmp = pref[i][j];
						if(i-ord>=0) tmp -= pref[i-ord][j];
						if(j-ord>=0) tmp -= pref[i][j-ord];
						if(j-ord>=0 and i-ord>=0) tmp += pref[i-ord][j-ord];
						if(tmp >= k*ord*ord) ans++;
					}
				}
			}
			cout << ans << endl;
		}
		return 0;
	}