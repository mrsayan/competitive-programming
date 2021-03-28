//Problem - https://www.codechef.com/START2C/problems/SVRT

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ll test;
	cin >> test;
	
	while(test--)
	{
		ll n,k,d=0;
		cin>>n>>k;
		if(n%k==0)
			cout<<n/k<<" "<<k<<endl;
		else
			cout<<(n/k)+1<<" "<<n%k<<endl;
	}
}