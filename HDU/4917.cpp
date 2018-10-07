#include<cstdio>
#include<vector>
using namespace std;
vector<int>fir[45];
int fat[45],siz[45],d[45],sta[45];
long long C[45][45],p=1e9+7,f[(1<<21)|5];
int Fin(int x){return fat[x]==x?x:fat[x]=Fin(fat[x]);}
int main()
{
    C[0][0]=1;
    for(int i=1;i<45;++i)
        for(int j=0;j<45;++j)
            C[i][j]=j?(C[i-1][j]+C[i-1][j-1])%p:1;
    for(int n,e;~scanf("%d%d",&n,&e);)
    {
        long long ans=1;
        for(int i=1;i<=n;++i)
            fir[i].clear(),fat[i]=i,siz[i]=1,d[i]=0;
        for(int i=0,u,v;i<e;++i)
        {
            scanf("%d%d",&u,&v);
            fir[u].push_back(v);
            ++d[v];u=Fin(u),v=Fin(v);
            if(u!=v)fat[u]=v,siz[v]+=siz[u];
        }
        for(int i=1;i<=n;++i)Fin(i);
        for(int sum=n,i=1;i<=n;++i)
            if(fat[i]==i)ans=ans*C[sum][siz[i]]%p,sum-=siz[i];
        for(int k=1;k<=n;++k)if(fat[k]==k)
        {
            int m=0;
            for(int i=1;i<=n;++i)if(fat[i]==k)sta[m++]=i;
            for(int i=0;i<1<<m;++i)f[i]=0;f[0]=1;
            for(int i=0;i<1<<m;++i)if(f[i])
            {
                for(int j=0;j<m;++j)if((1<<j)&i)for(int v:fir[sta[j]])--d[v];
                for(int j=0;j<m;++j)if(!((1<<j)&i)&&!d[sta[j]])(f[i|(1<<j)]+=f[i])%=p;
                for(int j=0;j<m;++j)if((1<<j)&i)for(int v:fir[sta[j]])++d[v];
            }
            ans=ans*f[(1<<m)-1]%p;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
