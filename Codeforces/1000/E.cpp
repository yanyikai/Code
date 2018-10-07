#include<bits/stdc++.h>
#define N 300005
using namespace std;
int s[N],dfn[N],low[N],pos[N],cnt,tim,nsc,ans,p;
vector<int>fir[N],hea[N];
void tarjan(int u,int fa)
{
	s[++cnt]=u;
	dfn[u]=low[u]=++tim;
	for(int v:fir[u])if(v!=fa)
	{
		if(!dfn[v])
		{
			tarjan(v,u);
			low[u]=min(low[u],low[v]);
		}else low[u]=min(low[u],dfn[v]);
	}
	if(low[u]>dfn[fa])
	{
		++nsc;
		for(;;)
		{
			int v=s[cnt--];
			pos[v]=nsc;
			if(u==v)break;
		}
	}
}
void dfs(int u,int s,int fa)
{
	if(s>ans)ans=s,p=u;
	for(int v:hea[u])
		if(v!=fa)dfs(v,s+1,u);
}
int main()
{
	int n,m;scanf("%d%d",&n,&m);
	for(int i=0,x,y;i<m;++i)
	{
		scanf("%d%d",&x,&y);
		fir[x].push_back(y);
		fir[y].push_back(x);
	}tarjan(1,0);
	for(int u=1;u<=n;++u)
		for(int v:fir[u])
			if(pos[u]!=pos[v])
				hea[pos[u]].push_back(pos[v]);
	dfs(1,0,0);dfs(p,0,0);
	printf("%d",ans);
	return 0;
}
