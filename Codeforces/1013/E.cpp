#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 5005
using namespace std;
long long dp[N][N][2],a[N];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",a+i);
	memset(dp,0x3f,sizeof dp);a[0]=a[n+1]=-1e17;
	dp[1][1][1]=dp[1][0][0]=dp[0][0][0]=0;
	for(int i=2;i<=n;++i)
	{
		dp[i][0][0]=dp[i-1][0][0];
		for(int j=1;j<=(i+1)>>1;++j)
		{
			dp[i][j][0]=min(dp[i-1][j][0],dp[i-1][j][1]+max(0ll,a[i]-a[i-1]+1));
			dp[i][j][1]=min(dp[i-2][j-1][0]+max(0ll,a[i-1]-a[i]+1),dp[i-2][j-1][1]+max(0ll,max(a[i-1]-a[i]+1,a[i-1]-a[i-2]+1)));
		}
	}
	for(int i=1;i<=(n+1)>>1;++i)
		printf("%lld ",min(dp[n][i][0],dp[n][i][1]));
	return 0;
}
