//Problem - https://www.codechef.com/APRIL21C/problems/TREEPERM

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
vector<ll> graph[1000001];
ll A[1000001],
B[1000001],
con[1000001],
a[100001],
b[100001],
par[100001],
h[100001],
vis[100001];
vector<ll> sset;
priority_queue<pair<ll,ll>> LT;
ll n,s;
ll TEMP;
void solve1(ll SUP, ll d){
	vis[SUP]++;
	h[SUP]=d;
	bool is_it=true;
	for(ll CHD:graph[SUP]){
		if(!vis[CHD]){
			par[CHD]=SUP;
			solve1(CHD,d+1);
			is_it=false;
		}
	}
	if(is_it==true)
		LT.push({d,SUP});
}
void done(){
	for(ll i=0;i<n+1;i++){
		graph[i].clear();
		a[i]=0;
		b[i]=0;
		par[i]=0;
		h[i]=0;
	}
	while(!LT.empty())
	{
		LT.pop();
	}
}
void clean(ll SUP)
{
	con[a[SUP]]=0;
	con[b[SUP]]=0;
	A[a[SUP]]=0;
	A[b[SUP]]=0;
	B[a[SUP]]=0;
	B[b[SUP]]=0;
}
int solve2(ll SUP){
	B[b[SUP]]++;
	A[a[SUP]]++;
	if(A[a[SUP]]==B[a[SUP]] && con[a[SUP]]!=0){
		con[a[SUP]]--;
		TEMP--;
	}else if(con[a[SUP]]==0){
		con[a[SUP]]++;
		TEMP++;
	}
	if(A[b[SUP]]==B[b[SUP]] && con[b[SUP]]!=0){
		con[b[SUP]]--;
		TEMP--;
	}else if(con[b[SUP]]==0){
		con[b[SUP]]++;
		TEMP++;
	}
	vis[SUP]++;
	sset.push_back(SUP);
	if(TEMP==0){
		if(vis[par[SUP]]==0 && SUP!=1)
			LT.push(make_pair(h[par[SUP]],par[SUP]));
		clean(SUP);
		return 1;
	}
	if(SUP==1){
		clean(SUP);
		return 0;
	}
	if(vis[par[SUP]]==0){
		if(solve2(par[SUP])==1){
			clean(SUP);
			return 1;
		}
	}
	clean(SUP);
	return 0;
}
int sol() {
	cin >> n >> s;
	for (ll i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for (ll i = 1; i < n + 1; i++) {
		cin >> a[i];
	}
	for (ll i = 1; i < n + 1; i++) {
		cin >> b[i];
	}
	for (ll i = 1; i < n + 1; i++) {
		vis[i] = 0;
		par[i] = 0;
		h[i] = 0;
	}
	solve1(1, 1);
	for (ll i = 1; i < n + 1; i++) {
		vis[i] = 0;
	}
	bool correct = true;
	vector<vector<ll>> sets;
	while (!LT.empty()) {
		pair<ll, ll> leaf = LT.top();
		LT.pop();
		if (vis[leaf.second] == 0) {
			TEMP = 0;
			sset.clear();
			if (solve2(leaf.second) == 0) {
				correct = false;
				break;
			} else 
			{
				sets.push_back(sset);
			}
		}
	}
	if (correct == false) {
		cout << 0 <<endl;
		return 0;
	}
	if (s == 1) {
		cout << 1 <<"\n";
		return 0;
	}
	ll a = 1;
	ll x = sets.size();
	for (ll i = 0; i < x; i++) {
		ll u = sets[i][0];
		ll l = sets[i][0];
		ll sze = sets[i].size();
		for (ll j = 1; j < sze; j++) 
		{
			if (h[sets[i][j]] > h[l])
				l = sets[i][j];
			if (h[sets[i][j]] < h[u])
				u = sets[i][j];
		}
		ll cnt = 0;
		for (ll c:graph[l]) {
			if (c != par[l])
				cnt++;
		}
		a = (a * (cnt + 1)) % mod;
	}
	cout << a <<"\n";
	return 0;
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		sol();
		done();
	}
	return 0;
}