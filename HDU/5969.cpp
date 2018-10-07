#include<cstdio>
#define int long long
using namespace std;
signed main()
{
    int T;scanf("%lld",&T);
    for(int cas=0;cas<T;++cas)
    {
        int l,r,res=0;scanf("%lld%lld",&l,&r);
        l^=r;for(;l;l>>=1)++res;
        printf("%lld\n",r|((1ll<<res)-1));
    }
    return 0;
}
