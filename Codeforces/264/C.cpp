#include<cstdio>
#include<algorithm>
#define N 100005
#define int long long
using namespace std;
int dp[N],c[N],v[N],id1,id2,inf=1e18;
main()
{
	int n,m,a,b;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",v+i);
	for(int i=1;i<=n;++i)
		scanf("%lld",c+i);
	for(int i=0;i<m;++i)
	{
		int mxn=0,ans;id1=id2=0;
		scanf("%lld%lld",&a,&b);
		for(int j=0;j<=n;++j)dp[j]=-inf;
		for(int j=1;j<=n;++j)
		{
			int nc=c[j];
			ans=max(dp[nc]+a*v[j],b*v[j]);
			ans=max(ans,dp[nc!=id1?id1:id2]+b*v[j]);
			if(ans>dp[id1])
			{
				if(id1!=nc)id2=id1;
				id1=nc;
			}else
			if(ans>dp[id2]&&nc!=id1)id2=nc;
			dp[nc]=max(dp[nc],ans);
			mxn=max(ans,mxn);
		}
		printf("%lld\n",mxn);
	}
	return 0;
}
