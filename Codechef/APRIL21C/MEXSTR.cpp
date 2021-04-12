//Problem - https://www.codechef.com/APRIL21C/problems/MEXSTR

#include <bits/stdc++.h>
#define ll long long int
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,x,y) for(long long i = x; i < y; i++)
#define endl "\n"

using namespace std;

int main() {
	fastIO;
	int t;
	cin>>t;
	constexpr int mn=(int)1e6;
	int num0[mn];
	int num1[mn];
	int dp0[mn+2];
	int dp1[mn+2];
	
	while(t--){
		string s;
		cin>>s;
		int n=s.length();
		int pos=-1;
		for(int i=0;i<n;++i)
		{
			if(s[i]=='0')
			{
				for(int j=pos+1;j<=i;++j)
					num0[j]= i;
				pos=i;
			}
		}
		for(int i=pos+1;i<=n;++i)
		{
			num0[i]=n;
		}
		if(num0[0]==n)
                cout<<"0"<<endl; //Eg- 1111

            else { pos=-1;
            	for(int i=0;i<n;++i)
            		{  if(s[i]=='1')
            	{
            		for(int j=pos+1;j<=i;++j)
            			num1[j]= i;
            		pos=i;
            	}
            }
            for(int i=pos+1;i<=n;++i)
            	num1[i]=n;

            dp0[n]=dp0[n+1]=dp1[n]=dp1[n+1]=0;

            for(int i=n-1;i>=0;--i)
            {
            	dp0[i]=dp0[i+1];
            	if(s[i]=='0' && num1[i]<n)
            	{
            		dp0[i]=max(dp0[i],dp0[num1[i]+1]+1);
            	}
            	if(s[i]=='1' && num0[i]<n)
            	{
            		dp0[i]=max(dp0[i],dp0[num0[i]+1]+1);
            	}
            	dp1[i]=dp1[i+1];
            	if(num1[i]<n)
            	{
            		dp1[i]=max(dp1[i],dp0[num1[i]+1]+1);
            	}
            }


            int x=dp1[0]+1;
            int count=num1[0]+1;
            string ans="1";
            for(int i=1;i<x;++i)
            {
            	if(count>=n)
            	{    
            		ans.push_back('0');
            		continue;
            	}
            	if(num0[count]>=n) 
            	{
            		ans.push_back('0');
            		count=num0[count]+1; 
            		continue;
            	}
            	if(dp0[num0[count]+1]<x-i-1)
            	{
            		ans.push_back('0');
            		count=num0[count]+1;
            	}
            	else
            	{    
            		ans.push_back('1');
            		count=num1[count]+1;
            	}
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}