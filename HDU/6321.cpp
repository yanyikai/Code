#pragma GCC optimize(3,"inline")
#include<cstdio>
#include<vector>
#define B(_) __builtin_popcount(_)
using namespace std;
vector<int>bit[6];
int dp[1124],sum[1124],res[9],p=1e9+7;
int main()
{
    int T;scanf("%d",&T);
    for(int cas=0;cas<T;++cas)
    {
        int n,m,cnt;char s[9];
        scanf("%d%d",&n,&m);
        dp[0]=1;cnt=n/2;
        for(int i=1;i<=cnt;++i)res[i]=0,bit[i].clear();
        for(int i=1;i<1<<n;++i)dp[i]=0;
        for(int i=1;i<1<<n;++i)
        {
            int x=B(i);
            if(x&1)continue;
            bit[x>>1].push_back(i);
        }
        for(int q=0,x,y;q<m;++q)
        {
            scanf("%s%d%d",s,&x,&y);
            if(x==y)continue;
            int sta=(1<<--x)|(1<<--y),f=*s=='+'?1:-1;
            for(int i=1;i<=cnt;++i)
                for(vector<int>::iterator v=bit[i].begin();v!=bit[i].end();++v)
                    if(((*v)&sta)==sta)
                    {
                        dp[*v]+=f*dp[(*v)^sta];
                        res[i]+=f*dp[(*v)^sta];
                        if(dp[*v]>=p)dp[*v]-=p;
                        if(dp[*v]<0)dp[*v]+=p;
                        if(res[i]>=p)res[i]-=p;
                        if(res[i]<0)res[i]+=p;
                    }
            for(int i=1;i<=cnt;++i)
                printf("%d%c",res[i],i==cnt?'\n':' ');
        }
    }
    return 0;
}
