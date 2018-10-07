#include<cstdio>
#define F(_) for(int _=0;_<n;++_)
const int N=55,M=105,inf=1e9;
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int d[N][N],a[M][N][N],b[M][N][N],n,m,f[N][N];
void min(int&a,int b){if(a>b)a=b;}
void mul(int o[][N],int a[][N],int b[][N])
{
    static int t[N][N];
    F(i)F(j){
        t[i][j]=inf;
        F(k)min(t[i][j],a[i][k]+b[k][j]);
    }F(i)F(j)o[i][j]=t[i][j];
}
int main()
{
    for(int cas=0,T=read();cas<T;++cas)
    {
        n=read(),m=read();
        F(i)F(j)d[i][j]=inf;
        for(int i=0;i<m;++i)
        {
            int u=read()-1,v=read()-1,w=read();
            min(d[u][v],w);
        }
        F(i)F(j)a[0][i][j]=b[0][i][j]=i==j?0:inf;
        for(int i=1;i<M;++i)mul(a[i],a[i-1],d);
        for(int i=1;i<M;++i)mul(b[i],b[i-1],a[100]);
        F(i)d[i][i]=0;
        F(k)F(i)F(j)min(d[i][j],d[i][k]+d[k][j]);
        // for(int i=0;i<M;++i)mul(b[i],b[i],d);
        for(int e=0;e<M;++e)
        {
            F(i)F(j)f[i][j]=inf;
            F(i)F(j)F(k)min(f[i][j],b[e][i][k]+d[k][j]);
            F(i)F(j)b[e][i][j]=f[i][j];
        }
        for(int q=read();q--;)
        {
            int u=read()-1,v=read()-1,k=read();
            int A=k%100,B=k/100,res=inf;
            F(i)min(res,a[A][u][i]+b[B][i][v]);
            printf("%d\n",res<inf?res:-1);
        }
    }
    return 0;
}
