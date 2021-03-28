//Problem - https://www.codechef.com/START2C/problems/NOBEL

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0; i<n;i++)
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
	FastIO;
	ll t;
	cin >> t;
	for (ll it=0; it < t;it++)
	{
		ll n,m,c =0,chap;
		cin>> n >> m; 
		ll A[m];
		memset( A, 0, sizeof(A));
		rep(i , n)
		{
			cin >> chap;
			A[chap-1]=i+1;

		}
		rep(i,m)
		{
			if(A[i]==0)
				{ c=1;
					cout <<"Yes" << endl;
					break;
				}
			}
			if(!c) cout << "No" << endl;
		}
	}