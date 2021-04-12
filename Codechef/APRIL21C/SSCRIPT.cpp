//Problem - https://www.codechef.com/APRIL21C/problems/SSCRIPT

#include<iostream>
using namespace std;

void solve(int N, int K, string str){
	int temp_count = 0, count = 0;
	for(int i = 0; i<str.length(); i++){
		if(str[i] == '*'){
			temp_count +=1;
			if(temp_count > count) count = temp_count;
		}
		else temp_count = 0;
	}
	if(count >= K) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		int N, K;
		cin>>N>>K;
		string str;
		cin>>str;
		solve(N,K,str);
	}
}