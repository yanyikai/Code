#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000005
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
int a[N],t[N],dp[N];
int main()
{
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        int n=read(),l=read();
        for(int i=1;i<=n;++i)
            a[i]=read();
        printf("Case #%d: ",cas);
        memset(t,127,sizeof t);
        for(int i=n;i>l;--i)
        {
            int p=lower_bound(t,t+n,-a[i])-t;
            t[p]=-a[i];dp[i]=p+1;
        }memset(t,127,sizeof t);
//        for(int i=1;i<=n;++i)printf("%d ",dp[i]);puts("");
        int ans=0,res=0;
        for(int i=l+1;i<=n;++i)
        {
            ans=max(ans,dp[i]+int(lower_bound(t,t+n,a[i])-t));
            int p=lower_bound(t,t+n,a[i-l])-t;
            t[p]=a[i-l];res=max(res,p+1);
        }
        printf("%d\n",max(ans,res));
    }
    return 0;
}
