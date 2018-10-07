#include<bits/stdc++.h>
#define N 105
#define M 2005
using namespace std;
struct Th
{
	int t,p,d,n;
}t[M];
int dp[M],pos,i,j,n,ans;
vector<int>  way[M];
inline bool cmp(Th x,Th y)
{
	return x.d<y.d;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d%d%d",&t[i].t,&t[i].d,&t[i].p),t[i].n=i;
	sort(t+1,t+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		for(j=t[i].d-1;j>=t[i].t;j--)
		{
			if(dp[j-t[i].t]+t[i].p>dp[j])
			{
				dp[j]=dp[j-t[i].t]+t[i].p;
				way[j]=way[j-t[i].t];
				way[j].push_back(t[i].n);
			}
		}
	}
	for(i=0;i<=M-5;i++) if(dp[i]>ans) ans=dp[i],pos=i;
	printf("%d\n%d\n",ans,way[pos].size());
	for(i=0;i<way[pos].size();i++) printf("%d ",way[pos][i]);
	return 0;
}
