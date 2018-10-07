#include<bits/stdc++.h>
#define N 105
#define M 200005
#define P pair<L,L>
#define L long long
#define INF 0x3f3f3f3f
using namespace std;
int dp[N][M],n,k,i,j,x,t[N],m;
int main()
{
	scanf("%d%d",&n,&k);m=n*100;
	memset(dp,0xc0,sizeof(dp));dp[0][m]=0;
	for(i=1;i<=n;i++) scanf("%d",&t[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		x=t[i]-k*x;
		for(j=m<<1;j>=0;j--) dp[i][j]=max(dp[i-1][j],dp[i-1][j-x]+t[i]);
	}
	printf("%d\n",dp[n][m]?dp[n][m]:-1);
	return 0;
}