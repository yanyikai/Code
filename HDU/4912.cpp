#pragma GCC diagnostic error "-std=c++11"
#include<cstdio>
#include<vector>
#include<algorithm>
#define N 100005
using namespace std;
vector<int>fir[N];
int dep[N],fat[N],siz[N],son[N],top[N],vis[N];
void dfs(int u)
{
    dep[u]=dep[fat[u]]+(siz[u]=1);
    for(int v:fir[u])if(v!=fat[u])
    {
        fat[v]=u;dfs(v);siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])son[u]=v;
    }
}
void DFS(int u)
{
    if(son[u])top[son[u]]=top[u],DFS(son[u]);
    for(int v:fir[u])if(v!=fat[u]&&v!=son[u])
    DFS(top[v]=v);
}
int lca(int u,int v){
	for(;top[u]!=top[v];)
		dep[top[u]]>dep[top[v]]?
			u=fat[top[u]]:v=fat[top[v]];
	return dep[u]<dep[v]?u:v;
}
struct P{
	int u,v,lca;
	bool operator<(const P&o)const{
		return dep[lca]>dep[o.lca];
	}
}a[N];
int cha(int u,int v,int lca)
{
	if(vis[u]||vis[v]||vis[lca])return 0;
	for(;v!=lca;v=fat[v])if(vis[v])return 0;
	for(;u!=lca;u=fat[u])if(vis[u])return 0;
	return 1;
}
void Upd(int u,int v,int lca)
{
	for(;u!=lca;u=fat[u])vis[u]=1;
	for(;v!=lca;v=fat[v])vis[v]=1;
	vis[lca]=1;
}
int main()
{
	for(int n,m;~scanf("%d%d",&n,&m);)
	{
		int ans=0;
		for(int i=1;i<=n;++i)fir[i].clear(),
			dep[i]=vis[i]=fat[i]=top[i]=son[i]=0;
		for(int i=1,u,v;i<n;++i)
			scanf("%d%d",&u,&v),
			fir[u].push_back(v),
			fir[v].push_back(u);
		dfs(1);DFS(1);
		for(int i=1,u,v;i<=m;++i)
			scanf("%d%d",&u,&v),
			a[i]=P{u,v,lca(u,v)};
		sort(a+1,a+m+1);
		for(int i=1;i<=m;++i)
			if(cha(a[i].u,a[i].v,a[i].lca))
				Upd(a[i].u,a[i].v,a[i].lca),++ans;
		printf("%d\n",ans);
	}
	return 0;
}
