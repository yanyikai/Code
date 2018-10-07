#include<cstdio>
#include<cstring>
using namespace std;
#define N 1100005
#define mid ((l+r)>>1)
int tot,son[N * 3][2],t[N * 3];
int T[55],x1,y1,y2,flg;

void Update(int l,int r,int&rt,int x,int y)
{
    if(!rt)rt=++tot,t[rt]=x;
    if(t[rt]>x)t[rt]=x;
    if(l==r)return ;
    y>mid?Update(mid + 1,r,son[rt][1],x,y):Update(l,mid,son[rt][0],x,y);
}
void Query(int l,int r,int rt)
{
    if(flg||!rt)return ;
    if(l>=y1&&r<=y2)
    {
        if(t[rt]<=x1)flg=1;
        return ;
    }
    if(y1<=mid)Query(l,mid,son[rt][0]);
    if(y2> mid)Query(mid+1,r,son[rt][1]);
}
int main()
{
    int ans,k,x,y,c;
    for(;~scanf("%d",&k)&&k-3;)
    {
        if(!k)
        {
            for(int i=1;i<=tot;i++)
                son[i][0]=son[i][1]=0;
            memset(T,0,sizeof T);tot=0;
        }else
        if(k==1)
        {
            scanf("%d%d%d",&x,&y,&c);
            Update(1,N,T[c],x,y);
        }else
        if(k==2)
        {
            scanf("%d%d%d",&x1,&y1,&y2);
            ans=0;
            for(int i=0;i<51;i++)
            {
                flg=0;
                Query(1,N,T[i]);
                ans+=flg;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
