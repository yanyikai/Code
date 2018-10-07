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
int p=1e9+7;
int calc(int x)
{
    int res=1;
    for(;x;x>>=1)res+=x;
    return res;
}
int get(int n,int k)
{
    int res=1;
    for(int i=1;i<=k;i<<=1)
    {
        int t=k/i,tm;
        t&1?(tm=t,t=(t+1)>>1):(tm=t>>1,++t);
        res=(res+tm%p*(t%p)%p*(i%p)%p)%p;
    }
    return res+((n-calc(k))%p+p)%p*(k%p)%p;
}
main()
{
    for(int cas(0),T(read());cas<T;++cas)
    {
        int n(read()),l(n/2-1),r(n/2+61);
        if(n==1){puts("1");continue;}
        for(;l<=r;)
        {
            int mid=(l+r)>>1;
            calc(mid)<n?l=mid+1:r=mid-1;
        }
        // printf("!%lld %lld\n",l,calc(l));
        printf("%lld\n",get(n,l)%p);
    }
    return 0;
}
