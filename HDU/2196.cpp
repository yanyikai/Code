#include <bits/stdc++.h>
#define N 10005
using namespace std;
struct P{int v,w;};
int n,x,y;
int dis[N];
vector<P> head[N];
vector<int> dp[N];
int dfs(int now,int father)
{
	int l=head[now].size();
	for(int it=0;it<l;++it)
	{
		P v=head[now][it];
		if(v.v!=father)
		{
			if(dp[now][it]==-1)
				dp[now][it]=v.w+dfs(v.v,now);
			dis[now]=max(dis[now], dp[now][it]);
		}
	}
	return dis[now];
}
int main()
{
	while(~scanf("%d",&n))
	{
		memset(head,0,sizeof head);
		memset(dp,0,sizeof dp);
		for(int i=2;i<=n;++i)
		{
			scanf("%d%d",&x,&y);
			head[i].emplace_back((P){x,y}); 
			dp[i].emplace_back(-1);
			head[x].emplace_back((P){i,y});
			dp[x].emplace_back(-1);
		}
		for(int i=1;i<=n;i++)
		{
			memset(dis,0,sizeof(dis));
			printf("%d\n",dfs(i,0));
		}
	}
	return 0;
}
