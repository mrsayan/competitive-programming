//Problem - https://www.codechef.com/MAY21B/problems/KKLING

#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pb push_back 
using namespace std;
vector<ll> mat[200008],value,childs,ans;

void dfs(ll now, ll last){ 

	for(ll i=0; i<mat[now].size(); i++){ 

		ll child= mat[now][i]; 
		if(child!=last) 
			dfs(child,now); 
	}
	childs.clear();

	for(ll i=0; i<mat[now].size(); i++){  

		ll child= mat[now][i];  
		if(child!=last)
			childs.push_back(value[child]); 
	}
	if(childs.size()>0){
		sort(childs.begin(),childs.end()); 

		ll x=childs[0];  

		ll checker=0; 

		for(ll i=0; i<childs.size(); i++){  

			if(childs[i]!= x) checker++;  

		}
		if(checker==0) value[now]+= x+1;

		if(checker!=0) value[now]+= x +2;     
	}
	else
		value[now]=0; 
}


void dfs1(ll node, ll par, ll minh){

	for(ll i=0; i<mat[node].size(); i++){  

		ll child= mat[node][i];

		minh = min(minh,value[node]);
		if(child!=par){
			if(value[child]>=minh-1){
				dfs1(child,node,minh);
			}
		}
	}
	if(value[node]==0){
		ans.push_back(node);
	}
}    





int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll t = 1; cin >> t;
	while(t--) {
		ll N; cin >> N;

		value.assign(N+1,0);

		for(ll i=0;i<N-1; i++)
		{
			int l, r;
			cin >> l >> r;
			mat[l].pb(r), mat[r].pb(l);
		}

		dfs(1,0);


		int minx = INT_MAX;

		for(ll i = 0; i<mat[1].size(); i++){
			ll child = mat[1][i];
			if(value[child]<minx){
				minx = value[child];
			}
		}

		for(ll i=0; i<mat[1].size(); i++){

			ll child = mat[1][i];
			if(value[child] == minx)

				dfs1(child,1,minx);

		}

		sort(ans.begin(), ans.end());

		cout<<ans.size()<<" "<<minx+1<<endl;

		for (ll i = 0; i <ans.size(); ++i) cout<<ans[i]<<" ";
			cout<<endl;


		for (ll i = 1; i <=N; ++i) {mat[i].clear(); }

			value.clear();
		ans.clear();

	}   
	return 0;
}