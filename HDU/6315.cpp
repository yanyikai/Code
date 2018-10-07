#include<bits/stdc++.h>
#define lc o<<1
#define rc o<<1|1
#define ls l,mid,lc
#define rs mid+1,r,rc
#define mid ((l+r)>>1)
#define N 400005
using namespace std;
int sum[N],tag[N],mxn[N],val[N];
void PU(int o)
{
    sum[o]=sum[lc]+sum[rc];
    mxn[o]=min(mxn[lc],mxn[rc]);
}
void PD(int o)
{
    if(!tag[o])return ;
    tag[lc]+=tag[o];
    tag[rc]+=tag[o];
    mxn[lc]-=tag[o];
    mxn[rc]-=tag[o];
    tag[o]=0;
}
void build(int l,int r,int o)
{
    if(l==r)mxn[o]=val[l];else
    build(ls),build(rs),PU(o);
}
void Upd(int l,int r,int o,int L,int R)
{
    if(l==r)
    {
        --mxn[o];
        if(!mxn[o])mxn[o]=val[l],++sum[o];
        return ;
    }
    PD(o);
    if(L<=l&&r<=R)
    {
        if(mxn[o]==1)Upd(ls,L,R),Upd(rs,L,R);
        else{++tag[o],--mxn[o];return;};
    }else
    {
        if(L<=mid)Upd(ls,L,R);
        if(R> mid)Upd(rs,L,R);
    }
    PU(o);
}
int Fin(int l,int r,int o,int L,int R)
{
    if(L<=l&&r<=R)return sum[o];
    PD(o);int res=0;
    if(L<=mid)res+=Fin(ls,L,R);
    if(R> mid)res+=Fin(rs,L,R);
    PU(o);return res;
}
void put(int l,int r,int o)
{
    PD(o);printf("%d %d %d %d\n",l,r,mxn[o],sum[o]);
    if(l==r)return ;put(ls);put(rs);
}
int main()
{
    char s[15];
    for(int n,m;~scanf("%d%d",&n,&m);)
    {
        memset(sum,0,sizeof sum);
        memset(tag,0,sizeof tag);
        memset(mxn,0,sizeof mxn);
        memset(val,0,sizeof val);
        for(int i=1;i<=n;++i)scanf("%d",val+i);
        build(1,n,1);
        for(int i=0,l,r;i<m;++i)
        {
            scanf("%s%d%d",s,&l,&r);
            if(*s=='a')Upd(1,n,1,l,r);
            else printf("%d\n",Fin(1,n,1,l,r));
        }
    }
    return 0;
}
