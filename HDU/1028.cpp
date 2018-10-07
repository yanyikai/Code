#include<bits/stdc++.h>
using namespace std;
long long dp[125][125],n;
int main()
{
	while(~scanf("%lld",&n))
	{
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j>=1;j--)
			{
				if(j>(i>>1)) dp[i][j]=1;
				else dp[i][j]+=dp[i-j][j]+dp[i][j+1];
			}
		}
		printf("%lld\n",dp[n][1]);
	}
	return 0;
}
