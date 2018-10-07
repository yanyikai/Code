#include<bits/stdc++.h>
#define N 5000
using namespace std;
long long n,m,k,sum[N+5],dp[N+5][N+5],i,j;
int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    for(i=1;i<=n;i++) scanf("%lld",&sum[i]),sum[i]+=sum[i-1];
	for(i=1;i<=k;i++)
	{
		for(j=n-i*m;j>=0;j--)
		{
			dp[i][j]=max(dp[i][j+1],dp[i-1][j+m]+sum[j+m]-sum[j]);
		}
	}
	printf("%lld",dp[k][0]);
	return 0;
}