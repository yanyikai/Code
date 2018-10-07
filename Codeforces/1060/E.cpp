#include<cstdio>
#include<vector>
#include<algorithm>
#define N 200005
#define P pair<int,int>
#define int long long
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
vector<int>fir[N];
int ans,siz[N],dep[N],a0,a1,n=read();
void dfs(int u,int f)
{
    dep[u]=dep[f]+1;siz[u]=1;
    (dep[u]&1)?++a0:++a1;
    for(int v:fir[u])if(v!=f)
        dfs(v,u),siz[u]+=siz[v];
    ans+=siz[u]*(n-siz[u]);
}
signed main()
{
    for(int i=1;i<n;++i)
    {
        int u=read(),v=read();
        fir[u].push_back(v);
        fir[v].push_back(u);
    }
    dfs(1,0);
    printf("%lld\n",(ans+a0*a1)/2);
    return 0;
}
