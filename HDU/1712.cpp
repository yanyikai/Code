#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,k,c[105][105],dp[105][105];
int main()
{
	while(~scanf("%d%d",&n,&m)&&(n||m))
	{
		memset(dp,0,sizeof dp);
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				scanf("%d",&c[i][j]),dp[i][j]=c[i][j];
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=m;j++)
			{
				for(k=j;k<=m;k++)
				{
					dp[i][k]=max(dp[i][k],dp[i-1][k-j]+c[i][j]);
				}
			}
		}
		printf("%d\n",dp[n][m]);
	}
	return 0;
}
