#include<bits/stdc++.h>
#define N 100005
using namespace std;
struct P{int u,v,col;}edge[N];
int T,n,m,i,fa[N],u,v,col,res1,res2,cnt;
int Fib[26]={1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393};
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int cmp(P a,P b){return a.col<b.col;}
int main()
{
    scanf("%d",&T);
    for(int cas=1;cas<=T;++cas)
    {
        res1=res2=cnt=0;
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;++i)
        {
            scanf("%d%d%d",&u,&v,&col);
            edge[i]=(P){u,v,col};
        }
        sort(edge+1,edge+m+1,cmp);
        for(i=1;i<=n;++i)
            fa[i]=i;
        for(i=1;i<=m;++i)
        {
            u=find(edge[i].u);
            v=find(edge[i].v);
            if(u!=v)
            {
                fa[u]=v;
                res1+=edge[i].col;
            }
        }
        for(i=1;i<=n;++i)
            fa[i]=i;
        for(i=m;i>=1;--i)
        {
            u=find(edge[i].u);
            v=find(edge[i].v);
            if(u!=v)
            {
                fa[u]=v;
                res2+=edge[i].col;
                ++cnt;
            }
        }
        if(cnt<n-1)
        {
            printf("Case #%d: No\n",cas);
            continue;
        }
//        printf("%d %d\n",res1,res2);
        printf("Case #%d: ",cas);puts(upper_bound(Fib,Fib+26,res2)-lower_bound(Fib,Fib+26,res1)>0?"Yes":"No");
    }
    return 0;
}
