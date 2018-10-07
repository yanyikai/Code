#include<cstdio>
#include<algorithm>
#define N 200010
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
using namespace std;
int n,cnt,x,y;
int a[N],f[N],ans[N],fat[N],arr[N<<1],nex[N<<1],fir[N];

void dfs(int u,int fa)
{
	fat[u]=fa;
	for(int i=fir[u];i;i=nex[i])
	{
		int v=arr[i];
		if(v==fa)continue;
		f[v]=__gcd(f[u], a[v]);
		dfs(v,u);
	}
}

void update(int u,int gcd)
{
	ans[u]=max(ans[u],max(gcd,f[u]));
	if(gcd==f[u])return;
	for(int i=fir[u];i;i=nex[i])
	{
		int v=arr[i];
		if (v==fat[u]) continue;
		update(v,__gcd(gcd,a[v]));
	}
}

int main()
{
	int n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1,e=0;i<n;++i)
	{
		int u=read(),v=read();
		arr[++e]=v;nex[e]=fir[u];fir[u]=e;
		arr[++e]=u;nex[e]=fir[v];fir[v]=e;
	}f[1]=a[1];dfs(1,0);
	for(int i=1;i<=n;i++)
		update(i,f[fat[i]]);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}