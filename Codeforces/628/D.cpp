#include<bits/stdc++.h>
#define L long long
#define N 2005
using namespace std;
const int M=1e9+7;
L m,d,l,dp[N][N][3];
char a[N],b[N];
L dfs(int p,int lim,L mod)
{
	if(p==l) return mod==0;
	if(dp[p][mod][lim%3]!=-1) return dp[p][mod][lim%3];
	L beg=(lim==3||lim==0)?a[p]-48:0,end=(lim==3||lim==1)?b[p]-48:9,lim_,ans=0;
	if(p&1)
	{
		if(beg<=d&&d<=end)
		{
			if(lim==3&&beg==end) lim_=3;else
			if((lim==1||lim==3)&&end==d) lim_=1;else
			if((lim==0||lim==3)&&beg==d) lim_=0;else lim_=2;
			ans=(ans+dfs(p+1,lim_,(mod*10+d)%m))%M;
		}
	}
	else
	for(L i=beg;i<=end;i++)
	{
		if(i==d) continue;
		if(lim==3&&beg==end) lim_=3;else
		if((lim==1||lim==3)&&i==end) lim_=1;else
		if((lim==0||lim==3)&&i==beg) lim_=0;else lim_=2;
		ans=(ans+dfs(p+1,lim_,(mod*10+i)%m))%M;
	}
	return dp[p][mod][lim]=ans;
}
int main()
{
	memset(dp,-1,sizeof dp);
	scanf("%lld%lld\n%s%s",&m,&d,a,b);l=strlen(a);
	printf("%lld",dfs(0,3,0));
}