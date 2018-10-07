#include<cstdio>
#include<iostream>
#include<cstring>
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
int dis[55][55],dp[55][1<<8][1<<8],tic[55],pla[9],pay[9][2];
int main()
{
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        memset(dis,inf,sizeof dis);
        memset(dp,inf,sizeof dp);
        memset(tic,0,sizeof tic);
        int n=read(),m=read(),q=read();
        for(int i=1;i<=n;++i)dis[i][i]=0;
        for(int i=0;i<m;++i)
        {
            int x=read(),y=read(),w=read();
            dis[x][y]=dis[y][x]=w;
        }for(int i=0;i<q;++i)
        {
            pla[i]=read();pay[i][0]=read();pay[i][1]=read();
            int nf=read();
            for(int j=0;j<nf;++j)
                tic[read()]|=1<<i;
        }for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)if(i!=k)
        for(int j=1;j<=n;++j)if(j!=i&&j!=k)
        if(dis[i][k]+dis[k][j]<dis[i][j])
        dis[i][j]=dis[i][k]+dis[k][j];
        int ans=inf;dp[1][0][0]=0;
        for(int sta=0;sta<1<<q;++sta)
        for(int stt=0;stt<1<<q;++stt)
        for(int i=1;i<=50;++i)
        {
            int&now=dp[i][sta][stt];
            if(now==inf)continue;
            if(stt+1==(1<<q))ans=min(ans,now+dis[i][1]);
            for(int j=0;j<q;++j)if((stt&(1<<j))==0)
            {
                int&nex=dp[pla[j]][sta|tic[pla[j]]][stt^(1<<j)];
                int cos=pay[j][(sta&(1<<j))?1:0]+dis[i][pla[j]];
                nex=min(nex,cos+now);
            }
            for(int j=1;j<=n;++j)
            {
                int&nex=dp[j][sta|tic[j]][stt];
                nex=min(nex,dis[i][j]+now);
            }
        }printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
