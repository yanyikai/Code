#include<cstdio>
#include<algorithm>
#define N 200005
using namespace std;
int l[N],r[N],s[N],cnt,dp[N][20],sum[N];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",l+i,r+i);
		r[i]+=l[i];
	}
	
	for(int i=n;i;--i)
	{
		// puts("-2");
		for(;cnt;--cnt)
			if(r[s[cnt]]>=r[i])break;
		int t=cnt?s[cnt]:0;
		*dp[i]=t;sum[i]=sum[t]+max(0,l[t]-r[i]);
		for(int j=1;j<20;++j)
			dp[i][j]=dp[dp[i][j-1]][j-1];
		s[++cnt]=i;
	}
	// puts("-1");
	int q;scanf("%d",&q);
	for(int k=0,x,y;k<q;++k)
	{
		scanf("%d%d",&x,&y);
		if(r[x]>=l[y]){puts("0");continue;}
		int t=x;
		for(int i=19;~i;--i)
			if(dp[t][i]&&r[dp[t][i]]<l[y])
				t=dp[t][i];
		printf("%d\n",sum[x]-sum[*dp[t]]);
	}
	return 0;
}