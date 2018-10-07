#include<bits/stdc++.h>
#define N 50005
using namespace std;
int dp[N][2];
string s;
set<string>ans;
int main()
{
	cin>>s;
	int n=s.size();
	for(int i=n-1;i>4;--i)
	{
		if(i+2==n)
		{
			ans.insert(s.substr(i,2));
			dp[i][0]=1;continue;
		}
		if(i+3==n)
		{
			ans.insert(s.substr(i,3));
			dp[i][1]=1;continue;
		}
		if((dp[i+2][0]&&s.substr(i,2)!=s.substr(i+2,2))||dp[i+2][1])
		{
			dp[i][0]=1;
			ans.insert(s.substr(i,2));
		}
		if((dp[i+3][1]&&s.substr(i,3)!=s.substr(i+3,3))||dp[i+3][0])
		{
			dp[i][1]=1;
			ans.insert(s.substr(i,3));
		}
	}printf("%lu\n",ans.size());
	for(auto v:ans)cout<<v<<'\n';
	return 0;
}
