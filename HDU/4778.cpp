#include<bits/stdc++.h>
using namespace std;
int G,B,S,x,n,cnt;
int m[25][25],t[25],dp[1<<21],tmp[25],i,j,k;
int main()
{
    for(;~scanf("%d%d%d",&G,&B,&S)&&G&&S&&B;)
    {
        memset(m,0,sizeof m);
        for(i=0;i<B;++i)
            for(scanf("%d",&n);n--;++m[i][x])
                scanf("%d",&x);
        for(i=1;i<1<<B;++i)
        {
            dp[i]=-1e6;
            memset(t,0,sizeof t);
            for(j=0;j<B;++j)
                if(!(i&(1<<j)))
                    for(k=1;k<=G;++k)
                        t[k]+=m[j][k];
            for(j=1;j<=G;++j)
                t[j]%=S;
            for(j=0;j<B;++j)
                if(i&(1<<j))
                {
                    cnt=0;
                    for(k=1;k<=G;++k)
                    {
                        tmp[k]=t[k]+m[j][k];
                        for(;tmp[k]>=S;++cnt) tmp[k]-=S;
                    }
                    dp[i]=max(dp[i],cnt>0?cnt+dp[i^(1<<j)]:cnt-dp[i^(1<<j)]);
                }
        }
        printf("%d\n",dp[(1<<B)-1]);
    }
    return 0;
}
