#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
char s[205];
int a[205];
int dp[205][205];
int main()
{
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        scanf("%s",s);int n=strlen(s),l=1;a[l]=1;
        for(int i=1;i<n;++i)s[i]==s[i-1]?++a[l]:a[++l]=1;
        for(int len=0;len<=l;++len)
        for(int i=1;i+len<=l;++i)
        {
            int j=i+len;
            dp[i][j]=n<<1;
            if(!len)dp[i][j]=max(1,3-a[i]);
            else
            {
                for(int k=i;k<j;++k)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                if((len-1)&1)
                {
                    dp[i][j]=min(dp[i][j],dp[i+1][j-1]+(a[i]+a[j]==2));
                    if(a[i]+a[j]<4)
                    for(int k=i+2;k<j;k+=2)
                        if(a[k]==1)
                            dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k+1][j-1]);
                }
            }
        }printf("Case #%d: %d\n",cas,dp[1][l]);
    }
    return 0;
}
