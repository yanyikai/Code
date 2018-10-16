#include<cstdio>
#include<vector>
#include<algorithm>
#define N 100005
#define int long long
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int val[N],fat[N],sum[N],dep[N],dfn[N],pos[N],siz[N],son[N],top[N],q[N],s[N],w[N],tim,n,Q;
vector<int>fir[N];
void dfs(int u){
    dep[u]=dep[fat[u]]+(siz[u]=1);
    for(int v:fir[u])if(v!=fat[u]){
        val[v]+=val[u];
        fat[v]=u,dfs(v),siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])son[u]=v;
    }
}
void DFS(int u){
    pos[dfn[u]=++tim]=u;
    if(son[u])top[son[u]]=top[u],DFS(son[u]);
    for(int v:fir[u])if(v!=fat[u]&&v!=son[u])
    DFS(top[v]=v);
}
int LCA(int x,int y){
    for(;top[x]^top[y];x=fat[top[x]])
        if(dep[top[x]]<dep[top[y]])x^=y^=x^=y;
    return dep[x]>dep[y]?y:x;
}
void Ins(int x,int v){for(;x<=n;x+=x&-x)sum[x]+=v;}
int Fin(int x,int res=0){
    for(;x;x-=x&-x)res+=sum[x];
    return res;
}
signed main()
{
    n=read(),Q=read();char S[3];
    for(int i=1;i<=n;++i)w[i]=val[i]=read();
    for(int i=1,u,v;i<n;++i)
        u=read(),v=read(),
        fir[u].push_back(v),
        fir[v].push_back(u);
    dfs(1);DFS(top[1]=1);
    for(int i=1;i<=n;++i)
        Ins(i,val[pos[i]]-val[pos[i-1]]);
    for(int cas=0;cas<Q;++cas)
    {
        scanf("%s",S);
        if(*S=='C')
        {
            int x=read(),v=read();
            Ins(dfn[x],v-w[x]);
            Ins(dfn[x]+siz[x],w[x]-v);
            w[x]=v;continue;
        }
        int m=0,tot=0,ans=0;
        for(int x;~scanf("%lld",&x)&&x;q[++m]=x);
        sort(q+1,q+m+1,[](int&a,int&b)->bool{return dfn[a]<dfn[b];});
        for(int i=1;i<=m;s[++tot]=q[i++])if(tot)
        {
            int lca=LCA(q[i],s[tot]);
            for(;tot&&dfn[s[tot]]>dfn[lca];--tot);
            if(!tot)ans+=Fin(dfn[s[1]])-Fin(dfn[lca]);
            if(!tot||s[tot]!=lca)s[++tot]=lca;
            ans+=Fin(dfn[q[i]])-Fin(dfn[lca]);
        }
        printf("%lld\n",ans+w[s[1]]);
    }
    return 0;
}