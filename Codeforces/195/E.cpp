#include<bits/stdc++.h>
#define MOD 1000000007
#define N 100005
using namespace std;
int fa[N],len[N],n,m,v,x,i,j,ans;
int find(int x)
{
	if(fa[x]==x) return x;
	int t=fa[x];fa[x]=find(fa[x]);
	len[x]=(len[x]+len[t])%MOD;
	return fa[x];
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=n;i++)
		for(scanf("%d",&m);m--;)
		{
			scanf("%d%d",&v,&x);
			int t=find(v);
			ans=(ans+(len[v]+x)%MOD)%MOD;
			fa[t]=i;len[t]=(len[v]+x)%MOD;
		}
	printf("%d",(ans+MOD)%MOD);
}