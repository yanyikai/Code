#include<list>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 205
using namespace std;list<int>q[N];
int a[N],o[N],e[N],fir[N],arr[N*N],nex[N*N],val[N*N],dis[N],Q[N],vis[N],E=1,s,t,las,tot;
void ADD(int u,int v,int w)
{
	arr[++E]=v;nex[E]=fir[u];fir[u]=E;val[E]=w;
	arr[++E]=u;nex[E]=fir[v];fir[v]=E;val[E]=0;
}
int bfs()
{
	memset(dis,-1,sizeof dis);
	dis[s]=0;int l=0,r=0;
	for(Q[r++]=s;l<r;)
		for(int u=Q[l++],i=fir[u];i;i=nex[i])
			if(val[i]>0&&dis[arr[i]]==-1)
				dis[arr[i]]=dis[u]+1,Q[r++]=arr[i];
	return dis[t]!=-1;
}
int dfs(int u,int mxn)
{
	if(u==t)return mxn;
	int res=0,f=0;
	for(int i=fir[u];i;i=nex[i])
		if(dis[arr[i]]==dis[u]+1&&val[i]>0&&(f=dfs(arr[i],min(val[i],mxn))))
		{
			val[i]-=f;val[i^1]+=f;mxn-=f;res+=f;
			if(!mxn)break;
		}
	if(res)return res;dis[u]=-1;return 0;
	
}
void DFS(int u,int _n,int f)
{
	vis[u]=1;f?q[_n].push_front(u):q[_n].push_back(u);
	for(int i=fir[u];i;i=nex[i])
	{
		if(arr[i]==s||arr[i]==t)continue;
		if( (i&1)&&val[i]==1&&!vis[arr[i]])DFS(arr[i],_n,f);
		if(!(i&1)&&val[i]==0&&!vis[arr[i]])DFS(arr[i],_n,u==las?!f:f);
	}
}
int cha(int x)
{
	int m=sqrt(x);
	for(int i=2;i<=m;++i)
		if(x%i==0)return 0;
	return 1;
}
int main()
{
	int n,ans=0;scanf("%d",&n);s=0,t=n+1;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		if(a[i]&1)o[++*o]=i,ADD(s,i,2);
		else e[++*e]=i,ADD(i,t,2);
	}
	if(*e!=*o)return puts("Impossible"),0;
	for(int i=1;i<=*o;++i)
		for(int j=1;j<=*e;++j)
			if(cha(a[o[i]]+a[e[j]]))
				ADD(o[i],e[j],1);
	for(;bfs();)ans+=dfs(s,0x3f3f3f3f);
	if(ans!=n)return puts("Impossible"),0;
	for(int i=1;i<=n;++i)
	{
		if(vis[i])continue;las=i;
		DFS(i,++tot,1);
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;++i,puts(""))
	{
		printf("%d ",(int)q[i].size());
		for(int v:q[i])printf("%d ",v);
	}
	return 0;
}