#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[105][45],f[45],n,k,p=1e9+7,ans;
vector<int>fir[105];
void dfs(int u,int fa)
{
	dp[u][0]=dp[u][k+1]=1;
	for(int v:fir[u])if(v!=fa)
	{
		dfs(v,u);
		memset(f,0,sizeof f);
		for(int i=0;i<=2*k;++i)
			for(int j=0;j<=2*k;++j)
				if(i+j<=2*k)
					(f[min(i,j+1)]+=dp[u][i]*dp[v][j])%=p;
				else
					(f[max(i,j+1)]+=dp[u][i]*dp[v][j])%=p;
		for(int i=0;i<=2*k;++i)dp[u][i]=f[i];
	}
}
main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1,u,v;i<n;++i)
		scanf("%lld%lld",&u,&v),
		fir[u].push_back(v),
		fir[v].push_back(u);
	dfs(1,0);
	for(int i=0;i<=k;++i)
		(ans+=dp[1][i])%=p;
	printf("%lld\n",ans);
	return 0;
}
