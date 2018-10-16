#include<cstdio>
#include<cstring>
#define N 105
#define M 505
#define inf 0x7f7f7f7f7f7f7f7f
#define int long long
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int a[N],v[N],vis[N][M],f[N][M],can[N][M];
void mxn(int&a,int b){a>b?a=b:0;}
signed main()
{
    memset(f,0x7f,sizeof f);
    int n=read(),k=read(),W=read();
    for(int i=1;i<=k;++i)
        a[i]=read(),v[i]=read();
    int Q=read();
    for(int i=1,x;i<=Q;++i)
        x=read(),vis[read()][x]=1;
    for(int i=1;i<=k;++i)
        for(int j=1;j<=n;++j)
            vis[i][j]+=vis[i][j-1];
    for(int i=1;i<=k;++i)
        for(int j=0;j<=n;++j)
            can[i][j]=(j+a[i]<=n&&vis[i][j+a[i]]==vis[i][j]);
    for(int i=1;i<=k;++i)f[i][0]=0;
    for(int j=0;j<n;++j)
        for(int i=1;i<=k;++i)
            for(int e=1;e<=k;++e)
                if(can[e][j])
                    mxn(f[e][j+a[e]],f[i][j]+v[e]+(i^e?W:0));
    int ans=inf;
    for(int i=1;i<=k;++i)mxn(ans,f[i][n]);
    printf("%lld\n",ans==inf?-1:ans);
    return 0;
}