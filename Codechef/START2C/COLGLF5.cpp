//Problem - https://www.codechef.com/START2C/problems/COLGLF5

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ll test;
	cin >> test;

	while (test--) {
		ll n, m, flag = 1, count = 0, temp;
		cin >> n >> m;
		map < ll, ll > m1;
		vector < ll > v;
		
		for (ll i = 0; i < n; i++) {
			cin >> temp;
			m1[temp]++;
			v.push_back(temp);
		}

		for (ll i = 0; i < m; i++) {
			cin >> temp;
			m1[temp] =0 ;
			v.push_back(temp);
		}

		sort(v.begin(), v.end());
		for (auto i: v) {
			if (m1[i] != flag) {
				if (flag == 1) {
					flag = 0;
				} else {
					flag = 1;
				}
				count++;

			}

		}
		cout << count << endl;
	}
}
