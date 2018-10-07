#include<cstdio>
#include<cstring>
using namespace std;
char s[1005],t[1005];
int dp[1005][10][10];
int main()
{
    for(;~scanf("%s%s",s,t);)
    {
        memset(dp,63,sizeof dp);
        dp[0][0][0]=0;int n=strlen(s);
        for(int i=0;i<n;++i)
        for(int j=0;j<10;++j)
        for(int k=0;k<10;++k)
        if(dp[i][j][k]!=0x3f3f3f3f)
        {
            int e=(t[i]-s[i]-j+20)%10;
            for(int x=0;x<=e;++x)
            for(int y=0;y<=x;++y)
            if(dp[i][j][k]+e<dp[i+1][(k+x)%10][y])
            dp[i+1][(k+x)%10][y]=dp[i][j][k]+e;
            e=10-e;
            for(int x=0;x<=e;++x)
            for(int y=0;y<=x;++y)
            if(dp[i][j][k]+e<dp[i+1][(k-x+10)%10][(10-y)%10])
            dp[i+1][(k-x+10)%10][(10-y)%10]=dp[i][j][k]+e;
        }printf("%d\n",dp[n][0][0]);
    }
    return 0;
}
