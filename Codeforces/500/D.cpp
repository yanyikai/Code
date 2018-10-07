#include<cstdio>
#include<vector>
#include<algorithm>
#define N 100005
using namespace std;
vector<int>fir[N];double p[N],ans;
int dep[N],siz[N],u[N],v[N],w[N],n;
void dfs(int u,int f)
{
	dep[u]=dep[f]+(siz[u]=1);
	for(int v:fir[u])if(v!=f)
	dfs(v,u),siz[u]+=siz[v];
}
double res(int x)
{
	if(x<3)return 0;
	return 1.0*x*(x-1)*(x-2)/(1.0*n*(n-1)*(n-2));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		scanf("%d%d%d",u+i,v+i,w+i);
		fir[u[i]].push_back(v[i]);
		fir[v[i]].push_back(u[i]);
	}dfs(1,0);
	for(int i=1;i<n;++i)
	{
		if(dep[u[i]]<dep[v[i]])swap(u[i],v[i]);
		p[i]=1-res(siz[u[i]])-res(n-siz[u[i]]);
		p[i]*=2;
	}
	for(int i=1;i<n;++i)
		ans+=p[i]*w[i];
	int q;scanf("%d",&q);
	for(int i=0,x,c;i<q;++i)
	{
		scanf("%d%d",&x,&c);
		ans-=p[x]*w[x];
		w[x]=c;
		ans+=p[x]*w[x];
		printf("%.7lf\n",ans);
	}
	return 0;
}