#include<bits/stdc++.h>
#define L long long
using namespace std;
L dp[15][65][2050],l,r;
int T,b,num[65],cnt;
L dfs(int p,int mask,bool ift)
{
	if(!p) return mask?0ll:1ll;
	if(!ift&&dp[b][p][mask]!=-1) return dp[b][p][mask];
	L ans=0ll;
	for(int i=0;i<b&&!(ift&&i>num[p]);i++) ans+=dfs(p-1,mask^(1<<i),ift&&i==num[p]);
	return ift?ans:dp[b][p][mask]=ans;
}
L get(L n)
{
	L ans=0ll;
	for(cnt=0;n;n/=b) num[++cnt]=n%b;
	for(int i=1;i<=cnt;i++) for(int j=1;j<b&&!(i==cnt&&j>num[i]);j++) ans+=dfs(i-1,1<<j,i==cnt&&j==num[i]);
	return ans;
}
int main()
{
	memset(dp,-1,sizeof dp);
	for(scanf("%d",&T);T--;printf("%lld\n",get(r)-get(l-1))) scanf("%d%lld%lld",&b,&l,&r);
	return 0;
}
/*
dp[b½øÖÆ][iÎ»][mask 01´®];
*/