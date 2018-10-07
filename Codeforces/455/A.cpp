#include<bits/stdc++.h>
using namespace std;
long long n,x,i,dp[100005][2],p;
map<long long,long long> m;
map<long long,long long>::iterator it,it_;
int main()
{
	scanf("%lld",&n);
	for(i=1;i<=n;i++) scanf("%lld",&x),m[x]++;
	it_=m.begin();
	for(it=m.begin(),i=1;it!=m.end();it++,i++)
	{
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		dp[i][1]=(it->first)*(it->second);
		it->first-it_->first==1?dp[i][1]+=dp[i-1][0]:dp[i][1]+=dp[i][0];
		it_=it;
	}
	printf("%lld",max(dp[i-1][0],dp[i-1][1]));
	return 0;
}