#include<bits/stdc++.h>
#define N 100005
using namespace std;
vector<int>fir[N],col[N];
int dis[105][N],n,m,s,k,ans[N];
void BFS(vector<int>col,int*dis)
{
	fill(dis+1,dis+n+1,-1);
	queue<int>Q;
	for(int v:col)
	{
		dis[v]=0;
		Q.push(v);
	}
	for(;!Q.empty();)
	{
		int u=Q.front();Q.pop();
		for(int v:fir[u])
			if(dis[v]==-1)dis[v]=dis[u]+1,Q.push(v);
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&s);
	for(int i=1,t;i<=n;++i)
		scanf("%d",&t),col[t].emplace_back(i);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		fir[u].emplace_back(v);
		fir[v].emplace_back(u);
	}
	for(int i=1;i<=k;++i)BFS(col[i],dis[i]);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=k;++j)
			ans[j]=dis[j][i];
		sort(ans+1,ans+k+1);
		printf("%d ",accumulate(ans+1,ans+s+1,0));
	}
	return 0;
}
