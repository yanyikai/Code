#include<cstdio>
#include<vector>
#define N 100005
using namespace std;
vector<int>fir[N];
int fat[N][20],dep[N],siz[N];
int up(int x,int del)
{
	for(int i=19;~i;--i)
		if(del>=(1<<i))x=fat[x][i],del-=1<<i;
	return x;
}
void dfs(int u,int f)
{
	dep[u]=dep[f]+(siz[u]=1);
	siz[u]=1;fat[u][0]=f;
	for(int i=1;i<20;++i)
		fat[u][i]=fat[fat[u][i-1]][i-1];
	for(int v:fir[u])if(v!=f)
		dfs(v,u),siz[u]+=siz[v];
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),
		fir[u].push_back(v),
		fir[v].push_back(u);
	dfs(1,0);int q;scanf("%d",&q);
	for(int i=0,u,v;i<q;++i)
	{
		scanf("%d%d",&u,&v);
		if(dep[u]<dep[v])u^=v^=u^=v;
		int x=u,y=v;
		if(u==v){printf("%d\n",n);continue;}
		u=up(u,dep[u]-dep[v]);
		for(int i=19;~i;--i)
			if(u!=v&&fat[u][i]!=fat[v][i])
				u=fat[u][i],v=fat[v][i];
		int k=u==v?u:fat[u][0];
		int dis=dep[x]+dep[y]-dep[k]*2;
		if(dis&1){puts("0");continue;}
		int l=up(x,dis/2);
		printf("%d\n",l==k?n-siz[up(x,dis/2-1)]-siz[up(y,dis/2-1)]:siz[l]-siz[up(x,dis/2-1)]);
	}
	return 0;
}