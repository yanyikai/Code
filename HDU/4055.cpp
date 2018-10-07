#include<cstdio>
#include<cstring>
#define int long long
#define p 1000000007
using namespace std;
char s[1005];
int dp[1005][1005];
signed main()
{
    for(;~scanf("%s",s);)
    {
        int n=strlen(s);
        dp[0][1]=1;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<i+2;++j)
            {
                dp[i][j]=dp[i][j-1];
                if(s[i-1]!='D')
                    dp[i][j]=(dp[i][j]+dp[i-1][j-1])%p;
                if(s[i-1]!='I')
                    dp[i][j]=(dp[i][j]-dp[i-1][j-1]+dp[i-1][i]+p)%p;
            }
        }printf("%lld\n",dp[n][n+1]);
    }
    return 0;
}
