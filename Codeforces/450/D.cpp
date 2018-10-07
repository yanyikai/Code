#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1000010,M=500010,INF=1e17;

int n,m,s,sz=0,k;
int las[N],las2[N],sz2;
bool flag[N];
int ss[N],yyy[N],cnt[N],fst[N],bo[N],vis[N],wzz[M*2];

struct XY
{
	int w,to,pre;
} e[M*2],e2[M*2];
struct XX
{
	int dis,num;
} d[M*2],tmp;
struct cmp1
{
	bool operator ()(XX &a,XX &b)
	{
		return a.dis>b.dis;
	}
};
void add(int x,int y,int w)
{
	++sz;
	e[sz].to=y;
	e[sz].w=w;
	e[sz].pre=las[x];
	las[x]=sz;
}
void add2(int x,int y,int w)
{
	e2[++sz2].to=y;
	e2[sz2].w=w;
	e2[sz2].pre=las2[x];
	las2[x]=sz2;
}

priority_queue<XX,vector<XX>,cmp1> q;
void Dijkstra()
{
	int u=0;
	d[s].dis=0;
	q.push(d[s]);
	while (!q.empty())
	{
		u=q.top().num;
		q.pop();
		if (flag[u]) continue;
		flag[u]=true;
		for (int j=las[u],v; j; j=e[j].pre)
			if (d[v=e[j].to].dis>=d[u].dis+e[j].w)
				d[v].dis=d[u].dis+e[j].w,q.push(d[v]),wzz[v]=0;
		for (int i=las2[u],v; i; i=e2[i].pre)
			if (d[v=e2[i].to].dis>d[u].dis+e2[i].w)
				d[v].dis=d[u].dis+e2[i].w,q.push(d[v]),wzz[v]=1;
	}
}

main()
{
	int xx,yy,zz;
	s=1;
	scanf("%lld%lld%lld",&n,&m,&k);
	for (int i=1; i<=n; ++i) d[i].num=i,d[i].dis=INF;

	for (int i=1; i<=m; ++i) scanf("%lld%lld%lld",&xx,&yy,&zz),add(xx,yy,zz),add(yy,xx,zz);
	for (int i=1; i<=k; ++i)
	{
		scanf("%lld%lld",&ss[i],&yyy[i]);
		add2(1,ss[i],yyy[i]);
		add2(ss[i],1,yyy[i]);
	}
	Dijkstra();

	int ans=k;
	for (int i=1; i<=n; ++i) if (wzz[i]) --ans;
	printf("%lld\n",ans);
	return 0;
}