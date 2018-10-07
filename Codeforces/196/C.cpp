#pragma GCC optimize(3,"inline,Ofast")
#include<cstdio>
#include<vector>
#include<algorithm>
#define N 1505
using namespace std;
int siz[N],ans[N],X,Y,n;
bool vis[N];
vector<int>fir[N];
struct P{
	int x,y,d;
	bool operator<(const P&o)const{
		if(x-X>=0&&o.x-X<=0)return 1;
		if(x-X<=0&&o.x-X>=0)return 0;
		return 1ll*(y-Y)*(o.x-X)<1ll*(o.y-Y)*(x-X);
	}
}poi[N];
void dfs(int u,int f)
{
	siz[u]=1;
	for(int v:fir[u])if(v!=f)
		dfs(v,u),siz[u]+=siz[v];
}
void get(int l,int r,int o)
{
	vis[o]=1;
	int t=l;
	for(int i=l+1;i<=r;++i)
		if((poi[i].y<poi[t].y)||(poi[t].y==poi[i].y&&poi[i].x<poi[t].x))
			t=i;
	if(t!=l)swap(poi[l],poi[t]);
	ans[poi[l].d]=o;
	X=poi[l].x;Y=poi[l].y;
	sort(poi+l+1,poi+r+1);
	int pos=l+1;
	for(int v:fir[o])
		if(!vis[v])
		{
			get(pos,pos+siz[v]-1,v);
			pos+=siz[v];
		}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		fir[u].push_back(v);
		fir[v].push_back(u);
	}
	for(int i=1,x,y;i<=n;++i)
	{
		scanf("%d%d",&x,&y);
		poi[i]=P{x,y,i};
	}dfs(1,0);get(1,n,1);
	for(int i=1;i<=n;++i)
		printf("%d ",ans[i]);
	return 0;
}