#include<cstdio>
#include<vector>
#define N 3005
#define P pair<int,int>
#define int long long
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int n=read(),p=read(),q=read(),all,ans;
vector<int>fir[N];
int fat[N],dep[N],lca[N][N],sum[N],cnt[N];
void dfs(int u)
{
    dep[u]=dep[fat[u]]+1;
    for(int v:fir[u])if(v!=fat[u])
        fat[v]=u,dfs(v);
}
int Glca(int x,int y){
    if(lca[x][y])return lca[x][y];
    if(x==y)return lca[x][y]=x;
    if(dep[x]>dep[y])return lca[x][y]=Glca(fat[x],y);
    return lca[x][y]=Glca(x,fat[y]);
}
int dis(int x,int y){return dep[x]+dep[y]-2*dep[lca[x][y]];}
void DFS(int u)
{
    sum[u]+=sum[fat[u]];
    for(int v:fir[u])if(v!=fat[u])
        DFS(v),cnt[u]+=cnt[v];
}
signed main()
{
    for(int i=1,u,v;i<n;++i)
        u=read(),v=read(),
        fir[u].push_back(v),
        fir[v].push_back(u);
    dfs(1);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
        {
            Glca(i,j);
            if(dis(i,j)==q)
                ++all,++sum[lca[i][j]],++cnt[i],++cnt[j],cnt[lca[i][j]]-=2;
        }
    DFS(1);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(dis(i,j)==p)
                ans+=all-(sum[i]+sum[j]-sum[lca[i][j]]-sum[fat[lca[i][j]]])-cnt[lca[i][j]];
    printf("%lld\n",ans);
    return 0;
}
