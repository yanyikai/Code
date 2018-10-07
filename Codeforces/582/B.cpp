#include<bits/stdc++.h>
using namespace std;
int n,T,i,j,l,maxn,ans,dp[100005],t[100005],m[300005];
int main()
{
	scanf("%d%d",&n,&T);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t[i]);
		m[t[i]]++;
		maxn=max(maxn,m[t[i]]);
	}l=n;
	while((--T)&&l<10000) for(i=0;i<n;i++) t[l++]=t[i];
	for(i=0;i<l;i++)
	{
		dp[i]++;
		for(j=0;j<i;j++) if(t[j]<=t[i]) dp[i]=max(dp[i],dp[j]+1);
		ans=max(ans,dp[i]);
	}
	printf("%d",ans+maxn*T);
	return 0;
}