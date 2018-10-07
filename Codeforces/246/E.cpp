#include<bits/stdc++.h>
#define N 100005
#define P pair<int,int>
using namespace std;
int dep[N],siz[N],fat[N],son[N],ans[N],col[N],tot,top,n;
vector<int>fir[N];
vector<P>que[N];
map<string,int>m;
set<int>mer[N];
void get(int u,int p)
{
	if(p)mer[dep[u]].insert(col[u]);
	else mer[dep[u]].erase(col[u]);
	for(int v:fir[u])if(v!=top)get(v,p);
}
void dfs(int u)
{
	dep[u]=dep[fat[u]]+(siz[u]=1);
	for(int v:fir[u])
	{
		dfs(v);siz[u]+=siz[v];
		if(siz[v]>siz[son[u]])son[u]=v;
	}
}
void DFS(int u,int p)
{
	for(int v:fir[u])if(v!=son[u])DFS(v,1);
	if(son[u])DFS(son[u],0),top=son[u];
	get(u,1);top=0;for(P v:que[u])
	ans[v.first]=v.second>n?0:(int)mer[v.second].size();
	if(p)get(u,0);
}
int main()
{
	char s[40];
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i)
	{
		scanf("%s%d",s,&x);
		if(!m[s])m[s]=++tot;
		fat[i]=x;col[i]=m[s];
		fir[x].push_back(i);
	}
	for(int v:*fir)dfs(v);
	int q;scanf("%d",&q);
	for(int i=0,x,y;i<q;++i)
	{
		scanf("%d%d",&x,&y);
		que[x].push_back(P(i,y+dep[x]));
	}
	for(int v:*fir)DFS(v,1);
	for(int i=0;i<q;++i)
		printf("%d\n",ans[i]);
	return 0;
}