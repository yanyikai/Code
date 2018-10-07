#include<bits/stdc++.h>
#define N 40005
using namespace std;
struct P{int v,w;};
vector<P> head[N];
int fa[N],dep[N],faw[N];
int a,b,c,T,n,m,i,l,r,ans;
void dfs(int now,int fat)
{
	fa[now]=fat;dep[now]=dep[fat]+1;
	for(auto v:head[now])
		if(v.v!=fat)
			faw[v.v]=v.w,dfs(v.v,now);
}
int main()
{
	scanf("%d",&T);
	for(int cas=1;cas<=T;++cas)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<n;++i)
		{
			scanf("%d%d%d",&a,&b,&c);
			head[a].emplace_back((P){b,c});
			head[b].emplace_back((P){a,c});
		}
		dfs(1,0);
		for(i=1;i<=m;++i)
		{
			ans=0;
			scanf("%d%d",&l,&r);
			for(;l!=r;)
			if(dep[l]<dep[r]) ans+=faw[r],r=fa[r];
			else ans+=faw[l],l=fa[l];
			printf("%d\n",ans);
		}
	}
	return 0;
}
