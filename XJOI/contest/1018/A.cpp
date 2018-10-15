#include<cmath>
#include<cstdio>
#include<algorithm>
#define N 2010
#define int long long
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int x[N],y[N],f[N];
int Fin(int u){return f[u]==u?u:f[u]=Fin(f[u]);}
double sqr(int t){return 1.0*t*t;}
double dis(int i,int j){return sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));}
void merge(int u,int v){if((u=Fin(u))!=(v=Fin(v)))f[u]=v;}
signed main()
{
    // freopen("AC.in","r",stdin);
    // freopen("AC.out","w",stdout);
    int _x=read(),_y=read(),n=read();
    for(int i=1;i<=n;++i)
        x[i]=read(),y[i]=read();
    x[n+1]=0;y[n+1]=0;x[n+2]=0;y[n+2]=_y;
    x[n+3]=_x;y[n+3]=0;x[n+4]=_x;y[n+4]=_y;
    double l=0,r=1e9;
    for(int i=1;i<=n;++i)
        r=min(r,min(dis(i,n+1),dis(i,n+4)));
    for(;abs(r-l)>1e-3;)
    {
        double d=(l+r)/2;int fg=0;
        for(int i=1;i<=n+4;++i)f[i]=i;
        for(int i=1;i<n;++i)
            for(int j=i+1;j<=n;++j)
                if(dis(i,j)<=2*d)
                    merge(i,j);
        for(int i=1;i<=n;++i)
        {
            if(x[i]<=d)merge(i,n+1);
            if(_x-x[i]<=d)merge(i,n+4);
            if(y[i]<=d)merge(i,n+2);
            if(_y-y[i]<=d)merge(i,n+3);
        }
        if(Fin(n+1)==Fin(n+4)||Fin(n+1)==Fin(n+2)||Fin(n+3)==Fin(n+4)||Fin(n+3)==Fin(n+2))fg=1;
        fg?r=d:l=d;
    }
    printf("%.2lf",l);
    return 0;
}