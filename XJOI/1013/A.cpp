#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1005
#define P pair<int,int>
#define int long long
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int sum[N],cnt[N],a[N][N],f[N][N][2];
signed main()
{
    int n=read(),m=read(),k=read(),l=k/m,del=k-l*m;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
            sum[i]+=a[i][j]=read();
        sort(a[i]+1,a[i]+m+1,[](int&a,int&b)->bool{return a>b;});
        for(int j=1;j<=del;++j)
            cnt[i]+=a[i][j];
    }
    if(k==n*m)
    {
        int ans=0;
        for(int i=1;i<=n;++i)ans+=sum[i];
        return printf("%lld\n",ans),0;
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=i;++j)
        {
            f[i][j][1]=min(f[i-1][j-1][0]+cnt[i],f[i-1][j-1][1]+sum[i]);
            f[i][j][0]=f[i-1][j-1][0]+sum[i];
            if(i>j)f[i][j][1]=min(f[i][j][1],f[i-1][j][1]);
            if(i>j)f[i][j][0]=min(f[i][j][0],f[i-1][j][0]);
        }
    printf("%lld\n",f[n][l+1][1]);
    return 0;
}
