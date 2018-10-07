#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 35
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
struct P{int x,y;int operator<(const P&o)const{return x==o.x?y<o.y:x<o.x;};}p[N];
int vis[205][205];
inline int get(int a,int b,int c,int d)
{
    int ax=p[a].x,ay=p[a].y,bx=p[b].x,by=p[b].y,cx=p[c].x,cy=p[c].y,dx=p[d].x,dy=p[d].y;
    if(ax==bx||ay>=by||cx==dx||cy>=dy)return 0;
    if(!vis[ax][by]||!vis[bx][ay]||!vis[cx][dy]||!vis[dx][cy])return 0;
    if(bx<cx||ax>dx||by<cy||ay>dy)return (bx-ax)*(by-ay)+(dx-cx)*(dy-cy);
    if(ax<cx&&cx<bx&&ax<dx&&dx<bx&&ay<cy&&cy<by&&ay<dy&&dy<by)return (bx-ax)*(by-ay);
    return 0;
}
int main()
{
    for(int n;~scanf("%d",&n)&&n;)
    {
        memset(vis,0,sizeof vis);
        for(int i=0;i<n;++i)
        {
            int x=read(),y=read();
            p[i]=(P){x,y};
            ++vis[x][y];
        }sort(p,p+n);int ans=0;
        for(int sta=(1<<4)-1;sta<1<<n;)
        {
            int t[5];
            for(int i=0,tot=0;i<n;++i)if(sta&(1<<i))t[++tot]=i;
            ans=max(max(ans,get(t[1],t[2],t[3],t[4])),max(get(t[1],t[3],t[2],t[4]),get(t[1],t[4],t[2],t[3])));
            int x=sta&-sta,y=sta+x;
            sta=((sta&~y)/x>>1)|y;
        }ans?printf("%d\n",ans):puts("imp");
    }
    return 0;
}
