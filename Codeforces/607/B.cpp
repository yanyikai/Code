#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define N 500
using namespace std;
int dp[N+5][N+5],t[N+5],n,i,j,k;
int main()
{
    memset(dp,inf,sizeof(dp));
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&t[i]),dp[i][i]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--)
        {
            if(t[i]==t[j])
            {
                if(i==j+1)
                {
                    dp[j][i]=1;
                    continue;
                }
                dp[j][i]=min(dp[j][i],dp[j+1][i-1]);
            }
            for(int k=j;k<=i;k++) dp[j][i]=min(dp[j][i],dp[j][k]+dp[k+1][i]);
        }
    }
    printf("%d",dp[1][n]);
    return 0;
}