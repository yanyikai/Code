#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
#define N 5000
using namespace std;
pair<LL,LL> hole[N+5];
LL mice[N+5],sum[N+5],pre[N+5],dp[N+5][N+5],que[N+5],n,m,i,j,l,r;
int main()
{
    for(scanf("%d%d",&n,&m),i=1;i<=n;i++) scanf("%lld",&mice[i]);
    for(i=1;i<=m;i++) scanf("%lld%lld",&hole[i].first,&hole[i].second);
	sort(mice+1,mice+n+1),sort(hole+1,hole+m+1);memset(dp,inf,sizeof(dp));
	for(i=1;i<=m;i++) pre[i]=pre[i-1]+hole[i].second;
    if(pre[m]<n) return 0*puts("-1");
	for(dp[0][0]=0,i=1;i<=m;i++)
    {
        dp[i][0]=l=r=que[++r]=0;
        for(j=1;j<=pre[i]&&j<=n;j++)
        {
            dp[i][j]=dp[i-1][j];que[++r]=j;
            sum[j]=sum[j-1]+llabs(mice[j]-hole[i].first);
            while(j-que[l]>hole[i].second) l++;
            while(l<r&&dp[i-1][que[l]]-sum[que[l]]>dp[i-1][j]-sum[j]) l++;
			dp[i][j]=min(dp[i][j],sum[j]+dp[i-1][que[l]]-sum[que[l]]);
		}
	}
	printf("%lld\n",dp[m][n]);
}