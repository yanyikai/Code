#include<cstdio>
#include<vector>
#include<cstring>
#define N 500005
using namespace std;
vector<int>fir[N];
int siz[N],dep[N],fat[N],dfn[N],son[N],top[N],tim;
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
	dfn[u]=++tim;
	if(son[u])top[son[u]]=top[u],DFS(son[u]);
	for(int v:fir[u])if(v!=fat[u]&&v!=son[u])
	DFS(top[v]=v);
}
#define lc o<<1
#define rc o<<1|1
#define ls l,mid,lc
#define rs mid+1,r,rc
#define mid ((l+r)>>1)
int tag[N<<2];
void PD(int o)
{
	if(~tag[o])
	{
		tag[lc]=tag[rc]=tag[o];
		tag[o]=-1;
	}
}
void Upd(int l,int r,int o,int L,int R,int v)
{
	if(L<=l&&r<=R)tag[o]=v;else
	{
		PD(o);
		if(L<=mid)Upd(ls,L,R,v);
		if(R> mid)Upd(rs,L,R,v);
	}
}
int Fin(int l,int r,int o,int p)
{
	if(l==r)return tag[o];PD(o);
	return p>mid?Fin(rs,p):Fin(ls,p);
}
int main()
{
	memset(tag,-1,sizeof tag);
	int n;scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),
		fir[u].push_back(v),
		fir[v].push_back(u);
	int q;scanf("%d",&q);
	tag[1]=0;dfs(1);DFS(top[1]=1);
	for(int i=0,o,p;i<q;++i)
	{
		scanf("%d%d",&o,&p);
		switch(o)
		{
			case 1:
				Upd(1,n,1,dfn[p],dfn[p]+siz[p]-1,1);
				break;
			case 2:
				for(;top[p];p=fat[top[p]])
					Upd(1,n,1,dfn[top[p]],dfn[p],0);
				break;
			case 3:
				printf("%d\n",Fin(1,n,1,dfn[p]));
				break;
		}
	}
	return 0;
}