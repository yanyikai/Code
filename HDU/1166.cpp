#include<cstdio>
#include<cstring>
#define lowbit(x) (x&-x)
int T,i,n,x,y,a[50005];
inline void Up(int i,int v){for(;i<=n;i+=lowbit(i))a[i]+=v;}
inline int Qu(int i){int sum=0;for(;i;i-=lowbit(i))sum+=a[i];return sum;}
char s[10];
int main()
{
    scanf("%d",&T);
    for(int cas=1;cas<=T;++cas)
    {
        memset(a,0,sizeof a);
        scanf("%d",&n);
        for(i=1;i<=n;++i)
        {
            scanf("%d",&x);
            Up(i,x);
        }printf("Case %d:\n",cas);
        for(;~scanf("%s",s)&&*s!='E';)
        {
            scanf("%d%d",&x,&y);
            if(*s=='Q') printf("%d\n",Qu(y)-Qu(x-1));
            else Up(x,*s=='A'?y:-y);
        }
    }
}
