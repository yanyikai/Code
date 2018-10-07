#include<cstdio>
#define N 105
#define M 1505
#define F(_,o) for(int _=1;_<=o;++_)
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int a[N],w[N],g[N][N],id[N][N][N],sta[M][N],cot[M][N],f[N][M],p=1e9+7;
int gcd(int a,int b){for(;b;a^=b^=a^=b)a%=b;return a;}
int Pow(int x,int y){int res=1;for(;y;y>>=1,x=1ll*x*x%p)if(y&1)res=1ll*res*x%p;return res;}
int main()
{
    for(int cas=0,T=read();cas<T;++cas)
    {
        int n=read(),m=read(),cnt=0,ans=0,inv=Pow(m,p-2);
        F(i,n)a[i]=read();F(i,m)w[i]=read();
        F(i,m)F(j,m)g[i][j]=gcd(i,j);
        for(int i=1;i<=m;++i)
            for(int j=i;j<=m;j+=i)
                for(int k=j;k<=m;k+=j)
                    id[i][j][k]=++cnt;
        F(i,n)F(j,cnt)f[i][j]=0;
        for(int i=1;i<=m;++i)
            for(int j=i;j<=m;j+=i)
                for(int k=j;k<=m;k+=j)
                    for(int v=1,u=id[i][j][k];v<=m;++v)
                        sta[u][v]=id[g[j][v]][g[k][v]][v],
                        cot[u][v]=w[g[i][v]];
        F(i,m)F(j,m)F(k,m)
            if((!a[1]||a[1]==i)&&(!a[2]||a[2]==j)&&(!a[3]||a[3]==k))
                ++f[3][id[g[g[i][j]][k]][g[j][k]][k]];
        for(int i=3;i<n;++i)
            F(j,cnt)if(f[i][j])F(k,m)
                if(!a[i+1]||k==a[i+1])
                    (f[i+1][sta[j][k]]+=1ll*f[i][j]*cot[j][k]%p)%=p;
        F(i,cnt)(ans+=f[n][i])%=p;
        F(i,n)if(!a[i])ans=1ll*ans*inv%p;
        printf("%d\n",ans);
    }
    return 0;
}
