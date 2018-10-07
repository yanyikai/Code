#include<cstdio>
#include<cstring>
#define N 100005
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int fir[N],siz[N],dep[N],arr[N<<1],nex[N<<1],fat[N][32],n;
void dfs(int x,int fa)
{
    siz[x]=1;dep[x]=dep[fat[x][0]=fa]+1;
    for(int i=1;1<<i<=n;++i)
        fat[x][i]=fat[fat[x][i-1]][i-1];
    for(int i=fir[x];i;i=nex[i])
        if(arr[i]!=fa)
        {
            dfs(arr[i],x);
            siz[x]+=siz[arr[i]];
        }
}
inline int jump(int x,int len)
{
    for(int j=0;len;len>>=1,++j)
        if(len&1)x=fat[x][j];
    return x;
}
inline int lca(int a,int b)
{
    if(dep[a]<dep[b])a^=b,b^=a,a^=b;
    a=jump(a,dep[a]-dep[b]);
    if(a==b)return a;
    for(int i=31;~i;--i)
        if(fat[a][i]!=fat[b][i])
            a=fat[a][i],b=fat[b][i];
    return fat[a][0];
}
inline int mid(int a,int b,int ab)
{
    int len=dep[a]+dep[b]-(dep[ab]<<1);
    return dep[a]<dep[b]?jump(b,len>>1):jump(a,(len-1)>>1);
}
inline int get(int a,int b,int c,int ab,int ac)
{
    int mb=mid(a,b,ab),mc=mid(a,c,ac);
    if(dep[a]<dep[b]&&dep[a]<dep[c])
    {
        if(dep[mb]<dep[mc])mb^=mc,mc^=mb,mb^=mc;
        return lca(mb,mc)==mc?n-siz[mc]:n-siz[mb]-siz[mc];
    }
    if(dep[a]>=dep[b]&&dep[a]>=dep[c])
    {
        if(dep[mb]<dep[mc])mb^=mc,mc^=mb,mb^=mc;
        return lca(mb,mc)==mc?siz[mb]:0;
    }
    if(dep[a]<dep[b])mb^=mc,mc^=mb,mb^=mc;
    int t=lca(mb,mc);
    if(t==mc)return n-siz[mc];
    if(t==mb)return siz[mb]-siz[mc];
    return siz[mb];
}
int main()
{
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        memset(fir,0,sizeof fir);n=read();
        for(int i=1,e=0;i<n;++i)
        {
            int u=read(),v=read();
            arr[++e]=u;nex[e]=fir[v];fir[v]=e;
            arr[++e]=v;nex[e]=fir[u];fir[u]=e;
        }dfs(1,0);
        int m=read();
        for(int i=0;i<m;++i)
        {
            int a=read(),b=read(),c=read();
            int ab=lca(a,b),bc=lca(b,c),ac=lca(a,c);
            printf("%d %d %d\n",get(a,b,c,ab,ac),get(b,a,c,ab,bc),get(c,a,b,ac,bc));
        }
    }
    return 0;
}
