//Problem - https://www.codechef.com/APRIL21C/problems/SDICE

#include<iostream>
using namespace std;

void solve(long long int N){
	long long D = N%4;
	long long sum = 0;

	if(N == 1) sum = (2+3+4+5+6);
	else if(N == 2) sum=2*(3+4+5+6);
	else if(N == 3) sum=2*(3+4+5+6)+4+5+6;
	else if(N >=4){
		sum+=4*(6+5)*(N/4);
		if(D == 0) sum += (4*4);
		else if(D == 1) {
			sum+=3*4;
			sum+=2+3+4+5+6; 
		}
		else if(D == 2) {
			sum += 2*4;
			sum += 2*(3+4+5+6);
		}
		else if(D == 3){
			sum += 4;
			sum += 2*(3+4+5+6)+4+5+6;
		}
	}
	cout<<sum<<endl;
}

int main(){
	int T;
	cin>>T;
	while(T--){
		long long int N;
		cin>>N;
		solve(N);
	}
}