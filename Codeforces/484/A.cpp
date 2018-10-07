#include<cstdio>
#define int long long
using namespace std;
signed main()
{
    int T;scanf("%lld",&T);
    for(int cas=0;cas<T;++cas)
    {
        int l,r;scanf("%lld%lld",&l,&r);
        int ans=l;
        for(int i=0;i<63;++i)
        {
            if((ans|(1ll<<i))>r)break;
            ans|=1ll<<i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}