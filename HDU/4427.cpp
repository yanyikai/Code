#include<cstdio>
#include<cstring>
#define p 1000000007
#define int long long
using namespace std;
int fac[100],dp[2][1005][1005],lcm[1005][1005];
int gcd(int a,int b){return b?gcd(b,a%b):a;}
signed main()
{
    for(int i=1;i<1001;++i)
    for(int j=1;j<1001;++j)
    lcm[i][j]=i*j/gcd(i,j);
    for(int n,m,k;~scanf("%lld%lld%lld",&n,&m,&k);)
    {
        int tot=-1;memset(dp,0,sizeof dp);
        for(int i=1;i<=m;++i)if(m%i==0)fac[++tot]=i;++tot;
        for(int i=0;i<tot;++i)dp[1][fac[i]][fac[i]]=1;
        for(int l=1;l<k;++l)
        {
            for(int i=l;i<=n;++i)
            for(int j=0;j<tot;++j)
            dp[(l&1)^1][i][fac[j]]=0;
            for(int i=l;i<=n;++i)
            for(int j=0;j<tot;++j)
            if(dp[l&1][i][fac[j]])
            for(int e=0;e<tot&&i+fac[e]<=n;++e)
            (dp[(l&1)^1][i+fac[e]][lcm[fac[j]][fac[e]]]+=dp[l&1][i][fac[j]])%=p;
        }printf("%lld\n",dp[k&1][n][m]);
    }
    return 0;
}
