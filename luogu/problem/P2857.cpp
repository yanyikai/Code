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
int mp[1005][25],siz[25];
inline void ADD(int u,int v,int w){
    arr[++e]=v;nxt[e]=fir[u];fir[u]=e;cap[e]=w;
    arr[++e]=u;nxt[e]=fir[v];fir[v]=e;cap[e]=0;
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
    int n=read(),b=read(),res=2e9;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=b;++j)
            scanf("%d",mp[i]+j);
    for(int i=1;i<=b;++i)scanf("%d",siz+i);
    s=n+b+1,t=n+b+2;
    for(int i=1;i<=b;++i)
        for(int j=i;j<=b;++j)
        {
            if(j-i+1>res)continue;
            e=1;memset(fir,0,sizeof fir);
            for(int p=1;p<=n;++p)
                for(int k=i;k<=j;++k)
                    ADD(p,mp[p][k]+n,1);
            for(int k=1;k<=n;++k)
                ADD(s,k,1);
            for(int k=1;k<=b;++k)
                ADD(k+n,t,siz[k]);
            int ans=0;
            for(;bfs();ans+=dfs(s,2e9))memcpy(cur,fir,sizeof fir);
            if(ans>=n)res=j-i+1/*,printf("%d %d %d\n",i,j,j-i+1)*/;
        }
    printf("%d\n",res);
    return 0;
}
