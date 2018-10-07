#include<bits/stdc++.h>
using namespace std;
int a[30005],dp[30005][605],n,d,i,j,v,ans,num;
int main()
{
	scanf("%d%d",&n,&d);
	memset(dp,-1,sizeof(dp));
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num);
		a[num]++;
	}dp[d][300]=a[d];
	for(i=d;i<=30000;i++)
	{
		for(j=1;j<=600;j++)
		{
			if(dp[i][j]==-1) continue;v=j+d-300;
			if(i+v<=30000&&v>=1) dp[i+v][j]=max(dp[i+v][j],dp[i][j]+a[i+v]);
			if(i+v+1<=30000&&v+1>=1) dp[i+v+1][j+1]=max(dp[i+v+1][j+1],dp[i][j]+a[i+v+1]);
			if(i+v-1<=30000&&v-1>=1) dp[i+v-1][j-1]=max(dp[i+v-1][j-1],dp[i][j]+a[i+v-1]);
		}
	}
	for(i=d;i<=30000;i++) for(j=1;j<=600;j++) ans=max(ans,dp[i][j]);
	printf("%d\n",ans);
	return 0;
}