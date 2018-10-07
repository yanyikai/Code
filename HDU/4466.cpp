#include<cstdio>
#define N 5000005
#define p 1000000007
using namespace std;
int P[N],f[N];
int main()
{
    *P=1;
    for(int i=1;i<N;++i)
    {
        f[i]=f[i-1]+(i-1)/2-i/3+!(i%3);
        if(!(i&1))f[i]-=i>>2;
        f[i]=(f[i]%p+p)%p;
        P[i]=P[i-1]*2%p;
    }
    for(int i=3;i<N;++i)
        for(int j=i+i;j<N;j+=i)
            f[j]=(f[j]-f[i]+p)%p;
    for(int n,cas=0;~scanf("%d",&n);)
    {
        long long ans=0;
        for(int i=1;i*i<=n;++i)
            if(!(n%i))
            {
                ans=(ans+1ll*f[i]*P[n/i-1])%p;
                if(i*i!=n)
                    ans=(ans+1ll*f[n/i]*P[i-1])%p;
            }
        printf("Case %d: %lld\n",++cas,ans);
    }
    return 0;
}
