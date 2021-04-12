//Problem - https://www.codechef.com/APRIL21C/problems/BOLT

#include <bits/stdc++.h>
using namespace std;

void solve(float k1, float k2, float k3, float v){
	float distance = 100.00;
	float bolt_record = 9.58;

	float final_speed = k1*k2*k3*v;

	float time_elapsed = distance/final_speed;
	float time_approx = (int)(time_elapsed*100 + 0.5);
	float time = (float)(time_approx/100);

	if(time < bolt_record)  cout<<"YES"<<endl;
	else cout<<"NO"<<endl; 
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int test_cases;
	cin>>test_cases;
	while(test_cases--){
		float k1, k2, k3, v;
		cin>>k1>>k2>>k3>>v;
		solve(k1, k2, k3, v);
	}
}