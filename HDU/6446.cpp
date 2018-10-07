#include<cstdio>
#include<cstring>
#define int long long
inline int read(){
	int x=0,f=0;
	register char ch=getchar();
	for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
	for(;ch>47&&ch<58;ch=getchar())
	x=(x<<1)+(x<<3)+(ch^48);
	return f?~x+1:x;
}
const int p=1e9+7,N=1e5+5;
using namespace std;
int arr[N<<1],nxt[N<<1],len[N<<1],fir[N],e,n,d[N],siz[N];
inline void ADD(int u,int v,int w){
	arr[++e]=v;nxt[e]=fir[u];fir[u]=e;len[e]=w;
}
void dfs(int u,int f)
{
	d[u]=0;siz[u]=1;
	for(int i=fir[u];i;i=nxt[i])
		if(arr[i]!=f)
			dfs(arr[i],u);
	for(int i=fir[u];i;i=nxt[i])
		if(arr[i]!=f)
		{
			int v=arr[i];
			siz[u]+=siz[v];
			d[u]=(d[u]+d[v]+1ll*len[i]*siz[v]%p*(n-siz[v])%p)%p;
		}
}
signed main()
{
	for(;~scanf("%lld",&n);)
	{
		memset(fir,0,sizeof fir);e=0;
		for(int i=1,u,v,w;i<n;++i)
			u=read(),v=read(),w=read(),
			ADD(u,v,w),ADD(v,u,w);
		dfs(1,0);
		int res=2;
		for(int i=2;i<n;++i)res=res*i%p;
		printf("%lld\n",1ll*d[1]*res%p);
	}
	return 0;
}
