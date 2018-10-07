#include<cstdio>
#include<vector>
#include<algorithm>
#define N 100005
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
vector<int>fir[N];
int sum[N],son[N],vis[N],a[N],w[N],q[N],ans[N],siz[N],res,n,k,m;
void DFS(int u,int f){
    siz[u]=1;
    for(int v:fir[u])if(v!=f)
    {
        DFS(v,u);siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])son[u]=v;
    }
}
void Upd(int u,int f,int val){
    if(sum[a[u]]==k)--res;
    sum[a[u]]+=val;
    if(sum[a[u]]==k)++res;
    for(int v:fir[u])if(v!=f&&!vis[v])
    Upd(v,u,val);
}
void dfs(int u,int f,int val)
{
    for(int v:fir[u])
        if(v!=f&&v!=son[u])
            dfs(v,u,0);
    if(son[u])dfs(son[u],u,1),vis[son[u]]=1;
    Upd(u,f,1);ans[u]=res;
    if(son[u])vis[son[u]]=0;
    if(!val)Upd(u,f,-1);
}
int main()
{
    for(int cas=1,T=read();cas<=T;++cas)
    {
        n=read(),k=read(),res=0;
        for(int i=1;i<=n;++i)
            fir[i].clear(),sum[i]=son[i]=vis[i]=0;
        for(int i=1;i<=n;++i)a[i]=w[i]=read();
        sort(w+1,w+n+1);m=unique(w+1,w+n+1)-w-1;
        for(int i=1;i<=n;++i)
            a[i]=lower_bound(w+1,w+m+1,a[i])-w;
        for(int i=1,u,v;i<n;++i)
            scanf("%d%d",&u,&v),
            fir[u].push_back(v),
            fir[v].push_back(u);
        int Q=read();
        for(int i=0;i<Q;++i)q[i]=read();
        DFS(1,0);dfs(1,0,0);
        printf("Case #%d:\n",cas);
        for(int i=0;i<Q;++i)
            printf("%d\n",ans[q[i]]);
        if(cas!=T)puts("");
    }
    return 0;
}
