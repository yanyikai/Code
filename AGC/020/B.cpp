#include<cstdio>
#define P pair<int,int>
#define int long long
const int N=1e5+5,p=1e9+7;
inline int read(){
    int x=0;char ch=getchar();
    for(;ch<48||ch>57;ch=getchar());
    for(;ch>47&&ch<58;ch=getchar())
    x=(x<<1)+(x<<3)+(ch^48);return x;
}
using namespace std;
int a[N];
signed main()
{
    int n=read(),l=2,r=2;
    for(int i=n;i;--i)a[i]=read();
    for(int i=1;i<=n&&l<=r;++i)
    {
        // printf("!%lld %lld\n",l,r);
        // if(r<a[i]||l/a[i]==r/a[i])return puts("-1"),0;
        l=((l-1)/a[i]+1)*a[i];
        r=r/a[i]*a[i]+a[i]-1;
    }
    l>r?puts("-1"):printf("%lld %lld\n",l,r);
    return 0;
}