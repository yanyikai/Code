#include<cstdio>
#include<cstring>
#include<iostream>
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
int w[35][35],v[35],d[35];
int main()
{
    for(int n,m;~scanf("%d%d", &n, &m)&&n+m;)
    {
        memset(w,inf,sizeof w);
        for(int i=0;i<m;++i)
        {
            int x=read(),y=read(),t=read();
            w[x][y]=w[y][x]=min(t,w[x][y]);
        }
        int ans=0;
        for(int k=2;k<n;++k)
        {
            memset(v,0,sizeof v);
            memset(d,63,sizeof d);
            v[k]=1;d[1]=0;
            for(int i=1;i<=n;++i)
            {
                int x,m=inf;
                for(int j=1;j<=n;++j)
                    if(!v[j]&&d[j]<=m)
                        m=d[x=j];
                v[x]=1;
                for(int j=1;j<=n;++j)
                    d[j]=min(d[j],d[x]+w[x][j]);
            }
            ans=max(ans,d[n]);
        }
        ans==inf?puts("Inf"):printf("%d\n",ans);
    }
    return 0;
}
