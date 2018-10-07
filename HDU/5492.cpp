#include<cstdio>
#include<cstring>
#include<iostream>
#define INF 0x3f3f3f3f
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int dp[35][35][1775],a[35][35];
int main()
{
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        memset(dp,63,sizeof dp);
        int n=read(),m=read(),ans=INF;
        for(int i=0;i<n;++i)for(int j=0;j<m;++j)
        a[i][j]=read();dp[0][0][a[0][0]]=a[0][0]*a[0][0];
        for(int i=0;i<n;++i)for(int j=0;j<m;++j)
        for(int k=0;k<1775;++k)if(dp[i][j][k]!=INF)
        {
            dp[i+1][j][k+a[i+1][j]]=min(dp[i+1][j][k+a[i+1][j]],dp[i][j][k]+a[i+1][j]*a[i+1][j]);
            dp[i][j+1][k+a[i][j+1]]=min(dp[i][j+1][k+a[i][j+1]],dp[i][j][k]+a[i][j+1]*a[i][j+1]);
        }
        for(int i=0;i<1775;++i)if(dp[n-1][m-1][i]!=INF)
        ans=min(ans,dp[n-1][m-1][i]*(n+m-1)-i*i);
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
