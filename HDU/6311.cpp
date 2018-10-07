#include<bits/stdc++.h>
#define N 100005
#define M 500005
#define Me(_) memset(_,0,sizeof _)
using namespace std;
vector<int>key[N],ans[N];
int fir[N],e,arr[M],nex[M],rud[N],top,s[M],vis[M],fat[N],cnt;
int Fin(int u){return u==fat[u]?u:fat[u]=Fin(fat[u]);}
void ADD(int u,int v){nex[++e]=fir[u];fir[u]=e;arr[e]=v;}
void dfs(int u)
{
    for(int&v=fir[u];v;v=nex[v])
        if(!vis[v>>1])
        {
            int t=v;
            vis[v>>1]=1;dfs(arr[v]);
            s[++top]=(t&1?-(t>>1):t>>1);
        }
}
int main()
{
    for(int n,m;~scanf("%d%d",&n,&m);)
    {
        Me(fir);Me(rud);Me(vis);e=1;cnt=0;
        for(int i=1;i<=n;++i)
            key[i].clear(),ans[i].clear(),fat[i]=i;
        for(int i=0,u,v;i<m;++i)
            scanf("%d%d",&u,&v),ADD(u,v),ADD(v,u),++rud[u],++rud[v],fat[Fin(u)]=Fin(v);
        for(int i=1;i<=n;++i)
            if(rud[i]&1)
                key[Fin(i)].push_back(i);
        for(int i=1;i<=n;++i)
            if(fat[i]==i)
            {
                top=0;
                if(!key[i].size())
                {
                    dfs(i);++cnt;
                    for(;top;--top)
                        ans[cnt].push_back(s[top]);
                }
                else
                {
                    for(int j=0,l=key[i].size();j<l;j+=2)
                        ADD(key[i][j],key[i][j+1]),ADD(key[i][j+1],key[i][j]);
                    dfs(i);vector<int> pos;
                    for(int j=top;j;--j)
                        if(s[j]>m||s[j]<-m)
                            pos.push_back(j);
                    for(int j=0,l=pos.size()-1;j<l;++j)
                    {
                        ++cnt;
                        for(int k=pos[j]-1;k>pos[j+1];--k)
                            ans[cnt].push_back(s[k]);
                    }
                    ++cnt;
                    for(int j=pos[pos.size()-1]-1;j;--j)
                        ans[cnt].push_back(s[j]);
                    for(int j=top;j>pos[0];--j)
                        ans[cnt].push_back(s[j]);
                }
            }
        int t=cnt;
        for(int i=1;i<=cnt;++i)
            if(!ans[i].size())--t;
        cout<<t<<endl;
        for(int i=1;i<=cnt;++i)
            if(ans[i].size())
            {
                printf("%lu",ans[i].size());
                for(int j=0,l=ans[i].size();j<l;++j)
                    printf(" %d",ans[i][j]);
                puts("");
            }
    }
    return 0;
}
