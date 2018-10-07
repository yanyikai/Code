#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
int f[30][2],num[30];
int dfs(int fir,int p,int sta)
{
    if(!p)return 1;
    if(!fir&&~f[p][sta])return f[p][sta];
    int res=0,up=fir?num[p]:9;
    for(int i=0;i<=up;++i)if(i!=9||!sta)
        res+=dfs(fir&&i==num[p],p-1,i==4);
    return fir?res:f[p][sta]=res;
}
int get(int x)
{
    int tot=0;
    for(;x;x/=10)num[++tot]=x%10;
    return dfs(1,tot,0);
}
signed main()
{
    memset(f,-1,sizeof f);
    int T;scanf("%lld",&T);
    for(int x;T--;)
    {
        scanf("%lld",&x);
        printf("%lld\n",x+1-get(x));
    }
    return 0;
}
