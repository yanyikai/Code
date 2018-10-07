#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 200005
using namespace std;
struct P{int u,v;long long w;int operator<(const P&o)const{return w>o.w;}}e[N];
int fat[N],siz[N];long long num[N],ans;
int fin(int x){return fat[x]==x?x:fat[x]=fin(fat[x]);}
int main()
{
    for(int n;~scanf("%d",&n);)
    {
        ans=0;
        for(int i=1;i<=n;++i)
            siz[i]=1,fat[i]=i,num[i]=0;
        for(int i=1;i<n;++i)
            scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
        sort(e+1,e+n);
        for(int i=1;i<n;++i)
        {
            int x=fin(e[i].u),y=fin(e[i].v);
            fat[y]=x;
            num[x]=max(num[x]+e[i].w*siz[y],num[y]+e[i].w*siz[x]);
            siz[x]+=siz[y];
        }for(int i=1;i<=n;++i)
            ans=max(ans,num[i]);
        printf("%lld\n",ans);
    }
    return 0;
}
