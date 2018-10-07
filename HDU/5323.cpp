#include<cstdio>
#define int long long
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int ans;
void dfs(int l,int r)
{
    if(!l)
    {
        if(ans==-1||r<ans)ans=r;
        return ;
    }
    if(l*2<r+1)return ;
    dfs(l,2*r-l+1);
    if(l<r)dfs(l,2*r-l);
    dfs(2*l-r-1,r);
    dfs(2*l-r-2,r);
}
signed main()
{
    for(int l,r;~scanf("%lld%lld",&l,&r);)
    {
        ans=-1;dfs(l,r);
        printf("%lld\n",ans);
    }
    return 0;
}
