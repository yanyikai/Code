#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
int num[10],f[10][2];
int dfs(int p,int fir,int sta)
{
    if(!p)return 1;
    if(!fir&&~f[p][sta])return f[p][sta];
    int res=0,up=fir?num[p]:9;
    for(int i=0;i<=up;++i)if(i!=4&&(i!=2||!sta))
        res+=dfs(p-1,fir&&i==num[p],i==6);
    return fir?res:f[p][sta]=res;
}
int get(int x)
{
    int tot=0;
    for(;x;x/=10)num[++tot]=x%10;
    return dfs(tot,1,0);
}
signed main()
{
    memset(f,-1,sizeof f);
    for(int l,r;~scanf("%lld%lld",&l,&r)&&l+r;)
        printf("%lld\n",get(r)-get(l-1));
    return 0;
}
