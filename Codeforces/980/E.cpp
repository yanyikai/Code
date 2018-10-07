#include<bits/stdc++.h>
#define N 1000010
using namespace std;
int n,k,siz=1,fat[N][22];
vector<int> fir[N];
bool vis[N];
void dfs(int u,int d)
{
	for(int i=1;1<<i<=d;++i)fat[u][i]=fat[fat[u][i-1]][i-1];
	for(int i:fir[u])if(i!=*fat[u])*fat[i]=u,dfs(i,d+1);
}
int fun(int u)
{
	int res=0;
	for(int i=19;~i;i--)if(!vis[fat[u][i]])
		res|=1<<i,u=fat[u][i];
	return res+1;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),
		fir[u].push_back(v),
		fir[v].push_back(u);
	dfs(n,0);*vis=vis[n]=1;
	for(int i=n-1,tmp;i;--i)if(!vis[i])
	{
		tmp=fun(i);
		if(siz+tmp>n-k)continue;
		siz+=tmp;
		for(int j=i;!vis[j];j=*fat[j])vis[j]=1;
	}
	for(int i=1;i<=n;i++)if(!vis[i])printf("%d ",i);
	return 0;
}
