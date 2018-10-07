#include<cmath>
#include<cstdio>
#include<cstring>
#define M(a) memset(a,0,sizeof a)
#define F(i) for(int i=0;i<n;++i)
#define N 1005
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
double x[N],y[N],val[N],use[N][N],vis[N];
int pre[N];
double dis[N][N],del[N][N],now[N];
inline double sqr(double x){return x*x;}
inline double max(double x,double y){return x>y?x:y;}
int main()
{
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        M(use);M(vis);M(del);M(dis);M(now);M(pre);
        double sum=0,ans=0;int n=read();
        F(i)x[i]=read(),y[i]=read(),val[i]=read();
        F(i)F(j)dis[i][j]=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
        F(i)now[i]=dis[0][i],pre[i]=0;vis[0]=1;now[0]=0;pre[0]=-1;
        for(int i=1;i<n;++i)
        {
            int pos=-1;double minn=2e9;
            F(j)
            if(!vis[j]&&now[j]<minn)
            {
                minn=now[j];
                pos=j;
            }
            sum+=minn;
            vis[pos]=1;
            use[pre[pos]][pos]=use[pos][pre[pos]]=1;
            F(j)
            {
                if(vis[j]&&j!=pos)
                    del[j][pos]=del[pos][j]=max(del[j][pre[pos]],now[pos]);
                if(!vis[j]&&now[j]>dis[pos][j])
                {
                    now[j]=dis[pos][j];
                    pre[j]=pos;
                }
            }
        }
        F(i)for(int j=i+1;j<n;++j)
        ans=max(ans,1.0*(val[i]+val[j])/(sum-(use[i][j]?dis[i][j]:del[i][j])));
        printf("%.2lf\n",ans);
    }
}
