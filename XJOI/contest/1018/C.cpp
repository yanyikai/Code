#include<cstdio>
#include<algorithm>
#define N 1000100
#define int long long
inline int read(){
	int x=0;char ch=getchar();
	for(;ch<48||ch>57;ch=getchar());
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int f[N][2],arr[N<<1],nxt[N<<1],cot[N<<1],fir[N],e,dep[N];
void add(int u,int v,int w){
	arr[++e]=v;nxt[e]=fir[u];fir[u]=e;cot[e]=w;
}
void dfs(int u,int fa){
	for(int i=fir[u];i;i=nxt[i]){
		int v=arr[i];
		if(v==fa)continue;
		dfs(v,u);
		dep[u]=max(dep[u],dep[v]+cot[i]);
		f[u][0]+=f[v][0]+cot[i]*2;
		f[u][1]+=min(f[v][0]+cot[i]-dep[v],f[v][1]+cot[i]*2);
	}
}
signed main()
{
	int n=read();
	for(int i=1,u,v,w;i<n;++i)
		u=read(),v=read(),w=read(),
		add(u,v,w),add(v,u,w);
	dfs(1,0);
	printf("%lld\n",min(f[1][0],f[1][1]));
	return 0;
}