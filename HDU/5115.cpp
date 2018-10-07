#include<cstdio>
#include<algorithm>
#define N 205
#define inf 0x3f3f3f3f
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int a[N],b[N],dp[N][N];
int main()
{
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        int n=read();
        for(int i=1;i<=n;++i)
            a[i]=read();
        for(int i=1;i<=n;++i)
            b[i]=read();
        for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j)
        dp[i][j]=inf;
        for(int l=0;l<n;++l)
        {
            for(int i=1;i+l<=n;++i)
            {
                int j=i+l;
                for(int k=i;k<=j;++k)
                dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[k]+b[i-1]+b[j+1]);
            }
        }printf("Case #%d: %d\n",cas,dp[1][n]);
    }
    return 0;
}
