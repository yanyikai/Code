#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100005
#define int long long
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
struct P{
    int a,b;
    bool operator<(const P&o)const{
        int s0=a<b,s1=o.a<o.b;
        if(s0!=s1)return s0<s1;
        return s0?a>o.a:b<o.b;
    }
    void U(P&o){
        int t=max(a,a+o.a-b);
        b=b-a+o.b-o.a+t,a=t;
    }
}a[N];
struct O{
    P x;int tim,id;
    bool operator<(const O&o)const{
        return x<o.x;
    }
};
int del[N],dfn[N],fat[N];
priority_queue<O>Q;
vector<int>fir[N];
void dfs(int u,int f){fat[u]=f;for(int v:fir[u])if(v!=f)dfs(v,u);}
int Fin(int x){return del[fat[x]]?fat[x]=Fin(fat[x]):fat[x];}
main()
{
    for(int cas=0,T=read();cas<T;++cas)
    {
        int n=read(),tim=0;
        for(int i=1;i<=n;++i)
            fir[i].clear(),del[i]=dfn[i]=0;
        a[1]=P{0,0};
        for(int i=2;i<=n;++i)
            Q.push(O{a[i]=P{read(),read()},0,i});
        for(int i=1,u,v;i<n;++i)
            u=read(),v=read(),
            fir[u].push_back(v),
            fir[v].push_back(u);
        dfs(1,0);
        for(;!Q.empty();)
        {
            O t=Q.top();Q.pop();int u=t.id;
            // printf("%d\n",u);
            if(del[u]||t.tim!=dfn[u])continue;
            del[u]=1;int v=Fin(u);a[v].U(a[u]);
            if(v!=1)Q.push(O{a[v],dfn[v]=++tim,v});
        }
        printf("%lld\n",a[1].a);
    }
    return 0;
}
