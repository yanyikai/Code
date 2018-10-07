#include<cstdio>
#define int long long
inline int read(){
    int x=0,f=0;
    register char ch=getchar();
    for(;ch<48||ch>57;ch=getchar())f|=ch=='-';
    for(;ch>47&&ch<58;ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
    return f?~x+1:x;
}
using namespace std;
signed main()
{
    for(int T=read(),cas=1;cas<=T;++cas)
    {
        int D=read()+1,l=read(),r=read();
        for(;;)
        {
            int x=__builtin_popcount(D);
//            printf("%lld %lld\n",D,x);
            if(x<l)
            {
                for(int i=0;;++i)
                {
                    if(D&(1<<i))continue;
                    D|=1<<i;
                    break;
                }
            }else
            if(x>r)D+=D&-D;else break;
        }
        printf("Case #%lld: %lld\n",cas,D);
    }
    return 0;
}
