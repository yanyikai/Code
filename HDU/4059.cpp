#include<cstdio>
#define p 1000000007ll
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
int fac[15],pri[6000],vis[100005],cnt;
inline int pow(int x){return x*x%p*x%p*x%p;}
inline int get(int x){return x*(x+1)%p*(2*x+1)%p*(3*x*x%p+3*x-1)%p*233333335%p;}
signed main()
{
    for(int i=2;i<10000;++i)
    {
        if(vis[i])continue;
        pri[++cnt]=i;
        for(int j=i+i;j<10000;j+=i)vis[j]=1;
    }
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        int n=read(),tot=0,ans=get(n),t=n;
        for(int i=1;i<=cnt&&pri[i]<=t;++i)if(t%pri[i]==0)
        for(fac[++tot]=pri[i];t%pri[i]==0;t/=pri[i]);
        if(t!=1)fac[++tot]=t;
//        for(int i=1;i<=tot;++i)printf("%lld ",fac[i]);puts("");
        for(int i=1;i<1<<tot;++i)
        {
            int mul=1,cnt=0;
            for(int t=i,j=1;t;t>>=1,++j)
            if(t&1)++cnt,mul*=fac[j];
            cnt&1?ans=(ans-pow(mul)*get(n/mul)%p+p)%p:ans=(ans+pow(mul)*get(n/mul)%p)%p;
        }printf("%lld\n",ans);
    }
    return 0;
}
