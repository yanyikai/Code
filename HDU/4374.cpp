#pragma GCC optimize(3)
#include<cstdio>
#include<cstring>
#include<iostream>
#define M 10005
#define N 105
#define INF 0x3f3f3f3f
using namespace std;
struct P{int v,id;}que[M],*b,*e;
int sco[N][M],dp[N][M],tmp;
int i,j,k,n,m,x,t,ans,sum;
static inline void q()
{
	tmp=dp[i-1][j]-sum;
	for(;!(b>e||(*e).v>tmp);--e);
	*(++e)=(P){tmp,j};sum+=sco[i][j];
	dp[i][j]=max(dp[i][j],(*b).v+sum);
}
int main()
{
	for(;~scanf("%d%d%d%d",&n,&m,&x,&t);)
	{
		for(i=1;i<=m;++i) dp[0][i]=-INF;
		ans=-INF;dp[0][x]=0;
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=m;++j)
				scanf("%d",&sco[i][j]),dp[i][j]=-INF;
			e=que;b=e+1;sum=0;
			for(j=1;j<=m;++j){if((*b).id<j-t) ++b;q();}
			e=que;b=e+1;sum=0;
			for(j=m;j>=1;--j){if((*b).id>j+t) ++b;q();}
		}
		for(i=1;i<=m;++i) ans=max(ans,dp[n][i]);
		printf("%d\n",ans);
	}
	return 0;
}
