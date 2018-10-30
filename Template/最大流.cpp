#pragma GCC optimize("inline,Ofast")
#include<cstdio>
#include<cstring>
#define N 10005
#define M 200005
inline int read(){
    int x=0,f=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int n,s,t,e=1;
int fir[N],cur[N],Q[N],dep[N],arr[M],nxt[M],cap[M];
inline void ADD(int u,int v,int w){
    arr[++e]=v;nxt[e]=fir[u];fir[u]=e;cap[e]=w;
}
inline int bfs()
{
    int*be,*en;
    memset(dep,0,sizeof dep);
    for((*(be=en=Q+1)=s)[dep]=1;!(en<be);++be)
        for(int i=fir[*be];i;i=nxt[i])
        	if(cap[i]&&!i[arr][dep])
                (*(++en)=arr[i])[dep]=dep[*be]+1;
    return dep[t];
}
int dfs(int u,int mxn)
{
	if(u==t||!mxn) return mxn;
	int res=0,tmp;
	for(int &i=cur[u];i;i=nxt[i])
		if(cap[i]&&i[arr][dep]==dep[u]+1&&(tmp=dfs(arr[i],mxn>cap[i]?cap[i]:mxn)))
		{
			res+=tmp;cap[i]-=tmp;cap[i^1]+=tmp;mxn-=tmp;
			if(!mxn)return res;
		}
    if(!res)dep[u]=0;
    return res;
}
int main()
{
    //read:
    n=read();int m=read();
    s=read(),t=read();
    //get edge:
    for(int i=0;i<m;++i)
    {
        int u=read(),v=read(),w=read();
        ADD(u,v,w),ADD(v,u,0);
    }
    //Dinic:
    int ans=0;
    for(;bfs();ans+=dfs(s,2e9))memcpy(cur,fir,sizeof fir);
    //print:
    printf("%d\n",ans);
    return 0;
}